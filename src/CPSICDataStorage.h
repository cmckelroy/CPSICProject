#pragma once
#include <string>
using namespace std;

/*! \brief This abstract class represents a to-be-implemented persistant data storage class for the CPSIC.
  */
class CPSICDataStorage
{
public:
	/**
	This method saves data in a persistant fashion. This function should be overloaded to accept any of our storable data types
	*/
	virtual void store();

    /**
	This method retrieves data from persistant storage. Different versions of this function should be created for each of
	our storable data types.
	*/
	virtual void retrieve();


};
