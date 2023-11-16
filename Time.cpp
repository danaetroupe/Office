#include "Time.h"
#include <iostream>

Time::Time(std::string value) : value(value) {
	this->hours = std::stoi(value.substr(0, 2));
	this->minutes = std::stoi(value.substr(3, 2));
	this->seconds = std::stoi(value.substr(6, 2));
	if (value.substr(9, 2) == "pm") {
		this->hours += 12;
	}
}

Time::Time(std::string hour, std::string minutes, std::string seconds) {
	this->hours = std::stoi(hour);
	if (this->hours >= 24) { this->hours = 0; }
	this->minutes = std::stoi(minutes);
	if (this->minutes >= 60) { this->minutes = 0; }
	this->seconds = std::stoi(seconds);
	if (this->seconds >= 60) { this->seconds = 0; }
}

bool Time::operator>(const Time& t) {
	if (this->hours > t.hours) {
		return true;
	}
	else if (this->hours == t.hours) {
		if (this->minutes > t.minutes) { return true; }
		else if (this->minutes == t.minutes) {
			if (this->seconds > t.seconds) { return true; }
			else { return false; }
		}
		else { return false; }
	}
	else {
		return false;
	}
}

void Time::showTime() {
	std::cout << this->hours << ":" << this->minutes << ":" << this->seconds;
}