#pragma once
#include "Appointment.h"
/*! \brief A schedule object stores a set of appointments that are made by patients to address
 *   coronavirus concerns.
 */
class Schedule
{
private:
	Appointment schedule[];//an array of appointment objects
public:
	/**
	This function prints a clinician's schedule.

	@param clinician_name The name of the clinician whose schedule we want to print.

	*/
	void print(string clinician_name);
};