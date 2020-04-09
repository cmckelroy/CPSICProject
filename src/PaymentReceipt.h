#pragma once
#include<string>
using namespace std;

/*! \brief Receipt for payment issued.
  *
  *  Constraint: Amount must be positive.
  */
class PaymentReceipt
{
	int TimeStamp;
	double Amount;
	string PaymentMethod;
private:
	/**
	This function prints the values of its three variables.

	@return 0
	*/
	void print();
};