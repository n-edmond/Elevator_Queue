#include <iostream>
#include <time.h>
#include "Floor_Class.h"


Floor::Floor() 
{
	user_counter = 0;
}

int Floor::Generate_ID() 
{//GIVES EACH RIDER A UNIQUE ID. INCREMENTS COUNTER, RETURNS VALUE

	++user_counter;
	return user_counter;
}

void Floor::Floor_Check(int curr_floor, Elevator& elevator_cart)
{//DETERMINES THE DIRECTION OF A FLOOR BASED ON BEGINING OR END OF ELEVATOR DEQUE

	if (elevator_cart.Get_Floor_Stops().front() == curr_floor
		|| elevator_cart.Get_Floor_Stops().back() == curr_floor)
	{//SINCE FIRST FLOOR IN DEQUE WILL BE SMALLEST, WILL HELP DETERMINE IF I NEED TO GO UP/DOWN
		elevator_cart.Reverse_Elevator_Direction();
	}
}
 
queue<Person>* Floor::Queue_Switcher(int curr_floor) 
{//POINTS TO QUEUE OF WAITING RIDERS BASED ON THE FLOOR THE ELEVATOR IS CURRENTLY ON. USES LINE FORMED ON THAT FLOOR 

	if (curr_floor == 1)
	{
		return &floor_1_queue;
	}
	else if (curr_floor == 2)
	{
		return &floor_2_queue;
	}
	else
	{
		return &floor_3_queue;
	}

}

Elevator Floor::Exit_Elevator(int curr_floor, Elevator elevator_cart)
{//REMOVES USERS FROM ELEVATOR TO THE CURRENT FLOOR. SETS THE UPDATED DEQUE OF RIDERS TO THE ELEVATOR OBJECT AND RETURNS THE ELEVATOR OBJECT

	int counter = 0;
	deque<Person> cart_persons = elevator_cart.Get_Elevator_Cart();
	elevator_cart.Set_Is_Door_Open(true);

	cout << "The elevator doors have opened.\n";

	while (counter < cart_persons.size())
	{//LOOPS THROUGH DEQUE OF RIDERS AND REMOVES USERS W/ MATCHING DESTINATIONS
		if (cart_persons.at(counter).Get_Destination() == curr_floor)
		{
			cart_persons.at(counter).Set_Depart_Time();
			cart_persons.at(counter).Depart_Display();
			cart_persons.pop_front();
		}
		else
		{
			counter++;//INCREMENTS COUNTER FOR THE WHILE LOOP. ENSURES USERS ARENT MISSED
		}
	}

	elevator_cart.Set_Elevator_Cart(cart_persons);
	return elevator_cart;
}

Elevator Floor::Enter_Elevator(int curr_floor, int sec_delay, Elevator elevator_cart)
{//WILL BEGIN ADDING USERS INTO THE ELEVATOR

	int elevator_available = 20;//ELEVATOR CAPACITY
	int counter = 1;
	queue<Person>* floor_queue = Queue_Switcher(curr_floor);//POINTS TO APPROPIRATE QUEUE FOR THIS FLOOR
	deque <Person> cart_persons = elevator_cart.Get_Elevator_Cart();//THIS IS ESSENTIALLY THE ELEVATOR CART. HOLDS ALL USERS

	while (floor_queue->size() > 0 && elevator_available > 0)
	{
		if (cart_persons.size() < 15)//CHECKS ELEVATOR CAPACITY IS NOT MET 
		{
			cart_persons.push_back(floor_queue->front()); //ADDING FIRST PERSON TO ELEVATOR
			floor_queue->pop();
			elevator_available -= 2;//TIME IT TAKES USER TO GET ON ELEVATOR
		}
		else
		{
			return elevator_cart;
		}
	}
	//for (int maxTime= 0; maxTime < 20; ++maxTime)FOR THE SAMPLE TIME OF 20 MINS. MAY PUT IN DISPLAY SECTION
	cout << endl;
	elevator_available /= sec_delay;
	for (int i = 1; i <= elevator_available; i++) //this simulates the door closing after 20 seconds since a person appears every 2 seconds. 
	{
		// Creates a new user with each iteration of the loop, then delays 2 seconds to mimic arrival of users in real time
		Person rider(Generate_ID(), curr_floor);
		//rider.Delay(sec_delay);//ADDS SECOND DELAY BASED ON BUSY-NESS. 2 SEC FOR BUSY, 4 FOR AVERAGE, 6 FOR SLOW. 
		int floorChosen = rider.Get_Destination(); // Floor is automatically randomized when rider is generated

		if (cart_persons.size() < 15)//elevator can only hold 15 people. If more, we cannot add another person. 
		{
			cart_persons.push_back(rider);
			//elevator_cart.Add_Floor(rider.Get_Destination());
			cout << "A person has entered the elevator. They are going to floor: " << floorChosen << endl;
		}
		else//if the elevator has more than capacity, form a queue outside door. Queue cannot be more than 20 people. 
		{
			cout << "Elevator at max capacity. Must wait for next elevator cart or get on other elevator.";
			Queue_Generator(curr_floor, rider, elevator_cart);
			break;
		}
	}

	elevator_cart.Set_Elevator_Cart(cart_persons);
	Floor_Check(curr_floor, elevator_cart);
	elevator_cart.Update_Elevator_Location();

	//elevator_cart.Remove_Floor(curr_floor);
	cout << "\nThe door is now closing. Heading to Floor #" << elevator_cart.Get_Elevator_Location() << endl << endl;
	elevator_cart.Set_Is_Door_Open(false);//closes the elevator door.

	return elevator_cart;
}

void Floor::Queue_Generator(int curr_floor, Person waiter, Elevator elevator_cart)
{//ADDS ANY RIDERS THAT WERE UNABLE TO GET ON THE ELEVATOR 

	queue<Person>* floor_queue = Queue_Switcher(curr_floor);//points to the appropriate queue for this floor

	if ((!elevator_cart.Get_Is_Door_Open() || elevator_cart.Get_Elevator_Cart().size() > 15) && (floor_queue->size() <= 10))
	{//CHECKS IF THE DOOR IS CLOSED OR IF THERE ARE TOO MANY PEOPLE ON ELEVATOR. LINE FORMS IF SO.
		cout << "The door is closing. Forming line\n";
		floor_queue->push(waiter);
	}
	else
	{//IF LINE IS TOO LONG, NO MORE PEOPLE WILL JOIN. USERS WILL TAKE THE STAIRS INSTEAD.
		cout << "The line is too long and people have decided to take the stairs. No more people will be joining the queue on floor " << curr_floor<< "."<<endl;
	}
}



/*void Multi_Elevator_Sys(queue<Person> q1, queue<Person> q2, int floor_curr_on)
{
	Person incoming_user;
	if (q1.size() > q2.size())
	{//LINE 1 IS LONGER THAN LINE 2, PERSON WILL MOVE TO THE SHORTER LINE
		q2.push(incoming_user.Destination_Generator(floor_curr_on));
	}
	else
	{
		q1.push(incoming_user.Destination_Generator(floor_curr_on);
	}
}*/