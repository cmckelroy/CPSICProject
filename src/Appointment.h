#pragma once
#include "AbsoluteTimeRange.h"
#include<string>
using namespace std;

/*! \brief An appointment object represents an appointment made by a patient to see a clinician.
 */
class Appointment
{
private:
	AbsoluteTimeRange Abs_time_range;//an object of the class AbsoluteTimeRange
	string PatientFirstName;
	string PatientLastName;
	string ClinicianFirstName;
	string ClinicianLastName;
public:
	/**
	This function prints an appointment.

	*/
	void print_appointment();
};