#ifndef ELEVATOR
#define ELEVATOR

#include <vector>
#include "Person_Class.h"

using namespace std;
class Elevator
{
public:
	void set_is_door_open(bool check);
	bool get_is_door_open();
	vector<Person> get_elevator_cart();//getter
	void set_elevator_cart(vector <Person> temp_cart);//setter
	void load_Person(); //when elevator opens, can use this to add the appropriate new riders
	void unload_Person(); //when elevator opens, can use this to remove the appropriate riders and set their depart time
//	vector<Person> user_release();//saves the correct order
//	void elevator_release_display();//displays when the user will exit


private:
	vector<Person> elevator_cart;
	bool doorCheck = true;
};
#endif