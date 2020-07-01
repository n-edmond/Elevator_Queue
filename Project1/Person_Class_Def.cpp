#include <iostream>
#include <time.h>
#include "Person_Class.h"
#include <vector>
#include <queue>
using namespace std;

int Person::get_rand_floor_generator(int floorCurrOn)
{
	//floor_vector.erase(floorCurrOn);
	int userFloor = rand() % 3 + 1;

	while (userFloor == floorCurrOn)//THIS WHILE LOOP WILL CHANGE THE RANDOMIZED FLOOR IF THE FLOOR IS THE SAME AS CURRENTLY ON
	{
		userFloor = rand() % 3 + 1;
	}

	return userFloor;
	
	/*maybe instead try 3 separate vectors flr1 = {2,3}, flr2 = {1,3}, flr3 = {1,2}. Still debating on better approach. This might have smaller O(n)
	then use
	static int table[] = {0, 1, 2, 4, 5};
	int index = rand() % (sizeof table / sizeof *table);
	int number = table[index];
	*/
}

void Person::set_rand_floor_generator(int userF)
{
	this->userFloor = userF;
}

void Person::delay(int number_of_seconds)
{
	int milli_seconds = 1000 * number_of_seconds;//Converts the requested num of seconds to milli_seconds
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);//loops until time is correct/
}

void Person::queue_generator(int currFloor, int secDelay, queue<int> elevator_car)
{
	//assume 5 people at a time before they all get in. 
	int count = 0;
	//int i;
	for (int i = 1; i <= 10; i++) //this simulates the door closing after 20 seconds since a person appears every 2 seconds. 
	{
		// delay of one second
		delay(secDelay);//ADDS SECOND DELAY BASED ON BUSY-NESS. 2 SEC FOR BUSY, 4 FOR AVERAGE, 6 FOR SLOW. 
		int floorChosen = get_rand_floor_generator(currFloor);
		set_rand_floor_generator(floorChosen);
		cout << "2 seconds have passed. This person is going to this floor: " << floorChosen << endl;

	}
}