#pragma once
#include <string>
#include <chrono>
#include "AbsoluteTimeRange.h"
using namespace std;

enum weekday {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

/*! \brief This object represents a period of time within an arbitrary week.
  *
  *  This class can be used to produce an AbsoluteTimeRange object given a specific week of the year.
  */
 /*! Constraint: The start time must be earlier than the end time.
  */
class WeeklyTimeRange
{
private:
	weekday wkday;
	int startHour;  ///< an hour value between 0 and 23 for the start
	int startMinute;  ///< minute values can be 0-59
	int endHour;
	int endMinute;

public:
	WeeklyTimeRange(weekday wkday, int sh, int sm, int eh, int em);
	/**
	This function prints a weekly time range.

	*/
	void print();
	/**
	This function converts the relative information contained by this object into absolute terms

	@param relative_to timestamp of 12:00 AM on Sunday on that week.

	@return an AbsoluteTimeRange corresponding to this time range for a given week.
	*/
	AbsoluteTimeRange to_absolute(time_t relativeTo);
};
