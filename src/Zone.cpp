#include "Zone.h"
Zone::Zone(string name, Zone * parent, bool gca) : name(name), parentZone(parent), numOfCases(0), generatesCampusAlert(gca)
{
}

Zone::Zone(string name, Zone* parent, int cases, bool gca) : name(name), parentZone(parent), numOfCases(cases), generatesCampusAlert(gca)
{
}

int Zone::retrieve_num_of_cases()
{
	return numOfCases;
}

bool Zone::should_alert() {
	return generatesCampusAlert;
}

Zone * Zone::parent() {
	return parentZone;
}

string Zone::get_name() {
	return name;
}

void Zone::set_cases(int cases) {
	numOfCases = cases;
}


string Zone::parent_name() {
	if (parentZone == nullptr)
		return "N/A";
	else
		return parentZone->get_name();
}

