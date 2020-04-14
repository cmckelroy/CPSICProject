#pragma once
#include <string>
#include <chrono>
using namespace std;

/*! \brief A BillableLineItem object is created when a student makes a visit to the KSU health facilities
 *  for coronavirus related concerns for which they will be charged.
 *  
 *  Records both services rendered and total cost.
 */
/*! Constraint: Total cost must be positive.
 */
class BillableLineItem
{
private:
	time_t timestamp;
	string descriptionOfServices;
	double totalCost;
	bool paid;
public:
	/**
	This function prints the values of its three variables.
	*/
	void print();
};