#pragma once
#include "CPSICUser.h"
#include "BillableLineItem.h"
/*! \brief An administrator is someone who works for KSU and is allowed access to coronavirus related
 *   records.
 *
 *   May be required to approve clinician availability schedules.
 */
/*! Constraints: No two administrators can share the same ID. Role must be one from a pre-approved set
 *				 and determines what category of records the administrator can view.
 */
class Administrator : public CPSICUser
{
private:
	string Role;
public:
	/**
	This funciton allows an administrator to generate a campus alert by typing a message.

	@param message The administrator can create a unique message for each alert.

	@param url The message will often be the Kent State website, but unique messages can be created and sent to different websites.

	@param email_addresses This array stores the email addresses of all the email recipients of the message.


	*/
	void generate_campus_alert(string message, string url, string email_addresses[]);

	/**
	This function prints the desired income report. An administrator may view total income reports or
	individual income reports for counseling and medical attention.

	@param report_type The report_type refers to whether the the administrator wants a total income report,
	or a report of the income brought in just from counseling or just from medical


	*/
	void display_income_report(int report_type);

	/**
	This function prints a clinician's schedule.

	@param name The name of the physician or psychiatrist whose schedule the administrator wishes to view.

	@param start_date This is the first date in the range of dates that the administrator wants to view.

	@param end_date This is the last date in the range of dates that the administrator wants to view.

	*/
	void view_schedule(string name, int start_date, int end_date);

	/**
	This function cancels an appointment.

	@param date The date of the appointment

	@param absolute_time_range This is the 30-minute time slot between 10:00 and 4:00 that the appointment was scheduled for.

	@param clinician_ID This is the KSU flashline ID for the clinician.


	*/
	void cancel_appointment(int date, AbsoluteTimeRange absolute_time_range, int clinician_ID);

	/**
	This function automatically cancels a previous appointment, and schedules a new appointment.

	@param new_appointment_date This is the date we want the new appointment to be at.

	@param time This is the timeslot from 10:00 to 4:00 when we want the new appointment to be.

	@param patient_ID This is the patient's KSU Flashline ID.

	@param clinician_ID This is the clinician's KSU Flashline ID.

	@return Appointment;

	*/
	Appointment reschedule_appointment(int new_appointment_date, AbsoluteTimeRange time, int patient_ID, int clinician_ID);

	/**
	This function creates a bill, that consists of BillableLineItems.

	@param items This is an array of items/services that the patient is being charged for.

	@param is_student This variable tells us how much to charge the patient, because students and non-students are charged differently.

	*/
	void create_bill(BillableLineItem items[], bool is_student);
};