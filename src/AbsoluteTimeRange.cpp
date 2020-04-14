#include "AbsoluteTimeRange.h"

void AbsoluteTimeRange::print()
{
}

bool AbsoluteTimeRange::operator==(AbsoluteTimeRange& rhs)
{
	return this->startTime==rhs.startTime && this->endTime == rhs.endTime;
}
