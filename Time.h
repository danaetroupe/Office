#pragma once
#include <string>

class Time {
	int hours, minutes, seconds;
	std::string value = NULL;
public:
	Time();
	Time(std::string timeValue);

	bool operator>(const Time&);
};