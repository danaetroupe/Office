#pragma once
#include "Person.h"
struct Date {
	int year, month, day;
	Date(int year, int month, int day) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
};

class Patient : public Person
{
	Date* birthDate;
	string insurance;
public:
	Patient(string, string, string, string, Address*, Date*, ErrorHandler* = nullptr);
	~Patient();

	string getDateOfBirth() { return to_string(birthDate->month) + "/" + to_string(birthDate->day) + "/" + to_string(birthDate->year); }
	string getInsurance() { return insurance; }

	void setDateOfBirth(int year, int month, int day) {
		delete birthDate;
		birthDate = new Date(year, month, day);
	}
	void setInsurance(string insurance) { this->insurance = insurance; }
};

