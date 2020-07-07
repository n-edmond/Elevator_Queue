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

void Elevator::Reverse_Elevator_Direction() 
{//SWAPS DIRECTION OF ELEVATOR. USED FOR SINGLE ELEVATOR SYS.

	going_up = !going_up;
}

void Elevator::Update_Elevator_Location()
{
	for(int i = 0; i < 5; i++)
	{
		if (current_elevator_floor == 3)//IF THE CURRENT FLOOR IS 3, THE ELEVATOR CAN ONLY GO DOWN
		{
			going_up = false;
		}
		else if (current_elevator_floor == 1) //IF THE CURRENT FLOOR IS 1, THE ELEVATOR CAN ONLY GO UP.
		{
			going_up = true;
		}
		if (going_up)
		{
			current_elevator_floor++;//MOVES ELEVATOR UP
		}
		else
		{
			current_elevator_floor--;//MOVES ELEVATOR DOWN
		}

		if (floor_stops[current_elevator_floor])
		{
			break;
		}
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

bool Elevator::Get_Floor_Stop(int user_selection)
{
	return floor_stops[user_selection];
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

void Elevator::Set_Elevator_Direction(bool direction)
{
	going_up = direction;
}

void Elevator::Set_Elevator_Location(int loc)
{
	current_elevator_floor = loc;
	floor_stops[loc] = true;
}

void Elevator::Set_Floor_Stop(int user_selection, bool status)
{
	if (status != floor_stops[user_selection])
	{
		floor_stops[user_selection] = status;
	}
}
