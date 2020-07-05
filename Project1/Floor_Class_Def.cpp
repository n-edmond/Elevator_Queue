#include <iostream>
#include "Floor_Class.h"

int Floor::riderID() {
	++riderCounter;
	return riderCounter;
}

void Floor::get_in_elevator(int currFloor, int secDelay, Elevator e_cart)
{
	//assume elevator door stays open for 20 seconds before the door closes. 
	//int count = 0;
	vector<Person> cart_persons = e_cart.get_elevator_cart();
	//for (int maxTime= 0; maxTime < 20; ++maxTime)FOR THE SAMPLE TIME OF 20 MINS. MAY PUT IN DISPLAY SECTION
	for (int i = 1; i <= 10; i++) //this simulates the door closing after 20 seconds since a person appears every 2 seconds. 
	{
		// Creates a new rider with each iteration of the loop, then delays 2 seconds to mimic arrival of riders in real time
		Person rider(riderID());
		rider.delay(secDelay);//ADDS SECOND DELAY BASED ON BUSY-NESS. 2 SEC FOR BUSY, 4 FOR AVERAGE, 6 FOR SLOW. 
		int floorChosen = rider.getFloor(); // Floor is automatically randomized when rider is generated

		if (cart_persons.size() < 15)//elevator can only hold 15 people. If more, we cannot add another person. 
		{
			cart_persons.push_back(rider);
			cout << "2 seconds have passed. This person is going to this floor: " << floorChosen << endl;
		}
		else//if the elevator has more than capacity, form a queuue outside door. Queue cannot be more than 20 people. 
		{
			cout << "Elevator at max capacity. Must wait for next elevator cart or get on other elevator.";
			queue_generator(currFloor, e_cart);
			break;
		}
	}
	cout << "The door is now closing. " << endl;
	e_cart.set_is_door_open(false);//closes the elevator door.
}

void Floor::queue_generator(int floorChosen, Elevator elevator_cart)
{//if the elevator door is open, the elevator cart size is not 15, and the waiting line does not have 20 people in it, add new people to the queue
	if ((!elevator_cart.get_is_door_open() || elevator_cart.get_elevator_cart().size() > 15) && (floor_1_queue.size() <= 20))
	{
		cout << "The door is closed. Forming line";
		floor_1_queue.push(floorChosen);

	}
	else
	{
		cout << "The line is too long and it would be more efficient to take the stairs. This person has decided to do so." << endl;
	}
}
