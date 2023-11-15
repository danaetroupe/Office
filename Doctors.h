#pragma once

#include <set>
#include <map>

#include "Doctor.h"

namespace Doctors
{
	int generateUniqueId();

	void addNewDoctor(Doctor*);
	void addNewDoctor(Doctor*, int id);
};

