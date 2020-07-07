#include <iostream>
#include <time.h>
#include "Floor_Class.h"


Floor::Floor() 
{
	user_counter = 0;
}


//FUNCTIONS
int Floor::Generate_ID() 
{//GIVES EACH RIDER A UNIQUE ID. INCREMENTS COUNTER, RETURNS VALUE
	++user_counter;
	return user_counter;
}

queue<Person>* Floor::Queue_Switcher(int curr_floor, int elevator_number) 
{//POINTS TO QUEUE OF WAITING RIDERS BASED ON THE FLOOR THE ELEVATOR IS CURRENTLY ON. USES LINE FORMED ON THAT FLOOR 

	if (elevator_number == 1 && curr_floor == 1)
	{
		return &floor_1_queue_1;
	}
	else if (elevator_number == 1 && curr_floor == 2)
	{
		return &floor_2_queue_1;
	}
	else if (elevator_number == 1 && curr_floor == 3)
	{
		return &floor_3_queue_1;
	}
	else if (elevator_number == 2 && curr_floor == 1)
	{
		return &floor_1_queue_1;
	}
	else if (elevator_number == 2 && curr_floor == 2)
	{
		return &floor_2_queue_1;
	}
	else
	{
		return &floor_3_queue_1;
	}
}

void Floor::Add_From_Queue(int curr_floor, deque <Person> &cart_persons, Elevator &elevator_cart, int elevator_number)
{//UNLOADS APPROPRIATE QUEUE FOR ELEVATOR ONTO ELEVATOR
	queue<Person>* floor_queue = Queue_Switcher(curr_floor, elevator_number);//POINTS TO APPROPIRATE QUEUE FOR THIS FLOOR

	while (floor_queue->size() > 0)
	{
		if (cart_persons.size() < 15)//CHECKS ELEVATOR CAPACITY IS NOT MET 
		{
			cart_persons.push_back(floor_queue->front()); //ADDING FIRST PERSON TO ELEVATOR
			elevator_cart.Set_Floor_Stop(floor_queue->front().Get_Destination(), true);
			floor_queue->pop();
		}
		else
		{
			break;
		}
	}
}

void Floor::Add_New_Person(int curr_floor, Elevator &elevator_cart, deque <Person> &cart_persons, int time_elevator_available, int elevator_number)
{
	
	for (int i = 1; i <= time_elevator_available; i++) //THIS SIMULATES DOOR CLOSING AFTER 20 SECONDS 
	{
		Person rider(Generate_ID(), curr_floor, clock());
		//rider.Delay(sec_delay);//ADDS SECOND DELAY BASED ON VOLUME. 2 SEC FOR BUSY, 4 FOR AVERAGE, 6 FOR SLOW. 
		int floorChosen = rider.Get_Destination(); // FLOOR AUTOMATICALLY RANDOMIZED WHEN USER IS GENERATED

		if (cart_persons.size() < 15)//ELEVATOR CAN ONLY HOLD 15 PEOPLE 
		{
			cart_persons.push_back(rider);
			cout << "Rider #" << rider.Get_ID() << " has entered elevator " << elevator_number 
				<< ". They are going to floor: " << floorChosen << endl;
		}
		else
		{
			cout << "Elevator " << elevator_number << " at max capacity. Must wait for next elevator cart or get on other elevator." << endl;
			Queue_Generator(curr_floor, rider, cart_persons, elevator_cart, elevator_number);
		}
		elevator_cart.Set_Floor_Stop(rider.Get_Destination(), true);
	}
}

Elevator Floor::Exit_Elevator(Elevator elevator_cart, int curr_floor, int elevator_number)
{//REMOVES USERS FROM ELEVATOR TO THE CURRENT FLOOR. SETS THE UPDATED DEQUE OF RIDERS TO THE ELEVATOR OBJECT AND RETURNS THE ELEVATOR OBJECT

	int counter = 0;
	deque<Person> cart_persons = elevator_cart.Get_Elevator_Cart();
	Person current_rider;
	elevator_cart.Set_Is_Door_Open(true);

	cout << "Elevator " << elevator_number << "'s doors have opened." << endl;
	while(counter < cart_persons.size())
	{
		if (cart_persons.at(counter).Get_Destination() == curr_floor) {//REMOVES THE PERSON IN THE ELEVATOR IF IT IS THEIR DESTINATION
			cart_persons.at(counter).Set_Depart_Time();
			cart_persons.at(counter).Depart_Display();
			cart_persons.erase(cart_persons.begin() + counter);
		}
		else
		{//MOVES  THROUGH THE ELEVATOR CART
			counter++;
		}
	}
	elevator_cart.Set_Elevator_Cart(cart_persons);
	elevator_cart.Set_Floor_Stop(curr_floor, false);
	
	return elevator_cart;
}

