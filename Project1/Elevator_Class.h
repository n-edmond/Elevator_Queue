#ifndef ELEVATOR
#define ELEVATOR

#include <map>
#include "Person_Class.h"

using namespace std;
class Elevator:public Person
{
public:

	//DEFAULT CONSTRUCTOR 
	Elevator();

	//FUNCTIONS
	void Reverse_Elevator_Direction();//INVERTS THE ELEVATOR'S DIRECTION. USED FOR SINGLE ELEVATOR SYS
	void Update_Elevator_Location();//MOVES ELEVATOR UP OR DOWN

	//GETTERS
	bool Get_Is_Door_Open();//GETS WHETHER OR NOT THE DOOR IS OPEN
	deque <Person> Get_Elevator_Cart();//GETS DEQUE OF CURRENT RIDERS ON THE ELEVATOR
	int Get_Elevator_Location();//GETS THE ELEVATORS CURRENT FLOOR
	bool Get_Elevator_Direction();//GETS THE DIRECTION THE ELEVATOR IS CURRENTLY HEADED
	bool Get_Floor_Stop(int user_selection);

	//SETTERS
	void Set_Is_Door_Open(bool check);//SETS THE DOOR TO CLOSED WHEN CALLED. 
	void Set_Elevator_Cart(deque<Person> temp_cart);//SETS DEQUE OF CURRENT RIDERS ON THE ELEVATOR
	void Set_Elevator_Direction(bool direction);
	void Set_Elevator_Location(int loc);
	void Set_Floor_Stop(int user_selection, bool status);

private:
	deque<Person> elevator_cart;//DEQUE OF PEOPLE CURRENTLY RIDING ON THE ELEVATOR
	std::map<int, bool> floor_stops = { {1, false}, {2, false}, {3, false} };//MAP OF FLOORS THE ELEVATOR WILL STOP AT
	bool door_check;//CHECKS IF DOOR IS OPEN
	bool going_up;//CHECKS IF ELEVATOR IS GOING UP
	int current_elevator_floor;//CURRRENT FLOOR THE ELEVATOR IS ON; DEFAULTS TO FIRST FLOOR
};
#endif