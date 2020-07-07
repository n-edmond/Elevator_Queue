#include <iostream>
#include <time.h>
#include <queue>
#include "Floor_Class.h"

using namespace std;
void Single_Elevator_Sys(int vol);//WILL SHOW IMPLEMENTATION OF SINGLE SYSTEM
void Multi_Elevator_Sys(int vol);//WILL SHOW IMPLEMENTATION OF 2 ELEVATOR SYSTEM

int main()
{
	srand((unsigned)time(0));
	
	int volume = 2;//CHANGE THE DIGIT HERE IF YOU WOULD LIKE TO SEE DIFFERENT SPEEDS. OPTIONS ARE 2, 4, 6 AS STATED ON ASSUMPTIONS PAGE

	Single_Elevator_Sys(volume);
	cout << "\n\nIf you would like to see the multi-elevator system, please uncomment it in the Main.cpp. Thank you! \n \n";

	//Multi_Elevator_Sys(volume);


	return 0;
}


void Single_Elevator_Sys(int vol)
{//CREATES THE SINGLE ELEVATOR SYSTEM
	cout << "**************************** SINGLE ELEVATOR SYSTEM ****************************" << endl;

	Floor bldg;
	Elevator elevator;
	
	int current_floor = bldg.Floor_Start_Randomizer();
	cout << "First rider is being picked up at Floor #" << current_floor << endl;

	elevator = bldg.Enter_Elevator(vol, elevator, current_floor);

	for (int i = 0; i < 7; i++) {//ITERATES A RANDOM NUMBER OF TIMES. THIS IS SIMPLY TO SHOW A SMALL WINDOW OF THE ELEVATOR PROCESS
		current_floor = elevator.Get_Elevator_Location();
		elevator = bldg.Exit_Elevator(elevator, current_floor);
		elevator = bldg.Enter_Elevator(vol, elevator, current_floor);
	}
	bldg.Set_Program_End_Check();
	while(elevator.Get_Elevator_Cart().size() > 0)//WHILE LOOP WILL KEEP GOING UNTIL THE LINES OUTSIDE THE ELEVATORS EMPTY. WILL TERMINATE HERE
	{
		current_floor = elevator.Get_Elevator_Location();
		elevator = bldg.Exit_Elevator(elevator, current_floor);
		elevator = bldg.Enter_Elevator(vol, elevator, current_floor);
	}
}

void Multi_Elevator_Sys(int vol)
{
	cout << "**************************** MULTI ELEVATOR SYSTEM ****************************" << endl;
	Floor bldg;
	Elevator elevator_1;
	Elevator elevator_2;

	int current_floor_1 = bldg.Floor_Start_Randomizer();
	cout << "First rider for elevator 1 is being picked up at Floor #" << current_floor_1 << endl;

	elevator_1 = bldg.Enter_Elevator(vol, elevator_1, current_floor_1, true, 1);

	int current_floor_2= bldg.Floor_Start_Randomizer();
	cout << "First rider for elevator 2 is being picked up at Floor #" << current_floor_2 << endl;

	elevator_2 = bldg.Enter_Elevator(vol, elevator_2, current_floor_2, true, 2);

	for (int i = 0; i < 7; i++) {//ITERATES A RANDOM NUMBER OF TIMES. THIS IS SIMPLY TO SHOW A SMALL WINDOW OF THE ELEVATOR PROCESS
		if (elevator_1.Get_Elevator_Cart().size() > 0)
		{
			current_floor_1 = elevator_1.Get_Elevator_Location();
			elevator_1 = bldg.Exit_Elevator(elevator_1, current_floor_1, 1);
			elevator_1 = bldg.Enter_Elevator(vol, elevator_1, current_floor_1, true, 1);
		}
		else if (elevator_2.Get_Elevator_Cart().size() > 0)
		{
			current_floor_2 = elevator_2.Get_Elevator_Location();
			elevator_2 = bldg.Exit_Elevator(elevator_2, current_floor_2, 2);
			elevator_2 = bldg.Enter_Elevator(vol, elevator_2, current_floor_2, true, 2);
		}
	}
	bldg.Set_Program_End_Check();
	while (elevator_1.Get_Elevator_Cart().size() > 0 || elevator_2.Get_Elevator_Cart().size() > 0)//WHILE LOOP WILL KEEP GOING UNTIL THE LINES OUTSIDE THE ELEVATORS EMPTY. WILL TERMINATE HERE
	{
		if (elevator_1.Get_Elevator_Cart().size() > 0)
		{
			current_floor_1 = elevator_1.Get_Elevator_Location();
			elevator_1 = bldg.Exit_Elevator(elevator_1, current_floor_1, 1);
			elevator_1 = bldg.Enter_Elevator(vol, elevator_1, current_floor_1, true, 1);
		}
		else if (elevator_2.Get_Elevator_Cart().size() > 0)
		{
			current_floor_2 = elevator_2.Get_Elevator_Location();
			elevator_2 = bldg.Exit_Elevator(elevator_2, current_floor_2, 2);
			elevator_2 = bldg.Enter_Elevator(vol, elevator_2, current_floor_2, true, 2);
		}
	}
}