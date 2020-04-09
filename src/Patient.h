#pragma once
#include "CPSICUser.h"
#include "AbsoluteTimeRange.h"
//#include "PaymentReceipt.h"

/*! \brief A patient is a KSU student or staff member who has sought care from the medical department.
  *  
  *  This class is derived from the CPSICUser class.
  */
/*! Constraint: No two patients can share the same ID.
 */
class Patient : public CPSICUser
{
private:
	bool IsStudent;
	bool IsStaff;
	string Health_records;
	int Bill;//Should this be made a class?
	//PaymentRepeipt receipt;//object of class PaymentRepeipt
	bool HasShownFluSymptoms;
	bool IsInfected;
	bool HasSoughtCounseling;
public:
	/**
	Allows the user to make a payment

	@param payment_type (i.e. credit card, PayPal, electronic check, etc.)

	@param payment_card_number This is the credit card number or echeck number.

	@param amount This is the amount the patient wants to pay towards their bill.

	*/
	void make_payment(string payment_type, int payment_card_number, int amount);

	/**
	This function cancels an appointment. It doesn't require a clinician_ID like the cancel_appointment() function
	in the administrator class because a patient can not have two appointments with two different clinicians at
	the same time.

	@param date The date of the appointment

	@param absolute_time_range This is the 30-minute time slot between 10:00 and 4:00 that the appointment was scheduled for.


	*/
	void cancel_appointment(int date, AbsoluteTimeRange absolute_time_range);

	/**
	This function cancels an appointment and creates a new one.

	@param new_appointment_date This is the date of the new appointment the patient is trying to create.

	@param time This is the 30-minute time slot from 10:00 to 4:00 when the appointment will be held.

	*/
	void reschedule_appointment(int new_appointment_date, AbsoluteTimeRange time);
};