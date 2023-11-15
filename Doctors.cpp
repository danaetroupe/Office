#include "Doctors.h"
#include <random>

set<int> doctorIds;
map<int, Doctor*> avaliableDoctors;
map<int, Doctor*> unavaliableDoctors;


void Doctors::addNewDoctor(Doctor* doctor) {
	int id;
	do {
		id = rand() % 50000;
	} while (doctorIds.count(id) > 0);
	doctorIds.insert(id);
	avaliableDoctors.insert(pair<int, Doctor*>(id, doctor));
}

void Doctors::addNewDoctor(Doctor* doctor, int id) {
	while (doctorIds.count(id) > 0) {
		id = rand() % 50000;
	} 
	doctorIds.insert(id);
	avaliableDoctors.insert(pair<int, Doctor*>(id, doctor));
}