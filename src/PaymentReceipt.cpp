#include "PaymentReceipt.h"
#include <iostream>
PaymentReceipt::PaymentReceipt(time_t time, double amount, string method) : timestamp(time), amount(amount), paymentMethod(method)
{
}

void PaymentReceipt::print()
{
	std::cout << "Amount: $" << amount;
	std::cout << "\nPaid at: " << time;
	std::cout << "\nPayment Method: " << paymentMethod << std::endl;
}

nlohmann::json PaymentReceipt::to_json()
{
	return {
		{"time", timestamp},
		{"amount", amount},
		{"paymentMethod", paymentMethod}
	};
}
