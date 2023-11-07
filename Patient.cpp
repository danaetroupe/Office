#include "Patient.h"

Patient::Patient(string name, string number, string email, string insurance, Address* address, Date* date, ErrorHandler* handler) : Person(name, number, email, address, handler) {
	this->birthDate = date;
	this->insurance = insurance;
}

Patient::~Patient() {
	delete address;
	delete birthDate;
}