#include "Zone.h"
Zone::Zone(string name, bool gca) : name(name), parentZone(nullptr), childZone(nullptr), numOfCases(0), generatesCampusAlert(gca)
{
}

Zone::Zone(string name, int cases, bool gca) : name(name), parentZone(nullptr), childZone(nullptr), numOfCases(cases), generatesCampusAlert(gca)
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

Zone * Zone::child() {
	return childZone;
}

string Zone::get_name() {
	return name;
}

void Zone::set_cases(int cases) {
	numOfCases = cases;
}

void Zone::set_parent(Zone z) {
	parentZone = &z;
	//z.childZone = this;
}

void Zone::set_child(Zone z) {
	childZone = &z;
	//z.parentZone = this;
}

string Zone::parent_name() {
	if (parentZone == nullptr)
		return "N/A";
	else
		return parentZone->get_name();
}

string Zone::child_name() {
	if (childZone == nullptr)
		return "N/A";
	else
		return childZone->get_name();
	
}