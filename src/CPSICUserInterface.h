#pragma once
#include <string>
#include "CPSICUser.h"
#include "../libraries/httplib.h"
#include "../libraries/json.hpp"
using namespace std;

using CPSICRouteHandler = std::function<void(const httplib::Request & req, httplib::Response & res, string ssid)>;
using cookieDict = std::map<std::string, std::string>;

/*! \brief This abstract class represents a to-be-implemented user interface for the CPSIC
  */
class CPSICUserInterface
{
private:
	httplib::Server svr;
	map<string, string> loggedInUsers;
	map<string, string> testUserPasswords;
	map<string, nlohmann::json> testUserData;
	map<string, nlohmann::json> testAppointments;
	httplib::Server::Handler middleware(CPSICRouteHandler f);
public:

	void start();

	/** @name Login session managing methods
	 */
	 ///@{

	/**
	This method adds an active session to the database if the login is successful (i. e. the username
	and password match up
	@return a unique session id to be set as a cookie in the user's browser
	*/
	int login(string username, string password);

    /**
	This method removes an active session from the database.
	*/
	void logout(int sessionID);

	///@}
};
