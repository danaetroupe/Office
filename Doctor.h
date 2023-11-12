#pragma once
#include "Person.h"

class Doctor : Person
{
public:
	Doctor(string, string, string, Address*, ErrorHandler*);
	Doctor(vector<string>, ErrorHandler*);
	float getBalance();
};

