#include <iostream>
#include <time.h>
#include <queue>
#include "Floor_Class.h"

using namespace std;
void Single_Elevator_Sys(int vol);//will show implementation of single elevator system. 
void Multi_Elevator_Sys(int vol);//will show implementation of multiple (2) elevator system.

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
	int volume = 2;
	Single_Elevator_Sys(volume);

	//Multi_Elevator_Sys(volume);
	//deque<Person> elevator_passengers = elevator.Get_Completed_Rides();
//	for (int i = 0; i < elevator_passengers.size(); ++i) {
//		cout << "Person #" << elevator_passengers.at(i).Get_ID() << "'s destination is Floor " << elevator_passengers.at(i).Get_Destination() << endl;
//	}

	return 0;
}

void Single_Elevator_Sys(int vol)
{
	Floor test;
	Elevator elevator;
	
	int current_floor = 2;//test.Floor_Start_Randomizer();
	cout << "First rider is being picked up at Floor #" << current_floor << endl;

	elevator = test.Enter_Elevator(vol, elevator, current_floor);
	test.Floor_Check(current_floor, elevator);
	for (int i = 0; i < 5; i++) {
		current_floor = elevator.Get_Elevator_Location();
		elevator = test.Exit_Elevator(elevator, current_floor);
		elevator = test.Enter_Elevator(vol, elevator, current_floor);
	}
}

void Multi_Elevator_Sys(int vol)
{
	Floor test;
	Elevator elevator_1;
	Elevator elevator_2;

	int current_floor_1 = test.Floor_Start_Randomizer();
	cout << "First rider for elevator 1 is being picked up at Floor #" << current_floor_1 << endl;

	elevator_1 = test.Enter_Elevator(vol, elevator_1, current_floor_1);
	test.Floor_Check(current_floor_1, elevator_1);

	int current_floor_2= test.Floor_Start_Randomizer();
	cout << "First rider for elevator 1 is being picked up at Floor #" << current_floor_2 << endl;

	elevator_2 = test.Enter_Elevator(vol, elevator_2, current_floor_2);
	test.Floor_Check(current_floor_2, elevator_2);

	for (int i = 0; i < 3; i++) {
		current_floor_1 = elevator_1.Get_Elevator_Location();
		elevator_1 = test.Exit_Elevator(elevator_1, current_floor_1);
		elevator_1 = test.Enter_Elevator(vol, elevator_1, current_floor_1);

		current_floor_2 = elevator_2.Get_Elevator_Location();
		elevator_2 = test.Exit_Elevator(elevator_2, current_floor_2);
		elevator_2 = test.Enter_Elevator(vol, elevator_2, current_floor_2);
	}
}