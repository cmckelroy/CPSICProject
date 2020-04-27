#include "AbsoluteTimeRange.h"
#include <iostream>

AbsoluteTimeRange::AbsoluteTimeRange(time_t s, time_t e) : startTime(s), endTime(e)
{
}

void AbsoluteTimeRange::print()
{
	std::cout << "Range: " << startTime << " - " << endTime;
}

bool AbsoluteTimeRange::operator==(AbsoluteTimeRange& rhs)
{
	return this->startTime==rhs.startTime && this->endTime == rhs.endTime;
}

time_t AbsoluteTimeRange::get_start()
{
	return startTime;
}
time_t AbsoluteTimeRange::get_end()
{
	return endTime;
}

void AbsoluteTimeRange::set_new(time_t s, time_t e) {
	startTime = s;
	endTime = e;
}
