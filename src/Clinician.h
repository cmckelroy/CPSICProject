#pragma once
#include <string>
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
	string title;
public:
	/**
	This function allows a clinician to view their schedule.
	
	@param start_date This is the first date in the range of dates that the clinician wants to see in the schedule.

	@param end_date This is the last date in the range of dates that the clinician wants to see in the schedle.

	*/
	void view_schedule(int start_date, int end_date);
};