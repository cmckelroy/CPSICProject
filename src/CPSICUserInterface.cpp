#include <iostream>
#include "CPSICUserInterface.h"

using namespace httplib;
using namespace nlohmann;

cookieDict readCookies(const Request& req) {
    std::string rawCookies = req.get_header_value("Cookie");
    cookieDict cookedCookies;
    std::string key = "";
    std::string value = "";
    // first we create the key string, then we hit an equals sign and start creating the value string
    bool creatingKey = true;
    // the plus one is so that the code will read and react to the null-terminator
    for (int i = 0; i < rawCookies.length() + 1; i++) {
        const char c = rawCookies[i];
        if (c == '=' && creatingKey) {
            creatingKey = false;
        }
        else if (c == ';' || c == '\0') {
            cookedCookies[key] = value;
            key = "";
            value = "";
            creatingKey = true;
        }
        else if (c != ' ') {
            if (creatingKey) {
                key += c;
            }
            else {
                value += c;
            }
        }
    }
    return cookedCookies;
}

void setCookies(cookieDict cookies, Response& res) {
    std::string cookieString = "";
    int counter = 0;
    for (auto cookie : cookies) {
        cookieString += cookie.first + "=" + cookie.second;
        ++counter;
        if (counter < cookies.size()) {
            cookieString += "; ";
        }
    }
    res.set_header("Set-Cookie", cookieString);
}

Server::Handler CPSICUserInterface::middleware(CPSICRouteHandler f) {
    return [f,this](const Request& req, Response& res) {
        cookieDict current = readCookies(req);
        if (current.count("CPSIC_SSID") > 0 && loggedInUsers.count(current["CPSIC_SSID"]) > 0) {
            f(req, res, current["CPSIC_SSID"]);
        } else {
            json error = { {"error", "not logged in"} };
            res.set_content(error.dump(), "application/json");
        }
    };
}


void CPSICUserInterface::start()
{
    Server svr;

    testUserPasswords["123456789"] = "password1";
    testUserPasswords["987654321"] = "password2";

    testUserData["123456789"] = {
                {"role", "patient"},
                {"name", "james james"}
            };
    testUserData["987654321"] = {
                {"role", "administrator"},
                {"name", "jone jones"}
            };

    testAppointments["123456789"] = {
        {{"patient", "james james"}, {"clinician", "tom geoffery"}, {"timeSlot", 1586338200000}},
        { {"patient", "james james"}, {"clinician", "tom jeffery"}, {"timeSlot", 1586943000000}}
    };

    svr.Post("/login", [=](const Request& req, Response& res) {

        json input = json::parse(req.body);

        if (testUserPasswords[input["username"]] == input["password"]){
            string ssid = to_string(time(nullptr));
            loggedInUsers[ssid] = input["username"];
            cookieDict loginCookies;
            loginCookies["CPSIC_SSID"] = ssid;
            setCookies(loginCookies, res);
            json result = { { "result", "success" } };
            res.set_content(result.dump(), "application/json");
        } else {
            json result = { {"result","failure"} };
            res.set_content(result.dump(), "application/json");
        }
    });

    svr.Get("/logout", middleware([this](const Request& req, Response& res, string ssid) {
        loggedInUsers.erase(ssid);
    }));

    svr.Get("/userinfo", middleware([this](const Request& req, Response& res, string ssid) {
        if (loggedInUsers.count(ssid) > 0) {
            string userid = loggedInUsers[ssid];
            json userData = testUserData[userid];
            res.set_content(userData.dump(), "application/json");
        }
    }));

    svr.Get("/appointments", middleware([this](const Request& req, Response& res, string ssid) {
        if (testAppointments.count(loggedInUsers[ssid]) > 0) {
            res.set_content(testAppointments[loggedInUsers[ssid]].dump(), "application/json");
        }
    }));

    auto ret = svr.set_mount_point("/", "./html");
    if (!ret) {
        std::cout << "ERROR: ./html not found, will not be mounted" << std::endl;
    }

    std::cout << "server launching at http://localhost:4321" << std::endl;
    svr.listen("0.0.0.0", 4321);
}

int CPSICUserInterface::login(string username, string password)
{
	return 0;
}
