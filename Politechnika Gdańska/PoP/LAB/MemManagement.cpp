#include <iostream>
using namespace std;

//struktury
struct ship {
	char name[25];
	int crew;
};
typedef struct ship ship;
struct person {
	int id;
	ship* ship;
};
typedef struct person person;


//nowy statek
void newship(ship** currentship) {
	if((*currentship)->crew == 0) {
		free(currentship);
	}
	ship* newship = (ship*)malloc(sizeof(ship));
	cin >> newship->name;
	newship->crew = 0;
	*currentship = newship;
}

//find index of person with given id
int findidx(person* people, int id, int size) {
	for(int i = 0; i < size; i++) {
		if(people[i].id == id) {
			return i;
		}
	}
	return -1;
}

//wsiadanie na statek
int board(person* people, ship* currentship, int size) {
	int id;
	cin >> id;
	if(people[findidx(people, id, size)].ship != NULL) {
		people[findidx(people, id, size)].ship->crew--;
	}
	people[findidx(people, id, size)].ship = currentship;
	currentship->crew++;
	return 0;
}

//wypisanie logu ludzi na statkach
void print(person* people, int size) {
	cout << "Log:" << endl;
	for(int i = 0; i < size; i++){
		if(people[i].ship != NULL){
			cout << "Person " << people[i].id << ":	" << people[i].ship->name << ", crew: " << people[i].ship->crew << endl;
		}
		else {
			cout << "Person " << people[i].id << ":	" << "-" << endl;
		}
	}
}

//zwolnienie pamieci
void free(person* people, ship* currentship) {
	free(people);
	free(currentship);
}


int main() {
	int size;
	cin >> size;
	person* people = (person*)malloc(sizeof(person)*size);
	//wczytanie ludzi
	for(int i = 0; i < size; i++) {
		int id;
		cin >> id;
		people[i].id = id;
		people[i].ship = NULL;
	}
	ship* currentship = (ship*)malloc(sizeof(ship));
	currentship->crew = -1;
	char input = ' '; 
	while(input != 'Q'){
		cin >> input;
		switch(input) {
			case 'D':
				newship(&currentship);
				break;
			case 'B':
				board(people, currentship, size);
				break;
			case 'P':
				print(people, size);
				break;
			case 'Q':
				free(people, currentship);
				break;
		}
	}
	return 0;
}
