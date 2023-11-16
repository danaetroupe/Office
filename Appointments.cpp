#include "Appointments.h"
#include <queue>
#include <vector>

queue <Appointment*> unassignedAppointments;
vector <Appointment*> assignedAppointments;

void Appointments::addAppointment(Appointment* appointment) {
	unassignedAppointments.push(appointment);
}
int Appointments::getNumberOfAppointments() {
	return unassignedAppointments.size();
}
void Appointments::assignDoctor(Doctor* d) {
	Appointment* app = unassignedAppointments.front();
	app->addDoctor(d);
	assignedAppointments.push_back(app);
	unassignedAppointments.pop();
}