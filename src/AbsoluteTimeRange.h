#pragma once
#include <chrono>
#include <iostream>
/*! \brief This object represents a period of time that can be specifically located and written into a
  *  calendar.
  *
  *  Contrast with WeeklyTimeRange, which stores a period of time within an arbitrary week.
  */
/*! Constraint: The start time must be earlier than the end time.
 */
class AbsoluteTimeRange
{
private:
	time_t startTime;   //timestamp
	time_t endTime;     //timestamp
public:
	/**
	This function simply prints this absolute time range.
	*/
	void print();

	/**
	This operator will check if two ATRs are equal or not
	*/
	bool operator ==(AbsoluteTimeRange& rhs);
};