#ifndef FLOOR
#define FLOOR

#include "Person_Class.h"
#include "Elevator_Class.h"

using namespace std;

class Floor 
{
public:
	int riderID(); //icrements counter each time it is called and returns updated count
	void get_in_elevator(int currFloor, int secDelay, Elevator e_cart);//GENERATES THE LINE FORMED OUTSIDE THE ELEVATOR. ASSUME THAT THE NUMBERS ARE THE FLOORS USER WANTS TO GO TO. ASSUME BUTTON IS PUSHED
	//WHEN THEY GET IN ELEVATOR. FLOOR DESTINATION DECIDED TO INDICATE POSITON WHEN ARRIVED.
	void queue_generator(int floorChosen, Elevator elevator_cart);
	
private:
	int riderCounter = 0;
	//PEOPLE WAITING TO GET IN LINE FOR THE ELEVATOR. NOT THE PEOPLE IN THE ELEVATOR. LINE WILL NOT CONTAIN MORE THAN 20 PEOPLE, BEFORE PPL TAKE STAIRS
	queue<Person> floor_1_queue;
	queue<Person> floor_2_queue;
	queue<Person> floor_3_queue;

	//VECTOR OF POSSIBLE FLOOR CHOICES NOT SURE IF I WILL USE THIS YET. SMALL ENOUGH POPULATION THAT I PREPOPULATED IT
	vector<int> floor1_options{ 2, 3 };
	vector<int> floor2_options{ 2, 3 };
	vector<int> floor3_options{ 1, 2 };
};

#endif