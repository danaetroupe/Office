#pragma once
#include <string>

class Time {
	int hours, minutes, seconds;
public:
	Time(std::string timeValue);
	Time(std::string, std::string, std::string);

	bool operator>(const Time&);
	void showTime();
};