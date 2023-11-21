#pragma once
#include "Appointment.h"
namespace Appointments
{
	void addAppointment(Appointment*);
	int getNumberOfAppointments();
	void assignDoctor(Doctor*, int);
	void showAppointments();

	bool isAssigned(int);
	bool isUnassigned(int);
	Appointment* getAppointmentFromRoom(int);
	void clearAppointment(Appointment*);

	void clearMemory();
};


