#pragma once
#include <string>
using namespace std;

/*! \brief Receipt for payment issued.
  *
  *  Constraint: Amount must be positive.
  */
class PaymentReceipt
{
	private:
	
	int timestamp;
	double amount;
	string paymentMethod;

	public:
	/**
	This function prints the values of its three variables.
	*/
	void print();
};