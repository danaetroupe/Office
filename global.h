#pragma once
#include <string>
#include <iostream>

extern enum menuOptions { load, addPatient, addDoctor, patientSummary, doctorSummary, checkout, close };
extern std::string const OFFICE_HISTORY = "OfficeHistory.txt";
extern void printSeperator() {
	std::cout << "_____________________________________________________" << std::endl;
}
