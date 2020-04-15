// ServerDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../src/PaymentReceipt.h"
#include "../libraries/httplib.h"


int main()
{
    std::cout << "Hello World!\n";

    // Create sample payment receipt:
    time_t now = time(nullptr);  // get current time
    PaymentReceipt sampleReciept = PaymentReceipt(now, 35.01, "american express");
    nlohmann::json sampleRecieptJSON = sampleReciept.to_json();
    std::cout << "Serialized reciept data: " + sampleRecieptJSON.dump() << "\n";

    // Set up sever
    httplib::Server svr;
    // Tell server to automatically serve the files at "../html"
    auto ret = svr.set_mount_point("/", "../html");
    if (!ret) {
        std::cout << "ERROR: ../html not found in file system, will not be mounted\n";
    }

    // Tell server to respond to requests for the /bill url with the JSON data of our sample bill
    svr.Get("/reciept", [sampleRecieptJSON](const httplib::Request& req, httplib::Response& res) {
        std::cout << "received request for reciept\n";
        res.set_content(sampleRecieptJSON.dump(), "application/json");
    });

    // Start server; tell it to listen for any connection on port 1111 (http://localhost:1111 should work locally)
    svr.listen("0.0.0.0", 1111);
}
