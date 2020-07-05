#include <iostream>
#include "Elevator_Class.h"
#include <queue>

using namespace std;


void Elevator::unload_Person()
{

//	if (get_floor)
//		set_is_door_open(true);

}

void Elevator::Add_Floor(int currFloor) 
{	
	floorList.push_back(currFloor);

	if (floorList.size() == 1)
	{
		return;
	}

	for (int i = 0; i < floorList.size(); i++)
	{
		if (currFloor < floorList.at(i)) 
		{
			deque<int>::iterator it = floorList.begin();
			it += i;
			floorList.insert(it, floorList.begin(), floorList.end());
		}
	}
}

//IF GOING UP, THE SMALLEST (FRONT) VALUES ARE THE ONES THAT NEED TO BE POPPED AND VICE VERSA IF GOING DOWN
void Elevator::Remove_Floor()
{
	if (goingUp)
	{
		floorList.pop_front();
	}
	else
	{
		floorList.pop_back();
	}
}

//GETTERS
bool Elevator::get_is_door_open()
{
	return doorCheck;
}

deque <Person> Elevator::get_elevator_cart()
{
	return elevator_cart;
}


int Elevator::get_elevator_location()
{
	return currentElevatorFloor;
}

bool Elevator::get_elevator_direction()
{
	return goingUp;
}

deque<int> Elevator::Get_Floor_List()
{
	return floorList;
}
//SETTERS

void Elevator::set_is_door_open(bool check)
{
	this->doorCheck = check;
}

void Elevator::set_elevator_cart(deque <Person> temp_cart)
{
	this->elevator_cart = temp_cart;
}

void Elevator::set_elevator_location(int loc)
{
	currentElevatorFloor = loc;
}

void Elevator::reverse_elevator_direction() {
	goingUp = !goingUp;
}