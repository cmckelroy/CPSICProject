#include "WeeklyTimeRange.h"
#include <iostream>

WeeklyTimeRange::WeeklyTimeRange(weekday wkday, int sh, int sm, int eh, int em) : wkday(wkday), startHour(sh), startMinute(sm), endHour(eh), endMinute(em)
{
}

void WeeklyTimeRange::print()
{
	std::cout << "Start: " << wkday << " at " << startHour << ":" << startMinute << std::endl;
	std::cout << "End: " << wkday << " at " << endHour << ":" << endMinute << std::endl; 
}

int detectIncrements(weekday wkday);

void increment(int& mon, int& day, int n);


AbsoluteTimeRange WeeklyTimeRange::to_absolute(time_t relativeTo)
{
	struct tm  * weekInfo = gmtime(&relativeTo);
	struct tm start;
	struct tm end;

	//for START---------------
	start.tm_year = weekInfo->tm_year;	//get year

	//get month and month day information
	int mon = weekInfo->tm_mon;
	int day = weekInfo->tm_mday;
	increment(mon, day, detectIncrements(wkday));
	start.tm_mon = mon;
	start.tm_mday = day;

	//get time information	
	start.tm_hour = startHour;
	start.tm_min = startMinute;
	start.tm_sec = 0;


	//for END---------
	end.tm_year = weekInfo->tm_year;
	
	//get month and month day information
	end.tm_mon = mon;
	end.tm_mday = day;
	
	//get time information
	end.tm_hour = endHour;
	end.tm_min = endMinute;
	end.tm_sec = 0;

	//CONVERT start and end (tm structs) into timestamps (time_t)--------
	time_t startStamp = mktime(&start);
	time_t endStamp = mktime(&end);

	return AbsoluteTimeRange(startStamp, endStamp);
}

//function to aid in conversion to absolute - detects how many days are needed to increment by from Sunday
int detectIncrements(weekday wkday) {
	switch(wkday) {
		case Sunday: return 0;
		case Monday: return 1;
		case Tuesday: return 2;
		case Wednesday: return 3;
		case Thursday: return 4;
		case Friday: return 5;
		case Saturday: return 6;
		default: return -1;	//should not happen
	}
}

//function to aid in conversion to absolute - increments a month, day pairing by one day
void increment(int &mon, int &day, int n) {
	int lastDayOfMonth;
	switch (mon) {
		case 1: lastDayOfMonth = 31; break;
		case 2: lastDayOfMonth = 28; break;
		case 3: lastDayOfMonth = 31; break;
		case 4: lastDayOfMonth = 30; break;
		case 5: lastDayOfMonth = 31; break;
		case 6: lastDayOfMonth = 30; break;
		case 7: 
		case 8: lastDayOfMonth = 31; break;
		case 9: lastDayOfMonth = 30; break;
		case 10: lastDayOfMonth = 31; break;
		case 11: lastDayOfMonth = 30; break;
		case 12: lastDayOfMonth = 31; break;
	}

	for (int i = 0; i < n; i++) {
		if (day == lastDayOfMonth) {
			mon += 1;
			day = 1;
		}
		else
			day += 1;
	}

	return;
}