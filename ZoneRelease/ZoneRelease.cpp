// ZoneRelease.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../src/Zone.h"

void print(Zone z);

int main()
{
	std::cout << "\nDeclaring a zone for Ohio...\n";

	Zone ohio("Ohio", false);
	print(ohio);

	std::cout << "\nDeclaring a zone for Kent...\n";
	Zone kent("Kent", false);
	print(kent);
	std::cout << "\nMaking Kent a child of Ohio...\n\n";
	kent.set_parent(ohio);

	//print kent information again
	print(kent);

	//print ohio information again
	print(ohio);

	return 0;
}

void print(Zone z) {
	using std::endl;
	std::cout << "Zone: " << z.get_name() << endl
		<< "Parent: " << z.parent_name() << endl
		<< "Child: " << z.child_name() << endl
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
