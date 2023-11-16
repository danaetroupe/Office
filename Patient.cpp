#include "Patient.h"
#include <iomanip>
#include <iostream>


Patient::Patient(string name, string number, string email, string insurance, Address* address, Date* date, Time* arrivalTime, ErrorHandler* handler) : Person(name, number, email, address, handler) {
	this->arrivalTime = arrivalTime;
	this->birthDate = date;
	this->insurance = insurance;
}


Patient::~Patient() {
	delete birthDate;
	delete arrivalTime;
}

void Patient::printInfo() {
	std::cout << this->name << std::setw(5);
	this->arrivalTime->showTime();
	std::cout << std::endl;
}