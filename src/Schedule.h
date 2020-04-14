#pragma once
#include "Appointment.h"
#include <vector>
/*! \brief A schedule object stores a set of appointments that are made by patients to address
 *   coronavirus concerns.
 */
class Schedule
{
private:
	std::vector<Appointment> appointments;
public:
	/**
	This function prints a clinician's schedule.

	@param clinician_name The name of the clinician whose schedule we want to print.

	*/
	void print(string clinician_name);
};