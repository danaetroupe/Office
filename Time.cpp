#include "Time.h"
#include <chrono>

Time::Time() {

}

Time::Time(std::string value) : value(value) {
	this->hours = std::stoi(value.substr(0, 2));
	this->minutes = std::stoi(value.substr(3, 2));
	this->seconds = std::stoi(value.substr(6, 2));
	if (value.substr(9, 2) == "pm") {
		this->hours += 12;
	}
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