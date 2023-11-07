#pragma once
#include <string>
using namespace std;

#include "Patient.h"
#include "Doctor.h"

class Appointment {
	Patient* patient;
	Doctor* doctor;
	int roomNumber;
	int time;
	string visitReason;

public:
	Appointment(Patient* p, Doctor* d) : patient(p), doctor(d) {};

	int getRoomNumber() { return roomNumber; }
	int getTime() { return time; }
	string getVisitReason() { return visitReason; }

	void setRoomNumber(int room) { this->roomNumber = room; }
	void setTime(int time) { this->time = time; }
	void setVisitReason(string reason) { this->visitReason = reason; }

};