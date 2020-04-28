#include "CPSICUser.h"

CPSICUser::CPSICUser(string name, string surname, int id, string pass) : firstName(name), lastName(surname), KSUID(id), password(pass)
{
}
string CPSICUser::get_name() {
    return firstName + " " + lastName;
}
int CPSICUser::get_id() {
	return KSUID;
}
//Appointment& view_appointment(int appointmentID) { }