Elevator Floor::Enter_Elevator(int sec_delay, Elevator elevator_cart, int curr_floor, bool muliple_elevators, int elevator_number)
{//WILL BEGIN ADDING USERS INTO THE ELEVATOR

	int time_elevator_available = 20;//AMOUNT OF TIME ELEVATOR DOORS WILL BE OPEN
	int counter = 1;
	
	deque <Person> cart_persons = elevator_cart.Get_Elevator_Cart();//THIS IS ESSENTIALLY THE ELEVATOR CART. HOLDS ALL USERS
	
	Add_From_Queue(curr_floor, cart_persons, elevator_cart);

	//for (int maxTime= 0; maxTime < 20; ++maxTime)FOR THE SAMPLE TIME OF 20 MINS. MAY PUT IN DISPLAY SECTION
	if (cart_persons.size() < 15 && Get_Program_End_Check() == false)
	{
		time_elevator_available /= sec_delay;
		Add_New_Person(curr_floor, elevator_cart, cart_persons, time_elevator_available, elevator_number);
	}

	if (cart_persons.size() < 1)
	{
		elevator_cart.Set_Elevator_Cart(cart_persons);
		elevator_cart.Update_Elevator_Location();
		return elevator_cart;
	}

	if (curr_floor == 2 && cart_persons.front().Get_ID() == 1)
	{
		int first_destination = cart_persons.front().Get_Destination();
		elevator_cart.Set_Elevator_Location(first_destination);

		elevator_cart.Set_Elevator_Cart(cart_persons);
	}
	else
	{
		elevator_cart.Set_Elevator_Cart(cart_persons);
		elevator_cart.Update_Elevator_Location();
	}	

	cout << "\nThe door for elevator " << elevator_number 
		<< " is now closing. Heading to Floor #" << elevator_cart.Get_Elevator_Location() 
		<< endl << endl;
	elevator_cart.Set_Is_Door_Open(false);//CLOSES THE ELEVATOR DOOR

	return elevator_cart;
}

void Floor::Queue_Generator(int curr_floor, Person waiter, deque <Person> cart_persons, Elevator &elevator_cart, bool multiple_elevators)
{//ADDS ANY RIDERS THAT WERE UNABLE TO GET ON THE ELEVATOR INTO A LINE

	queue<Person>* floor_queue_1 = Queue_Switcher(curr_floor, 1);//POINTS TO APPROPRIATE QUEUE FOR THIS FLOOR AND QUEUE
	queue<Person>* floor_queue_2 = NULL;
	if (multiple_elevators)
	{
		floor_queue_2 = Queue_Switcher(curr_floor, 2);//POINTS TO APPROPRIATE QUEUE FOR THIS FLOOR AND QUEUE
	}

	//(IF THE DOOR IS CLOSED OR IF THE ELEVATOR HAS 15 PEOPLE) AND (if the line size is less than 10)
	if ((!elevator_cart.Get_Is_Door_Open() || cart_persons.size() == 15) ) //(floor_queue->size() <= 10))
	{//CHECKS IF THE DOOR IS CLOSED OR IF THERE ARE TOO MANY PEOPLE ON ELEVATOR. LINE FORMS IF SO.
		if (multiple_elevators)
		{
			Set_Program_End_Check();//CHECK WHICH LINE IS SMALLER
			Multi_Elevator_Sys(*floor_queue_1, *floor_queue_2, waiter);//SHOULD DO LINE COMPARISON
		}
		else
		{
			cout << "The elevator door is closing. Forming line\n";
			floor_queue_1->push(waiter);
		}
		//cout << "The door is closing. Forming line\n";
		//floor_queue_1->push(waiter);
		//Set_Max_Queue_Check(*floor_queue_1);
	}
	else
	{//IF LINE IS TOO LONG, NO MORE PEOPLE WILL JOIN. USERS WILL TAKE THE STAIRS INSTEAD.
		cout << "The line is too long and people have decided to take the stairs. No more people will be joining the queue on floor " << curr_floor<< "."<<endl;
		Set_Program_End_Check();
	}
}

int Floor::Floor_Start_Randomizer()
{//IDENTIFIES WHICH FLOOR PRESSED ELEVATOR BUTTON FIRST

	int first_button_push = rand() % 3 + 1;
	return first_button_push;
}

void Floor::Multi_Elevator_Sys(queue<Person> &q1, queue<Person> &q2, Person user)
{
	if (q1.size() > q2.size())
	{//LINE 1 IS LONGER THAN LINE 2, PERSON WILL MOVE TO THE SHORTER LINE
		q2.push(user);
	}
	else
	{
		q1.push(user);
	}
}

//GETTER
bool Floor::Get_Program_End_Check()
{
	return no_more_rider_check;
}

//SETTER
void Floor::Set_Program_End_Check()
{
	this->no_more_rider_check = true;
}