#include <iostream>
#include <time.h>
#include "Person_Class.h"
#include <queue>
using namespace std;

Person::Person( int counter, int currentFloor ){
	id = counter;
	arriveTime = clock();
	departTime;
//	userFloor = currentFloor;
	destination = Destination_Generator(currentFloor);
}

//FUNCTIONS
int Person::Destination_Generator(int floorCurrOn)
{
	//floor_vector.erase(floorCurrOn);
	int userFloor = rand() % 3 + 1;

	while (userFloor == floorCurrOn)//THIS WHILE LOOP WILL CHANGE THE RANDOMIZED FLOOR IF THE FLOOR IS THE SAME AS CURRENTLY ON
	{
		userFloor = rand() % 3 + 1;
	}

	return userFloor;
	
	/*maybe instead try 3 separate vectors flr1 = {2,3}, flr2 = {1,3}, flr3 = {1,2}. Still debating on better approach. This might have smaller O(n)
	then use
	static int table[] = {0, 1, 2, 4, 5};
	int index = rand() % (sizeof table / sizeof *table);
	int number = table[index];
	*/
}

void Person::Delay(int number_of_seconds)
{
	int milli_seconds = 1000 * number_of_seconds;//Converts the requested num of seconds to milli_seconds
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);//loops until time is correct/
}
/*
void Person::set_rand_floor_generator(int userF)
{
	this->userFloor = userF;
}
*/


//GETTERS
int Person::Get_ID() {
	return id;
}

//int Person::Get_Rider_Floor() {
//	return userFloor;
//}

int Person::Get_Destination() {
	return destination;
}

clock_t Person::Get_Arrival_Time() {
	return arriveTime;
}

clock_t Person::Get_Depart_Time() {
	return departTime;
}

void Person::Set_Depart_Time() {
	departTime = clock();
}



/*
void Person::get_in_elevator(int currFloor, int secDelay)
{
	//assume elevator door stays open for 20 seconds before the door closes. 
	//int count = 0;
	queue<Person> e_cart = Elevator::get_elevator_cart();
	//for (int maxTime= 0; maxTime < 20; ++maxTime)FOR THE SAMPLE TIME OF 20 MINS. MAY PUT IN DISPLAY SECTION
	for (int i = 1; i <= 10; i++) //this simulates the door closing after 20 seconds since a person appears every 2 seconds. 
	{
		// delay of one second
		delay(secDelay);//ADDS SECOND DELAY BASED ON BUSY-NESS. 2 SEC FOR BUSY, 4 FOR AVERAGE, 6 FOR SLOW. 
		int floorChosen = get_rand_floor_generator(currFloor);
		set_rand_floor_generator(floorChosen);
		if (e_cart.size() < 15)//elevator  can only hold 15 people. If more, we cannot add another person. 
		{
			e_cart.push(floorChosen);
			cout << "2 seconds have passed. This person is going to this floor: " << floorChosen << endl;
		}
		else//if the elevator has more than capacity, form a queuue outside door. Queue cannot be more than 20 people. 
		{
			cout << "Elevator at max capacity. Must wait for next elevator cart or get on other elevator.";
			queue_generator(currFloor, e_cart);
			break;
		}
	}
	cout << "The door is now closing. "<<endl;
	Elevator::set_is_door_open(false);//closes the elevator door.
}

void Person::queue_generator(int floorChosen, queue<Person> elevator_cart)
{//if the elevator door is open, the elevator cart size is not 15, and the waiting line does not have 20 people in it, add new people to the queue
	if ((!Elevator::get_is_door_open() || elevator_cart.size() > 15) && (floor_1_queue.size() <= 20) ) 
	{
		cout << "The door is closed. Forming line";
		floor_1_queue.push(floorChosen);

	}
	else
	{
		cout << "The line is too long and it would be more efficient to take the stairs. This person has decided to do so." << endl;
	}
}
*/
