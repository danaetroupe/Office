#pragma once

#include <set>
#include <map>
using namespace std;

#include "Doctor.h"

class Doctors
{
	set<int> doctorIds;
	map<int, Doctor*> avaliableDoctors;
	map<int, Doctor*> unavaliableDoctors;
public:
	Doctors();
	~Doctors();
	
	void addNewDoctor(string, string, string, string, int, int, string);
};

