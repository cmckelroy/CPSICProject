#include "Appointment.h"
#include "AbsoluteTimeRange.h"
#include "Patient.h"
#include "Clinician.h"
#include <chrono>
#include <ctime>
#include <iostream>
Appointment::Appointment(Patient p, Clinician c, AbsoluteTimeRange abs): clinicianID(c.get_id()), patientID(p.get_id()), time(abs), appointmentID(std::chrono::seconds(std::time(NULL)).count())
{
}

void Appointment::print_appointment()
{
	std::cout << "Patient: " << patientID	//this could be changed to patient name (and clinican name) when we have a method for getting patient/clinican from stored ID
		<< "\nClinician: " << clinicianID << std::endl
		<< "On: ";
    //prints date and start time of appointment
    timestamp_date(time.get_start());
    std::cout << std::endl
    //prints appointment ID
        << "Appointment ID: " << appointmentID << std::endl;
}

void Appointment::timestamp_date(time_t timestamp) 
{
    string localTime(asctime(localtime(&timestamp))); //note:asctime should probably be changed to asctime_s
    //converts timestamp to a string containing the local time
    //example of what localTime would contain: "Tue May 26 21:51:50 2015"

    //elicit desired information from localTime string
    string date = localTime.substr(0, 10);      //date
    int hour = stoi(localTime.substr(11, 2));   //hour of day
    int min = stoi(localTime.substr(14, 2));    //minute of day
    string year = localTime.substr(20, 4);      //year

    //turn time of day into hour of day (less specific, non-military)
    string ext; //contains A.M. or P.M.
    if (hour < 12) {
        ext = "A.M.";
    }
    else {
        ext = "P.M.";

        if (hour != 12)
            hour = hour - 12;
    }

    //print in desired format
    std::cout << date << " at " << hour << ":" << min << " " << ext << ", " << year;
    return;
}

int Appointment::get_id() {
    return appointmentID;
}
int Appointment::get_patientID() {
	return patientID;
}
int Appointment::get_clinicianID() {
    return clinicianID;
}
AbsoluteTimeRange Appointment::get_timeslot() {
    return time;
}

void Appointment::set_timeslot(AbsoluteTimeRange newTimeslot) {
	time = newTimeslot;
}
void Appointment::set_clinician(Clinician newClinician) {
	clinicianID = newClinician.get_id();
}