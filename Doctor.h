#pragma once
#include "Person.h"

class Doctor : public Person
{
public:
	Doctor(string, string, string, Address*, ErrorHandler*);
	
	void showInfo();
};

