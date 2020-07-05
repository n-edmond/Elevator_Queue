#include <iostream>
#include <time.h>
#include <queue>
#include "Floor_Class.h"

using namespace std;

int main()
{
	srand((unsigned)time(0));

	Floor test;
	Elevator elevator;
	elevator = test.get_in_elevator(1, 2, elevator);
	deque<Person> elevator_passengers = elevator.get_elevator_cart();
	for (int i = 0; i < elevator_passengers.size(); ++i) {
		cout << "Person #" << elevator_passengers.at(i).Get_ID() << "'s destination is Floor " << elevator_passengers.at(i).Get_Destination() << endl;
	}
	return 0;
}