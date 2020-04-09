#pragma once
#include <string>
using namespace std;
#include "Appointment.h"

/*! \brief This class is the parent class of the Clinician, Patient,and Administrator classes.
 */
class CPSICUser {
protected:
	int KSU_ID;         //unique for each Clinitian, Patient, and Administrator
	string FirstName;
	string LastName;
public:
	/**
	This function creates an appointment

	@param absolute_time_range This is the half-hour timeslot that the appointment is scheduled for.

	@param date This is the appointment date.

	@param patient_ID This is the patient's KSU ID.

	@param clinician_ID This is the clinician's KSU ID.

	@return It returns the created appointment.

	*/
	Appointment create_appointment(AbsoluteTimeRange absolute_time_range, int date, string patient_ID, string clinician_ID);

	/**
	This function prints the appointment information.

	@param absolute_time_range This is the half-hour timeslot that the appointment is scheduled for.

	@param date This is the appointment date.

	@param patient_ID This is the patient's KSU ID.

	@param clinician_ID This is the clinician's KSU ID.

	*/
	void view_appointment(int absolute_time_range, int date, int patient_ID, int clinician_ID);

	/**
	This function prints coronavirus data for a given region.

	@param region The region is the geographical area that the user wishes to see coronavirus data about.

	*/
	void visualize_coronavirus_data(string region);
};