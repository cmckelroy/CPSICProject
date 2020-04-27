#pragma once
#include "CPSICUser.h"
#include "PaymentReceipt.h"
#include "AbsoluteTimeRange.h"
#include "BillableLineItem.h"
#include "Appointment.h"
#include "Clinician.h"
#include <vector>

/*! \brief A patient is a KSU student or staff member who has sought care from the medical department.
  *  
  *  This class is derived from the CPSICUser class.
  */
/*! Constraint: No two patients can share the same ID.
 */
class Patient : public CPSICUser
{
private:
	bool isStudent;
	bool isStaff;
	vector<std::string> healthRecords;
	vector<BillableLineItem> bill;
	vector<PaymentReceipt> receipts;
	bool hasShownFluSymptoms;
	bool isInfected;
	bool hasSoughtCounseling;
public:
	/**
	Allows the user to make a payment

	@param payment_type (i.e. credit card, PayPal, electronic check, etc.)

	@param payment_card_number This is the credit card number or echeck number.

	@param amount This is the amount the patient wants to pay towards their bill.

	*/
	void make_payment(std::string paymentType, int paymentCardNumber, double amount);

	/**
	This function creates an appointment for a specific clinician for a specific timeslot.
	@param clinician The clinician
	@param timeslot The timeslot
	*/

	Appointment create_appointment(Clinician clinician, AbsoluteTimeRange timeslot);

	/**
	This function determines the user's balance from their outstanding bills.
	*/

	double get_balance();
};