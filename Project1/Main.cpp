#include <iostream>
#include <time.h>
#include <queue>
#include "Floor_Class.h"

using namespace std;

int main()
{
	srand((unsigned)time(0));

	Floor test;
	Elevator empty_elevator;
	test.get_in_elevator(1, 2, empty_elevator);
	return 0;
}