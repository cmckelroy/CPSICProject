#pragma once
#include <string>
#include "AbsoluteTimeRange.h"
using namespace std;

/*! \brief This object represents a period of time within an arbitrary week.
  *
  *  This class can be used to produce an AbsoluteTimeRange object given a specific week of the year.
  */
 /*! Constraint: The start time must be earlier than the end time.
  */
class WeeklyTimeRange
{
private:
	int startDay;       // 0 = Sunday, 6 = Saturday
	int startHour;      // an hour value between 0 and 23 for the start
	int startMinute;    // minute values can be 0-59
	int endDay;         // ditto
	int endHour;        // ditto
	int endDay;         // ditto
public:
	/**
	This function prints a weekly time range.

	*/
	void print();
	/**
	This function converts the relative information contained by this object into absolute terms

	@param relative_to timestamp of 12:00 AM on Sunday on that week.

	@return an AbsoluteTimeRange corresponding to this time range for a given week.
	*/
	AbsoluteTimeRange to_absolute(int relativeTo);
};
