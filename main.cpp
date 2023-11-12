#include "global.h"
#include "Patients.h"
#include "Doctors.h"
#include "FileHandler.h"
#include <iostream>
#include <map>


menuOptions showMenu();
void helpPrint(vector<string>, int);
void loadData();
void addNewPatient();
void addNewDoctor();

menuOptions showMenu() {
	std::cout << "==== MENU ====" << endl;
	vector<std::string> options = { "Load office data", "Add new patient", "Add new doctor", "Patient queue summary", "Doctor summary", "Checkout patient", "Close office" };
	std::string option = "";
	while (option == "") {
		for (int i = 0; i < options.size(); i++) {
			std::cout << i << ". " << options[i] << endl;
		}
		std::getline(std::cin, option);
		switch (stoi(option)) {
		case(0): 
			return load;
		case(1):
			return addPatient;
		case(2):
			return addDoctor;
		case(3):
			return patientSummary;
		case(4):
			return doctorSummary;
		case(5):
			return checkout;
		case(6):
			return close;
		default:
			std::cout << option << endl;
			option = "";
		}
	}
	return close;
}

void helpPrint(vector<string> v, int i) {
	if (i < v.size()) { std::cout << v[i] << endl; }
	else { std::cout << endl; }
}

void loadData() {
	std::cout << "== LOAD DATA ==" << endl;
	std::cout << "FILE NAME:" << endl;
	std::string f;
	std::getline(std::cin, f);
	ErrorHandler* handler = new ErrorHandler();
	FileHandler file(f, handler);
	if (handler->getErrorStatus()) {
		for (std::string display : handler->getErrorDisplays()) { std::cout << display << endl; }
	}
	else {
		int keepReading = true;
		int currentCategory = 0;
		while (keepReading) {
			vector<string> results = file.readFromFile(" ");
			if (results[0] == "Doctors") {
				results.erase(results.begin());
			}
			else if (results[0] == "Patients") {
				currentCategory = 1;
				results.erase(results.begin());
			}
			else if (results[0] == "Rooms") {
				currentCategory = 2;
				results.erase(results.begin());
			}

			int correct = false;
			while (!correct) {
			switch (currentCategory) {
			case(0):
				while (!correct) {
					std::cout << "DOCTOR" << endl;
					std::cout << "1) FIRST NAME: "; helpPrint(results, 0);
					std::cout << "2) LAST NAME: "; helpPrint(results, 1);
					std::cout << "3) ADDRESS: "; helpPrint(results, 2);
					std::cout << "4) CITY: "; helpPrint(results, 3);
					std::cout << "5) STATE: "; helpPrint(results, 4);
					std::cout << "6) ZIP: "; helpPrint(results, 5);
					std::cout << "7) PHONE: "; helpPrint(results, 6);
					std::cout << "8) EMAIL: "; helpPrint(results, 7);
					std::cout << "9) ID: "; helpPrint(results, 8);
					std::cout << "Correct information? (Type number 1-9 or 0 if CORRECT)" << endl;

					std::string input;
					std::getline(std::cin, input);
					if (input >= "0" || input <= "9") {
						std::string input2;
						cout << "Re-enter information..." << endl;
						std::getline(std::cin, input2);
						results[stoi(input)] = input2;
					}
					else { 
						correct = true; 
					}
				}
			case(1):
			case(2):
				keepReading = false;
			}
			}
		}
	}
	delete handler;
}

