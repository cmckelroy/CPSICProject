#pragma once
#include<string>
using namespace std;

/*! \brief This abstract class represents a to-be-implemented persistant data storage class for the CPSIC.
  */
class CPSICDataStorage
{
public:
	/**
	This function saves data in a persistant fashion.

	@return 0
	*/
	virtual void store();
    /**
	This function retrieves data from persistant storage.

	@return 0
	*/
	virtual void retrieve();


};
