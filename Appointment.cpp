#include "Appointment.h"
#include <iostream>

void Appointment::showAppointmentInfo() {
	std::cout << "DOCTOR: " << ((doctor == NULL) ? "NO DOCTOR ASSIGNED" : doctor->getName()) << "; PATIENT: " << patient->getName() << "; ROOM #: " << roomNumber << endl;
}