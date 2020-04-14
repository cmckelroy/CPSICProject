#pragma once
#include <string>
#include <chrono>
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
	string paymentMethod;

	public:
	/**
	This function prints the values of its three variables.
	*/
	void print();
};