#include <iostream>
#include <time.h>
#include <queue>
#include "Floor_Class.h"

using namespace std;
void single_elevator_sys();//will show implementation of single elevator system. 
void multi_elevator_sys();//will show implementation of multiple (2) elevator system.

int main()
{
	srand((unsigned)time(0));

	/*TO MAKE SIMULATION SHORT, WHAT IF I STOP RUNNING THE PROGRAM AFTER 10 PEOPLE HAVE GOTTEN IN LINE PER FLOOR? MIGHT BE TOO LONG OTHERWISE AND WILL 
	STILL SHOW GENERAL IDEA? THINK IT THROUGH FOR LATER/**/


	/*cout << "Welcome to the Elevator Simulator!\n\n";
	cout << "This program will simulate the order of user arrivals/departures.\n\n";
	cout << "Please choose from the options below: \n";
	cout << "1 - This will show you an elevator system in high volumes (2 second delay between arrivals)\n";
	cout << "2 - This will show you an elevator system in medium volumes (4 second delay between arrivals)\n";
	cout << "3 - This will show you an elevator system in low volumes (6 second delay between arrivals)\n";*/
	single_elevator_sys();


	//deque<Person> elevator_passengers = elevator.Get_Completed_Rides();
//	for (int i = 0; i < elevator_passengers.size(); ++i) {
//		cout << "Person #" << elevator_passengers.at(i).Get_ID() << "'s destination is Floor " << elevator_passengers.at(i).Get_Destination() << endl;
//	}

	return 0;
}

void single_elevator_sys()
{
	int current_floor = 1;
	Floor test;
	Elevator elevator;

	for (int i = 0; i < 3; i++) {
		elevator = test.Exit_Elevator(current_floor, elevator);
		elevator = test.Enter_Elevator(current_floor, 2, elevator);
		current_floor = elevator.Get_Elevator_Location();
	}
}