#pragma once
#include <string>
using namespace std;

#include "Patient.h"
#include "Doctor.h"

class Appointment {
public:
	enum visitType { preventative, sick };
private:
	Patient* patient;
	Doctor* doctor = NULL;
	int roomNumber;
	string visitReason;
	visitType type;

public:
	Appointment(Patient* p, int roomNumber, string visitReason, visitType type) : patient(p), roomNumber(roomNumber), visitReason(visitReason), type(type) {};

	void addDoctor(Doctor* doctor) { this->doctor = doctor; }
	void setRoomNumber(int room) { this->roomNumber = room; }
	void setVisitReason(string reason) { this->visitReason = reason; }

	int getRoomNumber() { return roomNumber; }
	string getVisitReason() { return visitReason; }
	Doctor* getDoctor() { return doctor; }
	Patient* getPatient() { return patient; }

	void showAppointmentInfo();
};