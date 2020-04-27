#include "WeeklyTimeRange.h"
#include <iostream>

WeeklyTimeRange::WeeklyTimeRange(weekday sd, int sh, int sm, weekday ed, int eh, int em) : startDay(sd), startHour(sh), startMinute(sm), endDay(ed), endHour(eh), endMinute(em)
{
}

void WeeklyTimeRange::print()
{
	std::cout << "Start: " << startDay << " at " << startHour << ":" << startMinute << std::endl;
	std::cout << "End: " << endDay << " at " << endHour << ":" << endMinute << std::endl; 
}

AbsoluteTimeRange WeeklyTimeRange::to_absolute(time_t relativeTo)
{
	return AbsoluteTimeRange();
}
