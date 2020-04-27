#include "Schedule.h"

void Schedule::print()
{
    for (int i = 0; i < appointments.size(); i++) {
        appointments[i].print_appointment();
    }
}
void Schedule::add_appointment(Appointment app) {
    appointments.push_back(app);
}
