#pragma once
#include <string>
using namespace std;
#include "Appointment.h"

/*! \brief This class is the parent class of the Clinician, Patient,and Administrator classes.
 */
class CPSICUser {
protected:
	int KSUID;         //unique for each Clinician, Patient, and Administrator
	string firstName;
	string lastName;
public:
	/**
	This function creates an appointment

	@param absolute_time_range This is the half-hour timeslot that the appointment is scheduled for.

	@param date This is the appointment date.

	@param patient_ID This is the patient's KSU ID.

	@param clinician_ID This is the clinician's KSU ID.

	@return It returns the created appointment.

	*/
	Appointment create_appointment(AbsoluteTimeRange appointmentTime, int appointmentDate, string patientID, string clinicianID);

	/**
	This function prints the appointment information.

	@param absolute_time_range This is the half-hour timeslot that the appointment is scheduled for.

	@param date This is the appointment date.

	@param patient_ID This is the patient's KSU ID.

	@param clinician_ID This is the clinician's KSU ID.

	*/
	void view_appointment(int appointmentTime, int date, int patientID, int clinicianID);

	/**
	This function prints coronavirus data for a given region.

	@param region The region is the geographical area that the user wishes to see coronavirus data about.

	*/
	void visualize_coronavirus_data(string region);
};