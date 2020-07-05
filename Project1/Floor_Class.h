#ifndef FLOOR
#define FLOOR

#include "Elevator_Class.h"

using namespace std;

class Floor 
{
public:

	//FUNCTIONS
	int Generate_ID(); //icrements counter each time it is called and returns updated count
	void floor_check(int currFloor, Elevator elevator_cart);
	queue<Person>* queue_switcher(int currFloor);
	Elevator get_out_elevator(int currFloor, int secDelay, Elevator elevator_cart);
	Elevator get_in_elevator(int currFloor, int secDelay, Elevator elevator_cart);//GENERATES THE LINE FORMED OUTSIDE THE ELEVATOR. ASSUME THAT THE NUMBERS ARE THE FLOORS USER WANTS TO GO TO. ASSUME BUTTON IS PUSHED
	//WHEN THEY GET IN ELEVATOR. FLOOR DESTINATION DECIDED TO INDICATE POSITON WHEN ARRIVED.
	void queue_generator(int currFloor,  Person waiter, Elevator elevator_cart);

	//GETTER
	void get_floor_location();

	//SETTER
	void set_floor_location();
	
private:
	int userCounter = 0;
	//PEOPLE WAITING TO GET IN LINE FOR THE ELEVATOR. NOT THE PEOPLE IN THE ELEVATOR. LINE WILL NOT CONTAIN MORE THAN 20 PEOPLE, BEFORE PPL TAKE STAIRS
	queue<Person> floor_1_queue;
	queue<Person> floor_2_queue;
	queue<Person> floor_3_queue;

};

#endif