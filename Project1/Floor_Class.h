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
	void Floor_Check(int curr_floor, Elevator& elevator_cart);//CHANGES THE DIRECTION OF THE ELEVATOR IF IT HITS THE END OF ITS QUEUE (TOP OR BOTTOM)
	queue<Person>* Queue_Switcher(int curr_floor);//POINTS TO THE QUEUE VARIABLE APPROPRIATE TO THE CURRENT FLOOR
	Elevator Exit_Elevator(int curr_floor, Elevator elevator_cart);//REMOVES ANY RIDERS WHOSE DESTINATION MATCHES THE CURRENT FLOOR AND OUTPUTS THEIR WAIT TIME
	Elevator Enter_Elevator(int curr_floor, int sec_delay, Elevator elevator_cart);//GENERATES THE LINE FORMED OUTSIDE THE ELEVATOR. CHECK ASSUMPTION PAGE
	void Queue_Generator(int curr_floor, Person waiter, Elevator elevator_cart);//WAIT LINE. USED IF PERSON NOT ABLE TO ENTER ELEVATOR. CHECK ASSUMPTIONS PAGE
	
	void Multi_Elevator_Sys(queue<Person> q1, queue<Person> q2, int floor_curr_on);//ALL PROCESS FOR MULTIPLE ELEVATORS HERE. THIS FUNCTION DICTATES WHICH ELEVATOR IS GETTING CALLED. SETS SEPARATE QUEUE FOR IF FULL.
private:

	int user_counter;//USED TO IDENTIFY SPECIFIC INDIVIDUAL
	queue<Person> floor_1_queue;//PEOPLE WAITING TO GET IN LINE FOR THE ELEVATOR. NOT THE PEOPLE IN THE ELEVATOR. 
	queue<Person> floor_1_queue_2;//ONLY FOR MULTI ELEVATOR SYS
	queue<Person> floor_2_queue;//PEOPLE WAITING TO GET IN LINE FOR THE ELEVATOR. NOT THE PEOPLE IN THE ELEVATOR. 
	queue<Person> floor_2_queue_2;//ONLY FOR MULTI ELEVATOR SYS
	queue<Person> floor_3_queue;//PEOPLE WAITING TO GET IN LINE FOR THE ELEVATOR. NOT THE PEOPLE IN THE ELEVATOR. 
	queue<Person> floor_3_queue_2;//ONLY FOR MULTI ELEVATOR SYS
};

#endif