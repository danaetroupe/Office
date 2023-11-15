#include "Patients.h"
#include <vector>

vector<pair<Time*, Patient*>> waitingRoom;
map<int, Patient*> currentAppointments;
set<int> patientIds;

void Patients::deallocateMemory()
{
	while (waitingRoom.size() > 0) {
		delete waitingRoom[0].first;
		delete waitingRoom[0].second;
		waitingRoom.erase(waitingRoom.begin());
	}
	for (auto& p : currentAppointments) {
		delete p.second;
		currentAppointments.erase(p.first);
	}
}

void Patients::addToQueue(Patient* patient) {
	waitingRoom.push_back({ patient->getTime(), patient });
	sort(waitingRoom.begin(), waitingRoom.end());
}
