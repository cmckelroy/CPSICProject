#include "PaymentReceipt.h"

PaymentReceipt::PaymentReceipt(time_t time, double amount, string method) : timestamp(time), amount(amount), paymentMethod(method)
{
}

void PaymentReceipt::print()
{
}

nlohmann::json PaymentReceipt::to_json()
{
	return {
		{"time", timestamp},
		{"amount", amount},
		{"paymentMethod", paymentMethod}
	};
}
