#pragma once
#include "Person.h"
struct Date {
	int year, month, day;
};

class Patient : Person
{
	Date birthDate;
	string insurance;
public:
	Patient(string, string, string, string, int, int, string);
	~Patient();
};

