#include "Administrator.h"

void Administrator::generate_campus_alert(string message, string url, vector<string> emailAddresses)
{

}

vector<PaymentReceipt> Administrator::create_income_report(int reportType)
{
	return vector<PaymentReceipt>();
}

void Administrator::create_bill(vector<BillableLineItem> lineItems, bool isStudent)
{
}

Administrator::Administrator()
{
	role = "Ambiguous. Please set.";
}

Administrator::Administrator(std::string aRole)
{
	role = aRole;
}