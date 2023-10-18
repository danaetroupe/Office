#pragma once

#include <queue>
#include <map>
#include <set>
using namespace std;

#include "Patient.h"

class Patients
{
	queue<Patient*> waitingRoom;
	map<int, Patient*> currentAppointments;
	set<int> patientIds;
public:
	int generateUniqueId();
	Patient* getFirstPatient();
	vector<Patient*> showCurrentAppointments();
	
	void addToQueue(Patient*);
	void removePatientFromQueue();
};

