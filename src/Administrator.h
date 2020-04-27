#pragma once
#include "CPSICUser.h"
#include "BillableLineItem.h"
#include "PaymentReceipt.h"
#include <string>
#include <vector>


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
	std::string role;  ///< this could also be an enum containing one of a set of specific possible roles
public:
	/**
	This function allows an administrator to generate a campus alert by typing a message.

	@param message The administrator can create a unique message for each alert.

	@param url The message will often be the Kent State website, but unique messages can be created and sent to different websites.

	@param email_addresses This array stores the email addresses of all the email recipients of the message.

	*/
	void generate_campus_alert(std::string message, std::string url, vector<std::string> emailAddresses);
	Administrator();

	Administrator(std::string aRole);
	/**
	This function prints the desired income report. An administrator may view total income reports or
	individual income reports for counseling and medical attention.

	@param report_type The report_type refers to whether the the administrator wants a total income report,
	or a report of the income brought in just from counseling or just from medical

	*/
	vector<PaymentReceipt> create_income_report(int reportType);

	/**
	This function creates a bill, that consists of BillableLineItems.

	@param items This is an array of items/services that the patient is being charged for.

	@param is_student This variable tells us how much to charge the patient, because students and non-students are charged differently.

	*/
	void create_bill(vector<BillableLineItem> lineItems, bool isStudent);

};