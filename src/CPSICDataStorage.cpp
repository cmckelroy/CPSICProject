#include "CPSICDataStorage.h"

Patient CPSICDataStorage::retrieve_user_as_patient(int KSUID)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table u = db.getTable("user");
	RowResult aResult = u.select("KSU_ID", "FirstName", "LastName", "PatientID").where("KSU_ID like :id").bind("id", KSUID).execute();

	Row row = aResult.fetchOne();

	int foreign = row[3];

	Table p = db.getTable("patient");
	RowResult myResult = p.select("PatientID", "IsSymptomatic", "HasCoronavirus", "HasSoughtCounseling", "HealthRecords").where("PatientID like :is").bind("is", foreign).execute();

	Row arg = myResult.fetchOne();

	cout << "1 = yes, 0 = no" << endl;
	cout << "First name:            " << row[1] << endl;
	cout << "Last name:             " << row[2] << endl;
	cout << "Has symptoms           " << arg[1] << endl;
	cout << "Has Coronavirus:       " << arg[2] << endl;
	cout << "Has sought counseling: " << arg[3] << endl;
	cout << "Health records:        " << arg[4] << endl;
}

Clinician CPSICDataStorage::retrieve_user_as_clinician(int KSUID)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table u = db.getTable("user");
	RowResult aResult = u.select("KSU_ID", "FirstName", "LastName", "ClinicianID").where("KSU_ID like :id").bind("id", KSUID).execute();

	Row row = aResult.fetchOne();

	int foreign = row[3];

	Table c = db.getTable("clinician");
	RowResult myResult = c.select("ClinicianID", "JobTitle").where("ClinicianID like :is").bind("is", foreign).execute();

	Row arg = myResult.fetchOne();

	cout << "First name: " << row[1] << endl;
	cout << "Last name:  " << row[2] << endl;
	cout << "Job title:  " << arg[1] << endl;
}

Administrator CPSICDataStorage::retrieve_user_as_administrator(int KSUID)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table u = db.getTable("user");
	RowResult aResult = u.select("KSU_ID", "FirstName", "LastName", "AdminID").where("KSU_ID like :id").bind("id", KSUID).execute();

	Row row = aResult.fetchOne();

	int foreign = row[3];

	Table a = db.getTable("administrator");
	RowResult myResult = a.select("AdminID", "Role").where("AdminID like :is").bind("is", foreign).execute();

	Row arg = myResult.fetchOne();

	cout << "First name: " << row[1] << endl;
	cout << "Last name:  " << row[2] << endl;
	cout << "Role:       " << arg[1] << endl;
}

int CPSICDataStorage::create_new_session(int KSUID)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table as = db.getTable("activesessions");
	as.insert("ExpirationTime", "KSU_ID").values(std::chrono::system_clock::now(), KSUID).execute();
}

int CPSICDataStorage::retrieve_ksuid_for_session(int sessionID)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table as = db.getTable("activesessions");
	RowResult aResult = as.select("KSU_ID").where("SessionID like :id").bind("id", sessionID).execute();

	Row row = aResult.fetchOne();
	cout << "KSU ID for session " << sessionID << ": " << row[0] << endl;
}

Schedule CPSICDataStorage::retrieve_schedule(int KSUID)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table u = db.getTable("user");
	RowResult aResult = u.select("KSU_ID", "ClinicianID").where("KSU_ID like :id").bind("id", KSUID).execute();

	Row row = aResult.fetchOne();
	int foreign = row[1];

	Table av = db.getTable("weeklyavailability");
	RowResult myResult = av.select("ClinicianID", "StartTime", "EndTime", "DayoftheWeek").where("ClinicianID like :is").bind("is", foreign).execute();
}

Schedule CPSICDataStorage::retrieve_schedule(AbsoluteTimeRange abs)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");
}

Zone CPSICDataStorage::retrieve_largest_zone()
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table z = db.getTable("zone");
	RowResult aResult = z.select("ZoneName" , "NumOfCases", "WillRaiseAlert", "ParentZone").where("ParentZone = null").execute();

	Row row = aResult.fetchOne();
	cout << "Largest zone:                       " << row[0] << endl;
	cout << "Number of cases:                    " << row[1] << endl;
	cout << "Will raise alert (1 = yes, 0 = no): " << row[2] << endl;
}

Zone CPSICDataStorage::retrieve_zone(std::string name)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table z = db.getTable("zone");
	RowResult aResult = z.select("ZoneName", "NumOfCases", "WillRaiseAlert", "ParentZone").where("ZoneName like :zone").bind("zone", name).execute();

	Row row = aResult.fetchOne();
	cout << "Zone name:                          " << row[0] << endl;
	cout << "Number of cases:                    " << row[1] << endl;
	cout << "Will raise alert (1 = yes, 0 = no): " << row[2] << endl;
	cout << "Parent zone:                        " << row[3] << endl;
}

void CPSICDataStorage::saveAppointment(Appointment a)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");
}

void CPSICDataStorage::deleteAppointment(int appID)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table ap = db.getTable("appointment");

}

void CPSICDataStorage::updatePatient(Patient p)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table up = db.getTable("patient");
}

void CPSICDataStorage::updateClinician(Clinician c)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table uc = db.getTable("clinician");
}

void CPSICDataStorage::savePayment(PaymentReceipt pr)
{
	Session sess("localhost", 33060, "root", "t2]%j!muWbNb[d`a");

	Schema db = sess.getSchema("cpsic");

	Table sp = db.getTable("paymentreceipt");
}