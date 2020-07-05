#include <iostream>
#include "Elevator_Class.h"
#include <queue>

using namespace std;

void Elevator::set_is_door_open(bool check) 
{
	this->doorCheck = check;
}

bool Elevator::get_is_door_open()
{
	return doorCheck;
}

vector<Person> Elevator::get_elevator_cart()
{
	return elevator_cart;
}
void Elevator::set_elevator_cart(vector <Person> temp_cart)
{
	this->elevator_cart = temp_cart;
}

void Elevator::load_Person() {
	
}

void Elevator::unload_Person() {

}