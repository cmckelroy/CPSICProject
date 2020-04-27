#pragma once
#include <string>
#include "CPSICUser.h"
using namespace std;

/*! \brief This abstract class represents a to-be-implemented user interface for the CPSIC
  */
class CPSICUserInterface
{
public:
	/** @name Login session managing methods
	 */
	 ///@{

	/**
	This method adds an active session to the database if the login is successful (i. e. the username
	and password match up
	@return a unique session id to be set as a cookie in the user's browser
	*/
	virtual int login(string username, string password);

    /**
	This method removes an active session from the database.
	*/
	virtual void logout(int sessionID);

	/**
	This method returns the KSU ID corresponding to the user who owns a specific session.
	*/
	int retrieveSessionUserID(int sessionID);

	///@}

	/** @name Data retrieval methods
	*	
	*/
};
