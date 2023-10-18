#pragma once
#include "Person.h"

class Doctor : Person
{
public:
	Doctor(string, string, string, string, int, int, string);
	float getBalance();
};

