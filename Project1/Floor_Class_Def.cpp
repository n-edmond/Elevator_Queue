#include <iostream>
#include "Floor_Class.h"

int Floor::Generate_ID() {
	++userCounter;
	return userCounter;
}

//THE FIRST FLOOR IN THE FLOOR LIST IS ALWAYS THE SMALLEST VALUE, WHILE THE LAST ONE IS THE LARGEST
//THEREFORE, YOU CAN KNOW IF YOU'RE AT THE FRONT OR BACK OF YOUR ELEVATOR QUEUE (THUS NEEDING TO CHANGE
//DIRECTIONS) BY SEEING IF THE CURRENT FLOOR MATCHES THE BACK OR FRONT OF THE QUEUE
void Floor::floor_check(int currFloor, Elevator elevator_cart)
{
	if (elevator_cart.Get_Floor_List().front() == currFloor 
		|| elevator_cart.Get_Floor_List().front() == currFloor)
	{
		elevator_cart.reverse_elevator_direction();
	}
}


queue<Person>* Floor::queue_switcher(int currFloor) {
	if (currFloor == 1)
	{
		return &floor_1_queue;
	}
	else if (currFloor == 2)
	{
		return &floor_2_queue;
	}
	else
	{
		return &floor_3_queue;
	}

}

Elevator Floor::get_out_elevator(int currFloor, int secDelay, Elevator elevator_cart)
{
	
	int personLoad = 20 / secDelay;
	int counter = 0;

	deque<Person> cart_persons = elevator_cart.get_elevator_cart();

	for (int i = 0; i < cart_persons.size(); 0 )
	{
		if (cart_persons.at(i).Get_Destination() == currFloor)
		{
			cart_persons.at(i).Set_Depart_Time();
			cart_persons.pop_front();
		}
	}

	elevator_cart.set_elevator_cart(cart_persons);
	return elevator_cart;
}

Elevator Floor::get_in_elevator(int currFloor, int secDelay, Elevator elevator_cart)
{
	
	//assume elevator door stays open for 20 seconds before the door closes. 
	//personLoad determines how many people will be wanting an elevator given the secDelay
	int personLoad = 20 / secDelay;
	int counter = 1;

	queue<Person>* floor_queue = queue_switcher(currFloor);
	deque<Person> cart_persons = elevator_cart.get_elevator_cart();

	while (floor_queue->size() > 0 && personLoad > 0)
	{
		if (cart_persons.size() < 15)//elevator can only hold 15 people. If more, we cannot add another person. 
		{
			cart_persons.push_back(floor_queue->front()); //add the first person from the floor queue to the elevator
			elevator_cart.Add_Floor(floor_queue->front().Get_Destination()); // add the floor the user selected to the elevator's list of floors (if not already present)

			floor_queue->pop();
			personLoad--;
		}
		else
		{
			return elevator_cart;
		}
	}
	//for (int maxTime= 0; maxTime < 20; ++maxTime)FOR THE SAMPLE TIME OF 20 MINS. MAY PUT IN DISPLAY SECTION

	for (int i = 1; i <= personLoad; i++) //this simulates the door closing after 20 seconds since a person appears every 2 seconds. 
	{
		// Creates a new user with each iteration of the loop, then delays 2 seconds to mimic arrival of users in real time
		Person rider(Generate_ID(), currFloor);
		//rider.Delay(secDelay);//ADDS SECOND DELAY BASED ON BUSY-NESS. 2 SEC FOR BUSY, 4 FOR AVERAGE, 6 FOR SLOW. 
		int floorChosen = rider.Get_Destination(); // Floor is automatically randomized when rider is generated
		bool riderDirection = floorChosen > currFloor;

		if (cart_persons.size() < 15)//elevator can only hold 15 people. If more, we cannot add another person. 
		{
			cart_persons.push_back(rider);
			Set_Floor_Limits(cart_persons.back().Get_Destination()); //SET FLOOR LIMITS BASED ON THE RIDER THAT WAS JUST ADDED
			cout << "2 seconds have passed. This person is going to this floor: " << floorChosen << endl;
		}
		else//if the elevator has more than capacity, form a queue outside door. Queue cannot be more than 20 people. 
		{
			cout << "Elevator at max capacity. Must wait for next elevator cart or get on other elevator.";
			queue_generator(currFloor, rider, elevator_cart);
			break;
		}
	}
	elevator_cart.set_elevator_cart(cart_persons);
	floor_check(currFloor, elevator_cart);

	cout << "The door is now closing. " << endl;
	elevator_cart.set_is_door_open(false);//closes the elevator door.

	elevator_cart.set_elevator_location();

	return elevator_cart;
}

void Floor::queue_generator(int currFloor, Person waiter, Elevator elevator_cart)
{//if the elevator door is open, the elevator cart size is not 15, and the waiting line does not have 20 people in it, add new people to the queue
	queue<Person>* floor_queue = queue_switcher(currFloor);

	if ((!elevator_cart.get_is_door_open() || elevator_cart.get_elevator_cart().size() > 15) && (floor_queue->size() <= 20))
	{
		cout << "The door is closed. Forming line";
		floor_queue->push(waiter);
	}
	else
	{
		cout << "The line is too long and it would be more efficient to take the stairs. This person has decided to do so." << endl;
	}
}
