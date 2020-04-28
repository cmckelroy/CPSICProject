// ZoneRelease.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../src/Zone.h"

void print(Zone z);

int main()
{
	using std::cout;
	using std::endl;

	cout << "This program tests the Zone functionality by declaring Zones which may contain Coronavirus; statistics are inputted as examples (and are not accurate).\n"
		<< "There are three disctinct zones of note to the Kent State Health System: KSU, Ohio, and the United States.\n";

	Zone unitedStates("United States", nullptr, 100000, false);
	Zone ohio("Ohio", &unitedStates, 7000, false);
	Zone kent("KSU", &ohio, true);	//if there are cases at KSU, this should generate an alert

	//print zones
	print(unitedStates);
	print(ohio);
	print(kent);

	if (kent.retrieve_num_of_cases() == 0)
		cout << "There are no cases at Kent State.\n";

	std::cout << "However, this data can be updated if someone comes into Kent State health services with coronavirus.\n";
	kent.set_cases(5);
	print(kent);

	return 0;
}

void print(Zone z) {
	using std::endl;
	std::cout << "\nZone: " << z.get_name() << endl
		<< "Parent: " << z.parent_name() << endl
		<< "Cases: " << z.retrieve_num_of_cases() << endl
		<< "GCA: " << z.should_alert() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
