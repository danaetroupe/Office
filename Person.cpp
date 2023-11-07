#include "Person.h"
#include <iostream>

Person::Person(string name, string number, string email, Address* address, ErrorHandler* handler) {
	this->name = name;
	this->address = address;
	this->phoneNumber = number;
	this->email = email;

	if (!regex_match(name, regex("[a-zA-Z]+"))) {
		handler->addErrorCode(handler->ERROR_NAME_INVALID);
	}
	if (!regex_match(address->address, regex("[0-9][0-9]*[a-zA-Z]")) || !regex_match(address->zipCode, regex("[0-9]+"))) {
		handler->addErrorCode(handler->ERROR_ADDRESS_INVALID);
	}
	if (!regex_match(email, regex("[a-zA-Z0-9_]+@[a-zA-Z]+.[a-ZA-Z]+"))) {
		handler->addErrorCode(handler->ERROR_EMAIL_INVALID);
	}
	if (!regex_match(phoneNumber, regex("[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]"))) {
		handler->addErrorCode(handler->ERROR_PHONE_INVALID);
	}
}

Person::~Person() {
	delete address;
}