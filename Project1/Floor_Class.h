#ifndef FLOOR
#define FLOOR

#include "Elevator_Class.h"

using namespace std;

class Floor :public Elevator
{
public:

	//DEFAULT CONSTRUCTOR
	Floor();

	//FUNCTIONS
	int Generate_ID(); //INCREMENTS COUNTER EACH TIME IT IS CALLED AND RETURNS UPDATED COUNT. THIS IS USED FOR IDENTIFYING SPECIFIC PERSONS
	queue<Person>* Queue_Switcher(int curr_floor, int elevator_number = 1);//POINTS TO THE QUEUE VARIABLE APPROPRIATE TO THE CURRENT FLOOR
	void Add_From_Queue(int curr_floor, deque <Person>& cart_persons, Elevator &elevator_cart, int elevator_number = 1);
	void Add_New_Person(int curr_floor, Elevator &elevator_cart, deque <Person>& cart_persons, int time_elevator_available, int elevator_number);
	Elevator Exit_Elevator(Elevator elevator_cart, int curr_floor, int elevator_number = 1);//REMOVES ANY RIDERS WHOSE DESTINATION MATCHES THE CURRENT FLOOR AND OUTPUTS THEIR WAIT TIME
	Elevator Enter_Elevator(int sec_delay, Elevator elevator_cart, int curr_floor, bool multiple_elevators = false, int elevator_number = 1);//GENERATES THE LINE FORMED OUTSIDE THE ELEVATOR. CHECK ASSUMPTION PAGE
	void Queue_Generator(int curr_floor, Person waiter, deque <Person> cart_persons, Elevator &elevator_cart, bool multiple_elevators);//WAIT LINE. USED IF PERSON NOT ABLE TO ENTER ELEVATOR. CHECK ASSUMPTIONS PAGE
	int Floor_Start_Randomizer();//DECIDES WHICH FLOOR HAS PRESSED THE BUTTON FOR THE ELEVATOR FIRST.
	void Multi_Elevator_Sys(queue<Person> &q1, queue<Person> &q2, Person user);//ALL PROCESS FOR MULTIPLE ELEVATORS HERE. THIS FUNCTION DICTATES WHICH ELEVATOR IS GETTING CALLED. SETS SEPARATE QUEUE FOR IF FULL.
	
	//GETTERS
	bool Get_Program_End_Check();//RETURNS FALSE IF RIDER CAN STILL JOIN, TRUE IF RIDER CANNOT JOIN QUEUE

	//SETTERS
	void Set_Program_End_Check();

private:

	int user_counter = 0;//USED TO IDENTIFY SPECIFIC INDIVIDUAL
	bool no_more_rider_check = false;//USED TO STOP PEOPLE FROM GENERATING IN QUEUES. WILL INDICATE PROGRAM WILL END
	queue<Person> floor_1_queue_1;//PEOPLE WAITING TO GET IN LINE FOR THE ELEVATOR. NOT THE PEOPLE IN THE ELEVATOR. 
	queue<Person> floor_1_queue_2;//ONLY FOR MULTI ELEVATOR SYS
	queue<Person> floor_2_queue_1;//PEOPLE WAITING TO GET IN LINE FOR THE ELEVATOR. NOT THE PEOPLE IN THE ELEVATOR. 
	queue<Person> floor_2_queue_2;//ONLY FOR MULTI ELEVATOR SYS
	queue<Person> floor_3_queue_1;//PEOPLE WAITING TO GET IN LINE FOR THE ELEVATOR. NOT THE PEOPLE IN THE ELEVATOR. 
	queue<Person> floor_3_queue_2;//ONLY FOR MULTI ELEVATOR SYS
};

#endif