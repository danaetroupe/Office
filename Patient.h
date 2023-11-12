#pragma once
#include "Person.h"
#include "Time.h"
struct Date {
	string year, month, day;
	Date(string year, string month, string day) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
};

class Patient : public Person
{
	Date* birthDate;
	string insurance;
	Time* arrivalTime;
public:
	Patient(string, string, string, string, Address*, Date*, ErrorHandler* = nullptr);
	Patient(vector<string>, ErrorHandler*);
	~Patient();

	string getDateOfBirth() { return birthDate->month + "/" + birthDate->day + "/" + birthDate->year; }
	string getInsurance() { return insurance; }

	void setDateOfBirth(string year, string month, string day) {
		delete birthDate;
		birthDate = new Date(year, month, day);
	}
	void setInsurance(string insurance) { this->insurance = insurance; }
};

