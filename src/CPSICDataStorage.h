#pragma once
#include <string>
#include "mysql.h"
#include <mysqlx/xdevapi.h>
#include <iostream>
#include <cstdio>
#include <chrono>
#include <ctime>
#include "Patient.h"
#include "Administrator.h"
#include "Clinician.h"
#include "Zone.h"

using namespace std;
using namespace ::mysqlx;

/*! \brief This abstract class represents a to-be-implemented persistant data storage class for the CPSIC.
  */
class CPSICDataStorage
{
public:
	/** @name Information retrieval methods
	*/
	///@{

	virtual Patient retrieve_user_as_patient(int KSUID);
	virtual Clinician retrieve_user_as_clinician(int KSUID);
	virtual Administrator retrieve_user_as_administrator(int KSUID);

	/**
	Creates a new active session for a user that just logged in with a particular KSU ID.
	*/
	virtual int create_new_session(int KSUID);

	/**
	Retrieves the KSU ID of the user who created a specific session
	*/
	virtual int retrieve_ksuid_for_session(int sessionID);

	/**
	Retrieves all appointments that involve a user with a specific KSU ID, whether they're the clinician
	in the appointment or the patient.
	*/
	virtual Schedule retrieve_schedule(int KSUID);

	/**
	Retrieves all appointments that fall into a certain time range (for administrative purposes; this is
	not meant to become public information
	*/
	virtual Schedule retrieve_schedule(AbsoluteTimeRange abs);

	/**
	Retrieves the single zone that has no "parent" zone and to which all others can trace a path to through parents
	*/
	virtual Zone retrieve_largest_zone();

	/**
	Retrieves a zone based on its name (which is its primary key)
	*/
	virtual Zone retrieve_zone(std::string name);

	///@}

	/** @name Information saving/updating methods
	*/
	///@{

	/**
	Uses the appointment object to create a matching record in the database
	*/
	virtual void saveAppointment(Appointment a);
	/**
	Deletes an appointment from the database (i imagine this will just use the appointmentID primary key attribute)
	*/
	virtual void deleteAppointment(int appID);

	/**
	Updates the details of a patient in the database by changing whether they've been diagnosed or whether they've sought
	treatment for certain reasons or what their health records are. (This shouldn't be allowed to change the KSU ID)
	*/
	virtual void updatePatient(Patient p);
	/**
	Updates a clinician's details. (I imagine this will mostly be used to change availability)
	*/
	virtual void updateClinician(Clinician c);

	/**
	Creates a record in the database for a PaymentReciept object
	*/
	virtual void savePayment(PaymentReceipt pr);

	///@}


};
