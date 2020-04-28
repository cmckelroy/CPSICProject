#include "Clinician.h"

Clinician::Clinician(string name, string surname, int id, string pass, string title) : CPSICUser(name, surname, id, pass), jobTitle(title)
{
}

void reschedule_appointment(Appointment app, AbsoluteTimeRange newTimeslot) 
{
	app.set_timeslot(newTimeslot);
}

Schedule Clinician::view_schedule(time_t start, time_t end)
{
	return Schedule();
}
