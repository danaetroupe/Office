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
void Appointments::assignDoctor(Doctor* d) {
	Appointment* app = unassignedAppointments[0];
	int index = app->getRoomNumber();
	app->addDoctor(d);
	assignedAppointments[index] = app;
	unassignedAppointments.erase(index);
}

void Appointments::showAppointments() {
	std::cout << "\n=CURRENT APPOINTMENTS=" << std::endl;
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