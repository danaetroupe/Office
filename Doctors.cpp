#include "Doctors.h"
#include <random>
#include <iostream>

set<int> doctorIds;
map<int,Doctor*> avaliableDoctors;
map<int,Doctor*> unavaliableDoctors;


void Doctors::addNewDoctor(Doctor* doctor) {
	int id;
	do {
		id = rand() % 50000;
	} while (doctorIds.count(id) > 0);
	doctorIds.insert(id);
	avaliableDoctors[doctor->getId()] = doctor;
}

void Doctors::addNewDoctor(Doctor* doctor, int id) {
	while (doctorIds.count(id) > 0) {
		id = rand() % 50000;
	} 
	doctor->assignId(id);
	doctorIds.insert(id);
	avaliableDoctors[doctor->getId()] = doctor;
}

void Doctors::showInfo() {
	if (avaliableDoctors.size() > 0) {
		std::cout << "=OPEN DOCTORS=" << endl;
		for (auto& p : avaliableDoctors) {
			p.second->showInfo();
		}
	}
	else {
		cout << "NO AVALIABLE DOCTORS." << endl;
	}
	if (unavaliableDoctors.size() > 0) {
		std::cout << "=BUSY DOCTORS=" << endl;
		for (auto& p : unavaliableDoctors) {
			p.second->showInfo();
		}
	}
	else { cout << "NO DOCTORS CURRENTLY SEEING PATIENTS." << endl; }
	
}

int Doctors::getNumberOfDoctors() {
	return avaliableDoctors.size();
}

bool Doctors::isDoctorAvaliable(int id) {
	if (avaliableDoctors.count(id) > 0) { return true; }
	else { return false; }
}

Doctor* Doctors::getAvaliableDoctorById(int id) {
	Doctor* d;
	if (Doctors::isDoctorAvaliable(id)) { d = avaliableDoctors[id]; avaliableDoctors.erase(id); }
	else { d = nullptr; }
	return d;
}