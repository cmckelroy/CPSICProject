#pragma once
#include "AbsoluteTimeRange.h"
// we need forward declaration here because Patient and Clinician #include Appointment, so if we #include
// Patient and Clinician here, we would end up with a circular dependency, which would be bad
class Patient;
class Clinician;
#include <string>
using namespace std;

/*! \brief An appointment object represents an appointment made by a patient to see a clinician.
 */
class Appointment
{
private:
	AbsoluteTimeRange time;//an object of the class AbsoluteTimeRange
	Patient &patient;
	Clinician &clinician;
public:
	Appointment(Patient &p, Clinician &c, AbsoluteTimeRange abs);

	/**
	This function prints an appointment.

	*/
	void print_appointment();

	/**
	This function cancels the appointment.
	*/
	void cancel();
};