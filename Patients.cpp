#include "Patients.h"
#include <vector>

vector<pair<Time*, Patient*>> waitingRoom;
vector <Patient*> currentAppointments;
set<int> patientIds;
int seenPatients = 0;

void Patients::deallocateMemory()
{
	for (auto& pair : waitingRoom) {
		delete pair.second;
	}
	for (Patient* p : currentAppointments) {
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

void Patients::checkoutPatient() {
	seenPatients += 1;
}

int Patients::getSeenPatients() {
	return seenPatients;
}