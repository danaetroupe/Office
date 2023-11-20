#pragma once
#include "Appointment.h"
namespace Appointments
{
	void addAppointment(Appointment*);
	int getNumberOfAppointments();
	void assignDoctor(Doctor*);
	void showAppointments();

	bool isAssigned(int);
	Appointment* getAppointmentFromRoom(int);
	void clearAppointment(Appointment*);

	void clearMemory();
};


