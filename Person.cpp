#include "Person.h"
#include <iostream>

Person::Person(string name, string number, string email, Address* address, ErrorHandler* handler) {
	this->name = name;
	this->address = address;
	this->phoneNumber = number;
	this->email = email;
	id = 0;

	handler->checkName(name);
	handler->checkEmail(email);
	handler->checkAddress(address->address, address->zipCode);
	handler->checkNumber(number);

}

Person::~Person() {
	delete address;
	delete account;
}