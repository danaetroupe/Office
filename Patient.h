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
	Date(string dateValue) {
		this->month = stoi(dateValue.substr(0, 2));
		this->day = stoi(dateValue.substr(3, 2));
		this->year = stoi(dateValue.substr(6, 4));
	}
};

class Patient : public Person
{
	Date* birthDate;
	string insurance;
	Time* arrivalTime;
public:
	Patient(string, string, string, string, Address*, Date*, Time*, ErrorHandler* = nullptr);
	~Patient();

	string getDateOfBirth() { return birthDate->month + "/" + birthDate->day + "/" + birthDate->year; }
	string getInsurance() { return insurance; }
	Time* getTime() { return arrivalTime; }

	void setDateOfBirth(string year, string month, string day) {
		delete birthDate;
		birthDate = new Date(year, month, day);
	}
	void setInsurance(string insurance) { this->insurance = insurance; }
};

