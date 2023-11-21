#include "Patients.h"
#include <vector>

vector<pair<Time*, Patient*>> waitingRoom;
vector <Patient*> currentAppointments;
set<int> patientIds;

void Patients::deallocateMemory()
{
	while (waitingRoom.size() > 0) {
		delete waitingRoom[0].first;
		delete waitingRoom[0].second;
	}
	for (auto& p : currentAppointments) {
		delete p;
	}
}

bool compareTime(pair<Time*, Patient*> p1, pair<Time*, Patient*> p2) {
	return *p1.first < *p2.first;
}

void Patients::addToQueue(Patient* patient) {
	waitingRoom.push_back({ patient->getTime(), patient });
	sort(waitingRoom.begin(), waitingRoom.end(), compareTime);
	//showPatientInfo();
}

void Patients::showPatientInfo() {
	for (auto& p : waitingRoom) {
		p.second->printInfo();
	}
}

Patient* Patients::getFirstPatient() {
	Patient* p = waitingRoom[0].second;
	waitingRoom.erase(waitingRoom.begin());
	currentAppointments.push_back(p);
	return p;
}

bool Patients::isPatients() {
	if (waitingRoom.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}

