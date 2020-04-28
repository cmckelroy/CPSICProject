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
	Schedule(vector<Appointment> apps);
	
	//This function prints this schedule.
	void print();
	//adds an appointment to the vector containing appointments
	void add(Appointment app);
	void remove_appointment(int appID);
};