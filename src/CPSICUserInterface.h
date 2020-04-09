#pragma once
#include<string>
using namespace std;

/*! \brief This abstract class represents a to-be-implemented user interface for the CPSIC
  */
class CPSICUserInterface
{
public:
	/**
	This function provides login functionality (implementation and mechanism TBD).

	@return 0
	*/
	virtual void login();
    /**
	This function provides logout functionality (implementation and mechanism TBD).

	@return 0
	*/
	virtual void logout();


};
