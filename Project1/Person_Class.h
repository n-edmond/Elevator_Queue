#ifndef PERSON
#define PERSON

#include <queue>
#include <time.h>
#include <vector>

using namespace std;
class Person
{
public:
	Person(int counter, int currentFloor);// CONSTRUCTOR
	
	//FUNCTIONS
	int Destination_Generator(int floorCurrOn);//RANDOMIZES THE FLOOR BASED ON THE FLOOR THE USER IS CURRENTLY ON
	void Delay(int number_of_seconds);//SIMULATES A DELAY FOR THE ELEVATOR.
//	void set_rand_floor_generator(int userF);//SETTER FOR RAND FLOOR GEN. USED ELSEWHERE 

	//GETTERS
	int Get_ID();//
//	int Get_Rider_Floor();//FLOOR THE USER IS ON. USED IN FLOORS OBJ, 
	int Get_Destination();//GETTER FOR RAND FLOOR GENERATOR
	clock_t Get_Arrival_Time();
	clock_t Get_Depart_Time();

	//SETTERS
	void Set_Depart_Time();// DPRT TIME SETTER
 

//	void get_in_elevator(int currFloor, int secDelay);//GENERATES THE LINE FORMED OUTSIDE THE ELEVATOR. ASSUME THAT THE NUMBERS ARE THE FLOORS USER WANTS TO GO TO. ASSUME BUTTON IS PUSHED
	//WHEN THEY GET IN ELEVATOR. FLOOR DESTINATION DECIDED TO INDICATE POSITON WHEN ARRIVED.
//	void queue_generator(int floorChosen, queue<Person> elevator_cart);
	
	

private:

	int id; // USER SPECIFIC. CREATES A USER TO PRESS ELEVATOR BUTTON
	clock_t arriveTime;//TIME USER IS CREATED
	clock_t departTime;//TIME USER GETS OFF THE ELEVATOR
	int userFloor;//FLOOR USER IS CURRENTLY ON
	int destination;//DESIRED FLOOR

	//VECTOR OF POSSIBLE FLOOR CHOICES NOT SURE IF I WILL USE THIS YET. SMALL ENOUGH POPULATION THAT I PREPOPULATED IT
	vector<int> floor1_options{ 2, 3 };
	vector<int> floor2_options{ 2, 3 };
	vector<int> floor3_options{ 1, 2 };
};
//DOORS WILL TAKE NEGLIGIBLE AMOUNT OF TIME TO OPEN. WILL NOT INCLUDE IN THE TIME. TIME STAYING OPEN WILL MATTER FOR HOW MANY PEOPLE IN LINE

#endif