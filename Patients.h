#pragma once

#include <queue>
#include <map>
#include <set>
using namespace std;

#include "Patient.h"

namespace Patients
{
	/*extern queue<Patient*> waitingRoom;
	extern map<int, Patient*> currentAppointments;
	extern set<int> patientIds;*/

	int generateUniqueId();
	Patient* getFirstPatient();
	vector<Patient*> showCurrentAppointments();
	
	void addToQueue(Patient*);
	void removePatientFromQueue();
	void showPatientInfo();

	void deallocateMemory();
};

