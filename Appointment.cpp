#include "Appointment.h"
#include <iostream>

void Appointment::showAppointmentInfo() {
	std::cout << "\nROOM #: " << roomNumber << "\nDOCTOR: " << ((doctor == NULL) ? "NO DOCTOR ASSIGNED" : doctor->getName()) << "; PATIENT: " << patient->getName() 
		<< "\nVISIT REASON: " << visitReason << endl;
}

Appointment::~Appointment() {
	delete patient;
}