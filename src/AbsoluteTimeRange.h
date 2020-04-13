#pragma once

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
	int startTime;   //timestamp
	int endTime;     //timestamp
public:
	/**
	This function simply prints an absolute time range.

	@param first_timestamp This is the timestamp that marks the beginning of the absolute time range.

	@param last_timestamp This is the timestamp that marks the end of the absolute time range.

	*/
	void print(int firstTimestamp, int lastTimestamp);
};