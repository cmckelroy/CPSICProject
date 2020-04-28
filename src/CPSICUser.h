#pragma once
#include <string>
#include "Appointment.h"
using namespace std;

/*! \brief This class is the parent class of the Clinician, Patient, and Administrator classes.
 */
class CPSICUser {
protected:
	int KSUID;         ///<unique for each Clinician, Patient, and Administrator
	string password;
	string firstName;
	string lastName;
public:
	CPSICUser(string name, string surname, int id, string pass);
	string get_name();
	int get_id();
	//prints appointment information given an appointmentID and returns a reference to the appointment
	//Appointment & view_appointment(int appointmentID);
};