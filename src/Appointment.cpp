#include "Appointment.h"

Appointment::Appointment(Patient &p, Clinician &c, AbsoluteTimeRange abs):clinician(c), patient(p), time(abs)
{
}

void Appointment::print_appointment()
{
}

void Appointment::cancel()
{
}
