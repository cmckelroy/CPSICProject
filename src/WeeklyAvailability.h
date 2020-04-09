#pragma once
#include "WeeklyTimeRange.h"
/*! \brief A WeeklyAvailability object represents all periods of time during an arbitrary during which a
 *   clinician is available to provide services by default.
 */
/*! Constraints: The periods of time represented should not overlap; if overlap occurs, the overlapping
 *				 WeeklyTimeRange objects should be merged.
 */
class WeeklyAvailability
{
private:
	WeeklyTimeRange wtr[];
public:
	/**
	This function prints a WeeklyAvailability object.

	@return 0
	*/
	void print();
};