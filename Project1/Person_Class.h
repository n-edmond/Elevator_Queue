#ifndef PERSON
#define PERSON

#include <queue>
#include <time.h>
#include <vector>

using namespace std;
class Person
{
public:

	//CONSTRUCTORS
	Person();
	Person(int counter, int current_floor);

	//FUNCTIONS
	int Destination_Generator(int floor_curr_on);//RANDOMIZES THE FLOOR BASED ON THE FLOOR THE USER IS CURRENTLY ON
	void Delay(int number_of_seconds);//SIMULATES A DELAY FOR THE ELEVATOR.
	void Depart_Display();//DISPLAYS INFORMATION REGARDING THE USER'S ID AND HOW LONG THEY WERE ON THE ELEVATOR
	int Floor_Start_Randomizer();//DECIDES WHICH FLOOR HAS PRESSED THE BUTTON FOR THE ELEVATOR FIRST.

	//GETTERS
	int Get_ID();//GET UNIQUE ID
	int Get_Destination();//GETTER FOR RAND FLOOR GENERATOR
	clock_t Get_Arrival_Time();//GET WHEN THE RIDER STARTED WAITING FOR THE ELEVATOR
	clock_t Get_Depart_Time();//GET WHEN THE RIDER LEFT THE ELEVATOR

	//SETTERS
	void Set_Depart_Time();// DEPART TIME SETTER

private:

	int id; // USER SPECIFIC. CREATES A USER TO PRESS ELEVATOR BUTTON
	clock_t arrive_time;//TIME USER IS CREATED
	clock_t depart_time;//TIME USER GETS OFF THE ELEVATOR
	int destination;//DESIRED FLOOR
	int count = 0;

	//VECTOR OF POSSIBLE FLOOR CHOICES NOT SURE IF I WILL USE THIS YET. SMALL ENOUGH POPULATION THAT I PREPOPULATED IT
	vector<int> floor1_options{ 2, 3 };
	vector<int> floor2_options{ 2, 3 };
	vector<int> floor3_options{ 1, 2 };
};
#endif