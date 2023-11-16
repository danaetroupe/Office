#pragma once
#include <string>
using namespace std;

#include "Account.h"
#include "ErrorHandler.h"

struct Address {
	string address, city, state, zipCode;
	Address(string address, string city, string state, string zip) {
		this->address = address;
		this->city = city;
		this->state = state;
		this->zipCode = zip;
	}
};

class Person
{
protected:
	Address* address;
	string name, email, phoneNumber;
	int id = NULL;

	Account* account;
public:
	Person(string, string, string, Address*, ErrorHandler*);
	~Person();

	string getName() { return name; }
	string getAddress() { return address->address; }
	string getCity() { return address->city; }
	string getState() { return address->state; }
	string getZipCode() { return address->zipCode; }
	string getPhoneNumber() { return phoneNumber; }
	string getEmail() { return email; }

	void setName(string name) { this->name = name; }
	void setAddress(string address, string city, string state, string zip) {
		delete this->address;
		this->address = new Address(address, city, state, zip);
	}
	void setPhoneNumber(string number) { this->phoneNumber = number; }
	void setEmail(string email) { this->email = email; }
	void assignId(int id);
};

