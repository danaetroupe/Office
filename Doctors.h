#pragma once

#include <set>
#include <map>

#include "Doctor.h"

namespace Doctors
{
	void addNewDoctor(Doctor*);
	void addNewDoctor(Doctor*, int id);
	void showInfo();

	int getNumberOfDoctors();
	bool isDoctorAvaliable(int id);
	Doctor* getAvaliableDoctorById(int id);
	void deallocateMemory();
	vector<Doctor*> getAllDoctors();
};