void addNewPatient() {
	std::cout << "== ADD NEW PATIENT ==" << endl;
	ErrorHandler* handler = new ErrorHandler();
	Patient* tempPatient = nullptr;
	while (tempPatient == nullptr) {
		std::string name, address, city, state, zip, phone, email, insurance, month, day, year;
		std::cout << "NAME: " << endl;
		std::getline(std::cin, name);
		std::cout << "ADDRESS: " << endl;
		std::getline(std::cin, address);
		std::cout << "CITY: " << endl;
		std::getline(std::cin, city);
		std::cout << "STATE: " << endl;
		std::getline(std::cin, state);
		std::cout << "ZIP CODE: " << endl;
		std::getline(std::cin, zip);
		std::cout << "PHONE NUMBER: " << endl;
		std::getline(std::cin, phone);
		std::cout << "EMAIL ADDRESS: " << endl;
		std::getline(std::cin, email);
		std::cout << "INSURANCE: " << endl;
		std::getline(std::cin, insurance);
		std::cout << "DATE OF BIRTH:" << endl;
		std::cout << "MONTH:" << endl;
		std::getline(std::cin, month);
		std::cout << "DAY:" << endl;
		std::getline(std::cin, day);
		std::cout << "YEAR:" << endl;
		std::getline(std::cin, year);

		Patient* tempPatient = new Patient(name, phone, email, insurance, new Address(address, city, state, zip), new Date(year, month, day), handler);
		if (handler->getErrorStatus()) {
			std::cout << "ERROR: ";
			for (std::string error : handler->getErrorDisplays()) {
				std::cout << error << " ";
			}
			std::cout << "RETRY? (Y/N)" << endl;
			delete tempPatient;
			tempPatient = nullptr;
			std::string retry;
			std::getline(std::cin, retry);
			if (retry == "N") { break; }
		}
		else {
			Patients::addToQueue(tempPatient);
			std::cout << "Patient added successufully." << endl;
		}
	}
	delete handler;
}

void addNewDoctor() {
	std::cout << "== ADD NEW DOCTOR ==" << endl;
	ErrorHandler* handler = new ErrorHandler();
	Doctor* tempDoctor = nullptr;
	while (tempDoctor == nullptr) {
		std::string name, address, city, state, zip, phone, email;
		std::cout << "NAME: " << endl;
		std::getline(std::cin, name);
		std::cout << "ADDRESS: " << endl;
		std::getline(std::cin, address);
		std::cout << "CITY: " << endl;
		std::getline(std::cin, city);
		std::cout << "STATE: " << endl;
		std::getline(std::cin, state);
		std::cout << "ZIP CODE: " << endl;
		std::getline(std::cin, zip);
		std::cout << "PHONE NUMBER: " << endl;
		std::getline(std::cin, phone);
		std::cout << "EMAIL ADDRESS: " << endl;
		std::getline(std::cin, email);

		Doctor* tempPatient = new Doctor(name, phone, email, new Address(address, city, state, zip), handler);
		if (handler->getErrorStatus()) {
			std::cout << "ERROR: ";
			for (std::string error : handler->getErrorDisplays()) {
				std::cout << error << " ";
				std::cout << name << endl;
			}
			std::cout << "RETRY? (Y/N)" << endl;
			delete tempDoctor;
			tempDoctor = nullptr;
			std::string retry;
			std::getline(std::cin, retry);
			if (retry == "N") { break; }
		}
		else {
			Doctors::addNewDoctor(tempDoctor);
			std::cout << "Doctor added successufully." << endl;
		}
	}
}

int main() {
	menuOptions choice = showMenu();
	switch (choice) {
	case(addPatient):
		addNewPatient();
		break;
	case(addDoctor):
		addNewDoctor();
		break;
	default:
		break;
	}
	Patients::deallocateMemory();
	return 1;
}

/*
ErrorHandler* handler = new ErrorHandler;
	Address* address = new Address("address", "city", "state", "zip");
	Date* date = new Date(5, 27, 2003);
	Patient* tempPatient = new Patient("name", "phone", "danaetroupe.gmail.com", "insurance", address, date, handler);
	if (handler->getErrorStatus()) {
		std::cout << "Error found";
		std::string wait;
		std::cin >> wait;
	}
	else {
		std::cout << "No error found.";
		std::string wait;
		std::cin >> wait;
	}
*/