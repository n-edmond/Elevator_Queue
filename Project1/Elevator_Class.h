#ifndef ELEVATOR
#define ELEVATOR

#include "Person_Class.h"

using namespace std;
class Elevator
{
public:
	
	//FUNCTIONS
	//void load_Person(); //ADDS NEW USERS WHEN THE ELEVATOR DOOR OPENS. SETS ARRIVAL TIME
	void unload_Person(); //REMOVES USERS WHEN ELEVATOR DOOR OPENS. SETS DEPART TIME.
	void reverse_elevator_direction();
	void Add_Floor(int currFloor);
	void Remove_Floor();

	//GETTERS
	bool get_is_door_open();
	deque <Person> get_elevator_cart();
	int get_elevator_location();
	bool get_elevator_direction();
	deque <int> Get_Floor_List();

	//SETTERS
	void set_is_door_open(bool check);//SETS THE DOOR TO CLOSED WHEN CALLED. 
	void set_elevator_cart(deque <Person> temp_cart);//setter
	void set_elevator_location(int loc);

//	vector<Person> user_release();//saves the correct order
//	void elevator_release_display();//displays when the user will exit


private:
	deque <Person> elevator_cart;
	deque <int> floorList;
	bool doorCheck = true;
	bool goingUp = true;
	int currentElevatorFloor;
};
#endif