#include "Doctor.h"
#include <iostream>
#include <iomanip>
Doctor::Doctor(string name, string number, string email, Address* address, ErrorHandler* handler) : Person(name, number, email, address, handler) {

}

void Doctor::showInfo() {
	std::cout << this->id << " | " << this->name << endl;
}

