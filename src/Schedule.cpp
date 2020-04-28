#include "Schedule.h"


Schedule::Schedule() {
}
Schedule::Schedule(vector<Appointment> apps) {
	appointments = apps;
}

void Schedule::print()
{
    for (unsigned int i = 0; i < appointments.size(); i++) {
        appointments[i].print_appointment();
    }
}
void Schedule::add(Appointment app) {
    appointments.push_back(app);
}

void Schedule::remove_appointment(int ID) {
	for (unsigned int i = 0; i < appointments.size(); i++) {
		if (appointments[i].get_id() == ID)
			appointments.erase(appointments.begin() + i);
	}
}
