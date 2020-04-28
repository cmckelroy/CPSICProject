#include "Clinician.h"

void reschedule_appointment(Appointment app, AbsoluteTimeRange newTimeslot) {
	app.set_timeslot(newTimeslot);
}

Schedule Clinician::view_schedule(time_t start, time_t end)
{
	return Schedule();
}
