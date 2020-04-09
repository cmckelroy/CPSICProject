#pragma once
#include<string>
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
	string startDay;//a day of the week for the start
	int startHour;//an hour value between 0000 and 2400 for the start
	int startMinute;
	string endDay;//a day of the week for the end
	int endHour;//an hour value between 0000 and 2400 for the end
	string endMinute;
public:
	/**
	This function prints a weekly time range.

	@return 0
	*/
	void print();
	/**
	This function creates an AbsoluteTimeRange corresponding to this time range for a given week.

	@param relative_to timestamp of 12:00 AM on Sunday on that week.

	@return 0
	*/
	AbsoluteTimeRange to_absolute(int relative_to);
};
