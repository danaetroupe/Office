#include "Patients.h"
//using namespace Patients;

queue<Patient*> waitingRoom;
map<int, Patient*> currentAppointments;
set<int> patientIds;

void Patients::deallocateMemory()
{
	while (waitingRoom.size() > 0) {
		delete waitingRoom.front();
		waitingRoom.pop();
	}
	for (auto& p : currentAppointments) {
		delete p.second;
		currentAppointments.erase(p.first);
	}
}

void Patients::addToQueue(Patient* patient) {
	waitingRoom.push(patient);
}
