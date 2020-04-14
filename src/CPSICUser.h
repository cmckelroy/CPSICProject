#pragma once
#include <string>
using namespace std;

/*! \brief This class is the parent class of the Clinician, Patient, and Administrator classes.
 */
class CPSICUser {
protected:
	int KSUID;         ///<unique for each Clinician, Patient, and Administrator
	string firstName;
	string lastName;
public:
	CPSICUser();
};