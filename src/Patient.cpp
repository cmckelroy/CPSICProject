#include "Patient.h"

void Patient::make_payment(string paymentType, int paymentCardNumber, double amount)
{
}

void Patient::reschedule_appointment(Appointment app, AbsoluteTimeRange timeslot) {
	app.set_timeslot(timeslot);
}

void Patient::reschedule_with_new(Appointment app, AbsoluteTimeRange timeslot, Clinician newClinician) {
	app.set_timeslot(timeslot);
	app.set_clinician(newClinician);
}

Appointment Patient::create_appointment(Clinician clinician, AbsoluteTimeRange timeslot)
{
	return Appointment(*this, clinician, timeslot);
}

double Patient::get_balance()
{
	return 0.0;
}
