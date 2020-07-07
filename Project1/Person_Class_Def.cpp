#include <iostream>
#include <time.h>
#include "Person_Class.h"
#include <queue>
using namespace std;

Person::Person()
{
	id = 1;
	arrive_time = 0;
	depart_time = 0;
	destination = 1;
}

Person::Person(int counter, int currentFloor, clock_t start) 
{//CONSTRUCTOR
	id = counter;
	arrive_time = start;
	depart_time;
	destination = Destination_Generator(currentFloor);
}


//FUNCTIONS
int Person::Destination_Generator(int floor_curr_on)
{//RANDOMLY GENERATIONS USER'S DESIRED FLOOR. 
	int user_floor = rand() % 3 + 1;

	while (user_floor == floor_curr_on)//THIS WHILE LOOP WILL CHANGE THE RANDOMIZED FLOOR IF THIS NUMBER IS THE SAME AS THE FLOOR THEYRE CURRENTLY ON
	{
		user_floor = rand() % 3 + 1;
	}

	return user_floor;

	/*maybe instead try 3 separate vectors flr1 = {2,3}, flr2 = {1,3}, flr3 = {1,2}. Still debating on better approach. This might have smaller O(n)
	then use
	static int table[] = {0, 1, 2, 4, 5};
	int index = rand() % (sizeof table / sizeof *table);
	int number = table[index];
	*/
}

/*void Person::Delay(int number_of_seconds)
{//DELAYS EXECUTION OF PROGRAM BY N SECONDS

	int milli_seconds = 1000 * number_of_seconds;//Converts the requested num of seconds to milli_seconds
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);//loops until time is correct/
}*/

void Person::Depart_Display()

{//DISPLAYS THE USER DEPART TIME. SHOWS USER ID, FLOOR THEY EXITED, AND ELAPSED TIME
	cout << "Person #" << id
		<< " has departed from the elevator to floor " << destination
		<< ". Their wait time was "
		<< depart_time - arrive_time << " seconds."
		<< endl;
}

bool Person::operator <(const Person& rider)
{//OVERLOADING FOR CLASS COMPARISON
	return destination < rider.destination;
}

bool Person::operator >(const Person& rider)
{//OVERLOADING FOR CLASS COMPARISON
	return destination > rider.destination;
}

//GETTERS
int Person::Get_ID() {
	return id;
}

int Person::Get_Destination() {
	return destination;
}

clock_t Person::Get_Arrival_Time() {
	return arrive_time;
}

clock_t Person::Get_Depart_Time() {
	return depart_time;
}

//SETTERS
void Person::Set_Depart_Time() {
	depart_time = clock();
}

