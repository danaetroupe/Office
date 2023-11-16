#pragma once
#include <string>
using namespace std;

#include "Patient.h"
#include "Doctor.h"

class Appointment {
	Patient* patient;
	Doctor* doctor;
	int roomNumber;
	string visitReason;

public:
	Appointment(Patient* p, Doctor* d, int roomNumber, string visitReason) : patient(p), doctor(d), roomNumber(roomNumber), visitReason(visitReason) {};

	int getRoomNumber() { return roomNumber; }
	string getVisitReason() { return visitReason; }

	void setRoomNumber(int room) { this->roomNumber = room; }
	void setVisitReason(string reason) { this->visitReason = reason; }

};