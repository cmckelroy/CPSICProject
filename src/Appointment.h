#pragma once
#include "AbsoluteTimeRange.h"
// we need forward declaration here because Patient and Clinician #include Appointment, so if we #include
// Patient and Clinician here, we would end up with a circular dependency, which would be bad
class Patient;
class Clinician;
#include <string>
using namespace std;

/*! \brief An appointment object represents an appointment made by a patient to see a clinician.
 */
class Appointment
{
private:
	int appointmentID; ///< primary key of the appointment in the database
	AbsoluteTimeRange time;
	int patientID;
	int clinicianID;

	/**
	This function prints a timestamp as a date
	in the form "[WEEKDAY] [MONTH] [DAY], [YEAR] at [TIME] A.M./P.M."
	*/
	void timestamp_date(time_t timestamp);

public:
	Appointment(Patient p, Clinician c, AbsoluteTimeRange abs);

	/**
	This function prints an appointment.

	*/
	void print_appointment();


	//accessor functions

	//accessor function for appointmentID
	int get_id();
	//accessor function for reference to patient
	int get_patientID();
	//accessor function for reference to clinician
	int get_clinicianID();
	//accessor function for time
	AbsoluteTimeRange get_timeslot();

	void set_timeslot(AbsoluteTimeRange newTimeslot);
	void set_clinician(Clinician newClinician);
};