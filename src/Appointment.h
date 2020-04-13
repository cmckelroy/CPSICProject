#pragma once
#include "AbsoluteTimeRange.h"
#include <string>
using namespace std;

/*! \brief An appointment object represents an appointment made by a patient to see a clinician.
 */
class Appointment
{
private:
	AbsoluteTimeRange time;//an object of the class AbsoluteTimeRange
	string patientFirstName;
	string patientLastName;
	string clinicianFirstName;
	string clinicianLastName;
public:
	/**
	This function prints an appointment.

	*/
	void print_appointment();
};