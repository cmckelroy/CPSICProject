// ServerDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../src/PaymentReceipt.h"
#include "../libraries/httplib.h"


int main()
{
    std::cout << "Hello World!\n";
    time_t now = time(nullptr);
    PaymentReceipt asdf = PaymentReceipt(now, 35.01, "american express");
    nlohmann::json asdfj = asdf.to_json();
    std::cout << "Bill data: " + asdfj.dump() << "\n";

    httplib::Server svr;
    auto ret = svr.set_mount_point("/", "../html");
    if (!ret) {
        std::cout << "ERROR: ../html not found in file system, will not be mounted\n";
    }
    svr.Get("/bill", [asdfj](const httplib::Request& req, httplib::Response& res) {
        std::cout << "received request for bill\n";
        res.set_content(asdfj.dump(), "application/json");
    });
    svr.listen("0.0.0.0", 1111);
}
