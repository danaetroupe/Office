#include "Appointments.h"

#include <queue>
#include <vector>
#include <iostream>
#include <set>
#include <map>

map <int, Appointment*> unassignedAppointments;
map <int, Appointment*> assignedAppointments;

void Appointments::addAppointment(Appointment* appointment) {
	unassignedAppointments[appointment->getRoomNumber()] = appointment;
}
int Appointments::getNumberOfAppointments() {
	return unassignedAppointments.size();
}
void Appointments::assignDoctor(Doctor* d, int roomNumber) {
	Appointment* app = unassignedAppointments[roomNumber];
	app->addDoctor(d);
	assignedAppointments[roomNumber] = app;
	unassignedAppointments.erase(roomNumber);
}

void Appointments::showAppointments() {
	std::cout << "=CURRENT APPOINTMENTS=" << std::endl;
	for (auto& appt : unassignedAppointments) {
		appt.second->showAppointmentInfo();
	}
	for (auto& appt : assignedAppointments) {
		appt.second->showAppointmentInfo();
	}
}

bool Appointments::isAssigned(int roomNumber) {
	if (assignedAppointments.count(roomNumber) > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Appointments::isUnassigned(int roomNumber) {
	if (unassignedAppointments.count(roomNumber) > 0) {
		return true;
	}
	else {
		return false;
	}
}

Appointment* Appointments::getAppointmentFromRoom(int roomNumber) {
	return assignedAppointments[roomNumber];
}

void Appointments::clearAppointment(Appointment* appointment) {
	assignedAppointments.erase(appointment->getRoomNumber());
	delete appointment;
}

void Appointments::clearMemory() {
	for (auto& appt : unassignedAppointments) {
		delete appt.second;
	}
	for (auto& appt : assignedAppointments) {
		appt.second->showAppointmentInfo();
	}
}