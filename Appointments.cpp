#include "Appointments.h"
#include <queue>
#include <vector>
#include <iostream>

vector <Appointment*> unassignedAppointments;
vector <Appointment*> assignedAppointments;

void Appointments::addAppointment(Appointment* appointment) {
	unassignedAppointments.push_back(appointment);
}
int Appointments::getNumberOfAppointments() {
	return unassignedAppointments.size();
}
void Appointments::assignDoctor(Doctor* d) {
	Appointment* app = unassignedAppointments[0];
	app->addDoctor(d);
	assignedAppointments.push_back(app);
	unassignedAppointments.erase(unassignedAppointments.begin());
}

void Appointments::showAppointments() {
	std::cout << "\n=CURRENT APPOINTMENTS=" << std::endl;
	for (auto& appt : unassignedAppointments) {
		appt->showAppointmentInfo();
	}
	for (auto& appt : assignedAppointments) {
		appt->showAppointmentInfo();
	}
}