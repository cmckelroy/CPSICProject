// Appointment Release.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../src/Appointment.h"
#include "../src/Patient.h"
#include "../src/Clinician.h"

int main()
{
	std::cout << "Welcome to the appointment system for CPSIC.\n";
	std::cout << "Choose a view to exemplify or type Q to quit: \n"
		<< "1. Patient"
		<< "2. Clinician"
		<< "Input: ";
	char choice;
	cin >> choice;

	while (choice != 'Q' && choice != 'q') {
		//enter 'clinican' functions test
		if (choice == '2') {

		}
		//enter 'patient' functions test
		else {

		}
	}

	
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