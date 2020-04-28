#pragma once
#include <string>
#include <chrono>
#include "../libraries/json.hpp"
using namespace std;

/*! \brief Receipt for payment issued.
  *
  *  Constraint: Amount must be positive.
  */
class PaymentReceipt
{
	private:
	
	time_t timestamp;
	double amount;
	std::string paymentMethod;

	public:
		PaymentReceipt(time_t time, double amount, std::string method);
		/**
		This function prints the values of its three variables.
		*/
		void print();
		/**
		This function outputs the object's value in serializable, transmittable form.
		*/
		nlohmann::json to_json();
};