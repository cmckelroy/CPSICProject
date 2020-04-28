// Appointment Release.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../src/Appointment.h"
#include "../src/Patient.h"
#include "../src/Clinician.h"
#include "../src/WeeklyTimeRange.h"

int main()
{
	std::cout << "Welcome to the appointment system for CPSIC.\n\n";
	std::cout << "First, we will exemplify appointment creation/modification through the lens of a patient:\n\n";

	//instantiate PATIENT
	Patient testPatient("Edward", "Hyde", 666, "evil", false, true, MedicalRecord());
	//instantiate CLINICIAN
	Clinician testDoctor("Henry", "Jekyll", 777, "kittens", "General Practicioner");


	//PATIENT FUNCTIONS TEST-------------------

	//display patient
	std::cout << "Patient: " << testPatient.get_name() << std::endl;
	//display patient functions (in app release scope)
	std::cout << "\nAppointment Powers for Patients:\n"
		<< "1. Create Appointment:\n"
		<< "Scheduling an appointment with a doctor for Monday Apr 27 at 12:30 P.M.\n";

	//CREATE APPOINTMENT
	WeeklyTimeRange testTime(Monday, 12, 30, 13, 0);	//Monday at 12:30 - 1:00
	time_t startOfWeek = 1587859200;	//relative to this sunday (apr 24th 2020)
	AbsoluteTimeRange appTimeslot= testTime.to_absolute(startOfWeek);

	Appointment testApp = testPatient.create_appointment(testDoctor, appTimeslot);
	//display created appointment
	testApp.print_appointment();


	//RESCHEDULE APPOINTMENT
	std::cout << "2. Reschedule Appointment:\n"
		<< "Rescheduling appointment for Wednesday at the same time.\n";

	WeeklyTimeRange testTime2(Wednesday, 12, 30, 13, 0);
	appTimeslot = testTime2.to_absolute(startOfWeek);

	testPatient.reschedule_appointment(testApp, appTimeslot);
	testApp.print_appointment(); //display

	//CLINICIAN FUNCTIONS TEST-----------------

	//display clinician
	std::cout << "Clinician: " << testDoctor.get_name() << std::endl;

	std::cout << "\nAppointment Powers for Clinicians:\n"
		<< "1. Reschedule Appointment:\n"
		<< "Rescheduling previous appointment for Wednesday at a later time (4PM)\n";


	//RESCHEDULE APPOINTMENT
	WeeklyTimeRange testTime3(Wednesday, 16, 0, 16, 30);
	appTimeslot = testTime3.to_absolute(startOfWeek);

	testDoctor.reschedule_appointment(testApp, appTimeslot);
	testApp.print_appointment(); //display

	return 0;
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
