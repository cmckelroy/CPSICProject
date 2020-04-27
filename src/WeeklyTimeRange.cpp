#include "WeeklyTimeRange.h"

void WeeklyTimeRange::print()
{
}

AbsoluteTimeRange WeeklyTimeRange::to_absolute(time_t relativeTo)
{
	return AbsoluteTimeRange(0,0);
}
