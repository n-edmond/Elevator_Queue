#include <iostream>
#include "Elevator_Class.h"
#include <queue>

using namespace std;

Elevator::Elevator()
{
	door_check = true;//CHECKS IF DOOR IS OPEN
	going_up = false;//CHECKS IF ELEVATOR IS GOING UP
	current_elevator_floor = 1;
}

/*
//WHEN A USER REQUESTS A DESTINATION FLOOR, IT IS ADDED TO THE ELEVATOR'S DEQUE OF STOPS, AS LONG AS THE FLOOR
//ISN'T ALREADY PRESENT. THE DEQUE IS SORTED IN ORDER OF SMALLEST TO LARGEST.
//IF THE DEQUE IS EMPTY, THEN THE ELEVATOR HAS NO STOPS PENDING AND THE LOCATION IS ADDED AUTOMATICALLY.
//IF ONE FLOOR IS PRESENT AND IT IS NOT EQUAL TO THE REQUESTED FLOOR, THEN IS IS INSERTED INTO THE DEQUE BASED ON ITS SIZE
//BECAUSE THERE ARE ONLY THREE FLOORS, AND THE ELEVATOR'S CURRENT FLOOR DOES NOT NEED TO BE CONSIDERED, THEN THERE WILL ONLY
//EVER BE 2 FLOORS IN THE DEQUE AT THE MOST. THEREFORE, THE CHECKS DESCRIBED ABOVE ARE ALL THAT ARE NEEDED
void Elevator::Add_Floor(int new_destination)
{
	if (floor_stops.size() == 0)
	{
		floor_stops.push_back(new_destination);
		current_elevator_floor = new_destination;
		return;
	}
	else if (floor_stops.size() == 1 && floor_stops.front() != new_destination)
	{
		if (new_destination > floor_stops.front())
		{
			floor_stops.push_back(new_destination);
		}
		else
		{
			floor_stops.push_front(new_destination);
		}
		current_elevator_floor = new_destination;
	}
}

//REMOVES THE FLOOR THE ELEVATOR IS CURRENTLY ON FROM THE DEQUE. IF THE ELEVATOR IS GOING UP, THEN THE CURRENT FLOOR
//WOULD BE ON THE FRONT OF THE DEQUE. IF IT'S GOING DOWN, THEN IT WOULD BE ON THE BACK.
void Elevator::Remove_Floor(int curr_floor)
{
	if (going_up and curr_floor == floor_stops.front())
	{
		floor_stops.pop_front();
		current_elevator_floor = floor_stops.front();
	}
	else if(!going_up and curr_floor == floor_stops.back())
	{
		floor_stops.pop_back();
		current_elevator_floor = floor_stops.back();
	}
}
*/

void Elevator::Reverse_Elevator_Direction() 
{//SWAPS DIRECTION OF ELEVATOR. USED FOR SINGLE ELEVATOR SYS.

	going_up = !going_up;
}

void Elevator::Update_Elevator_Location()
{//MOVES THE ELEVATOR UP OR DOWN

	if (going_up)
	{
		current_elevator_floor++;
	}
	else
	{
		current_elevator_floor--;
	}
}

//GETTERS
bool Elevator::Get_Is_Door_Open()
{
	return door_check;
}

deque<Person> Elevator::Get_Elevator_Cart()
{
	return elevator_cart;
}

int Elevator::Get_Elevator_Location()
{
	return current_elevator_floor;
}

bool Elevator::Get_Elevator_Direction()
{
	return going_up;
}

deque<int> Elevator::Get_Floor_Stops()
{
	return floor_stops;
}

//SETTERS
void Elevator::Set_Is_Door_Open(bool check)
{
	this->door_check = check;
}

void Elevator::Set_Elevator_Cart(deque<Person> temp_cart)
{
	this->elevator_cart = temp_cart;
}
