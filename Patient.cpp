#include "Patient.h"

Patient::Patient(string name, string number, string email, string insurance, Address* address, Date* date, Time* arrivalTime, ErrorHandler* handler) : Person(name, number, email, address, handler) {
	this->arrivalTime = arrivalTime;
	this->birthDate = date;
	this->insurance = insurance;
}

Patient::Patient(vector<string> input, ErrorHandler* handler) {

}

Patient::~Patient() {
	delete address;
	delete birthDate;
}