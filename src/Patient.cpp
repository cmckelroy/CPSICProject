#include "Patient.h"

void Patient::make_payment(string paymentType, int paymentCardNumber, double amount)
{
}

Appointment Patient::create_appointment(Clinician clinician, AbsoluteTimeRange timeslot)
{
	return Appointment(*this, clinician, timeslot);
}

double Patient::get_balance()
{
	return 0.0;
}
