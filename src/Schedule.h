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
	Schedule();
	/**
	This function prints this schedule.
	
	*/
	void print();
	void add_appointment(Appointment app);
	void remove_appointment();
};