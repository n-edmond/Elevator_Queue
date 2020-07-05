#ifndef PERSON
#define PERSON

#include <queue>
#include <time.h>
#include <vector>
//#include "Elevator_Class.h"

using namespace std;
class Person
{
public:
	Person(int counter);
	int get_rand_floor_generator(int floorCurrOn);//RANDOMIZES THE FLOOR BASED ON THE FLOOR THE USER IS CURRENTLY ON. FLOOR DEST ON ELEVATOR CLASS
//	void set_rand_floor_generator(int userF);//SETTER FOR RAND FLOOR GEN. USED ELSEWHERE 
	int getFloor();
	void setDepartTime();
	void delay(int number_of_seconds);//SIMULATES A DELAY FOR THE ELEVATOR. 
	clock_t getTime();
//	void get_in_elevator(int currFloor, int secDelay);//GENERATES THE LINE FORMED OUTSIDE THE ELEVATOR. ASSUME THAT THE NUMBERS ARE THE FLOORS USER WANTS TO GO TO. ASSUME BUTTON IS PUSHED
	//WHEN THEY GET IN ELEVATOR. FLOOR DESTINATION DECIDED TO INDICATE POSITON WHEN ARRIVED.
//	void queue_generator(int floorChosen, queue<Person> elevator_cart);
	
	

private:
/*
	//PEOPLE WAITING TO GET IN LINE FOR THE ELEVATOR. NOT THE PEOPLE IN THE ELEVATOR. LINE WILL NOT CONTAIN MORE THAN 20 PEOPLE, BEFORE PPL TAKE STAIRS
	queue<int> floor_1_queue;
	queue<int> floor_2_queue;
	queue<int> floor_3_queue;

	//VECTOR OF POSSIBLE FLOOR CHOICES NOT SURE IF I WILL USE THIS YET. SMALL ENOUGH POPULATION THAT I PREPOPULATED IT
	vector<int> floor1_options{ 2, 3 };
	vector<int> floor2_options{ 2, 3 };
	vector<int> floor3_options{ 1, 2 };
*/
	//USER FLOOR DESTINATION. FLOOR IS RANDOMIZED.
	int id;
	clock_t arriveTime;
	clock_t departTime;
	int userFloor;
	int destination;

};
//DOORS WILL TAKE NEGLIGIBLE AMOUNT OF TIME TO OPEN. WILL NOT INCLUDE IN THE TIME. TIME STAYING OPEN WILL MATTER FOR HOW MANY PEOPLE IN LINE

#endif