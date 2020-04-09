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
	*/
	void print();

	/**
	 * adds a WeeklyTimeRange object to the collection, checking for overlap in the process
	 */
	void add(WeeklyTimeRange wtr);

	/**
	 * removes the period of time represented by this range from the currently stored availability
	 */
	void remove(WeeklyTimeRange wtr);

};