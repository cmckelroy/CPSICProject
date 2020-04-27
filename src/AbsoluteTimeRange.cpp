#include "AbsoluteTimeRange.h"

void AbsoluteTimeRange::print()
{
	std::cout << "Start time: " << startTime << std::endl;
	std::cout << "End time:   " << endTime << std::endl;
}

bool AbsoluteTimeRange::operator==(AbsoluteTimeRange& rhs)
{
	return this->startTime==rhs.startTime && this->endTime == rhs.endTime;
}
