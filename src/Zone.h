#pragma once
#include <string>
using namespace std;

/*! \brief This is the parent class of all other zone classes.
  *
  *  A Zone represents an area in which coronavirus is being tracked, and may contain or be contained by
  *  other zones. Zones currently expected to be used are "the USA", "Ohio", and "Kent State University",
  *  each of which contains the next. It's used to track and visualize coronavirus data.
  */
class Zone
{
protected:
	string name;  ///< the name of the zone (i.e. "United States")
	Zone * parentZone;  //< pointer to the parent zone, if there is one.
	int numOfCases;  //< number of cases of coronavirus in that zone
	bool generatesCampusAlert;
public:
	//constructor; cases default = 0
	Zone(string name, Zone* parent, bool gca);
	//constructor for all fields
	Zone(string name, Zone* parent, int cases, bool gca);

	/**

	@return Returns the number of coronavirus cases in that zone.
	*/
	int retrieve_num_of_cases();
	//get campus alert bool
	bool should_alert();
	//get pointer to parent zone
	Zone * parent();
	//get zone name
	string get_name();
	//get name of parent zone, if it exists
	string parent_name();

	//sets the number of cases in a zone
	void set_cases(int cases);
};

