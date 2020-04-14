#pragma once
#include <string>
#include "Schedule.h"
using namespace std;

/*! \brief A clinician object represents a specific general practitioner, nurse, or counselor employeed
 *   by KSU.
 *
 *  This class is derived from the CPSICUser class.
 */
/*! Constraints: Title must be "general practitioner", "counselor", "nurse", or other preaproved title.
*/
#include "CPSICUser.h"
class Clinician : public CPSICUser
{
private:
	string jobTitle;
public:
	/**
	This function allows a clinician to view their schedule.
	
	@param start This is the timestamp of the beginning of the schedule.

	@param end_date This is the timestamp of the end.

	*/
	Schedule view_schedule(time_t start, time_t end);
};