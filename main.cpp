#include "global.h"
#include "Patients.h"
#include "Doctors.h"
#include "FileHandler.h"
#include "Rooms.h"
#include "Appointments.h"

#include<windows.h>  


menuOptions showMenu();
void helpPrint(vector<string>, int);
void loadData();
void addNewPatient();
void addNewDoctor();
void showPatientSummary();
void showDoctorSummary();
void checkoutPatient();
void closeOffice();

int main() {
	bool mainLoop = true;
	cout << "WELCOME TO OFFICE MANAGER PROGRAM!" << endl;
	while (mainLoop) {
		menuOptions choice = showMenu();
		switch (choice) {
		case(addPatient):
			addNewPatient();
			break;
		case(addDoctor):
			addNewDoctor();
			break;
		case(load):
			loadData();
			break;
		case(patientSummary):
			showPatientSummary();
			break;
		case(doctorSummary):
			showDoctorSummary();
			break;
		case(checkout):
			checkoutPatient();
			break;
		case(close):
			mainLoop = false;
			closeOffice();
			break;
		default:
			break;
		}
	}
	Patients::deallocateMemory();
	Appointments::clearMemory();
	return 1;
}

menuOptions showMenu() {
	std::cout << "\n==== MENU ====" << endl;
	vector<std::string> options = { "Load office data", "Add new patient", "Add new doctor", "Patient queue summary", "Doctor summary", "Checkout patient", "Close office" };
	std::string option = "";
	while (option == "") {
		printSeperator();
		for (int i = 0; i < options.size(); i++) {
			std::cout << i << ". " << options[i] << endl;
		}
		printSeperator();
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
	std::cout << "\n== LOAD DATA ==" << endl;
	std::cout << "FILE NAME:" << endl;
	std::string f;
	std::getline(std::cin, f);
	ErrorHandler* handler = new ErrorHandler();
	FileHandler file(f, handler);
	if (handler->getErrorStatus()) {
		for (std::string display : handler->getErrorDisplays()) { std::cout << display << endl; }
		delete handler;
	}
	else {
		int keepReading = true;
		int currentCategory = 0;
		while (keepReading) {
			vector<string> results = file.readFromFile("");
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
			switch (currentCategory) {
			// ADD DOCTOR
			case(0):
				results.resize(9);
				while (!correct) {
					printSeperator();
					std::cout << "DOCTOR" << endl;
					printSeperator();
					std::cout << "0) FIRST NAME: "; helpPrint(results, 0);
					std::cout << "1) LAST NAME: "; helpPrint(results, 1);
					std::cout << "2) ADDRESS: "; helpPrint(results, 2);
					std::cout << "3) CITY: "; helpPrint(results, 3);
					std::cout << "4) STATE: "; helpPrint(results, 4);
					std::cout << "5) ZIP: "; helpPrint(results, 5);
					std::cout << "6) PHONE: "; helpPrint(results, 6);
					std::cout << "7) EMAIL: "; helpPrint(results, 7);
					std::cout << "8) ID: "; helpPrint(results, 8);
					printSeperator();
					std::cout << "Correct information? (Type number 0-8 or DONE if correct)" << endl;

					std::string input;
					std::getline(std::cin, input);
					if (input[0] <= '8' && input[0] >= '0') {
						std::string input2;
						cout << "Re-enter information..." << endl;
						std::getline(std::cin, input2);
						results[stoi(input)] = input2;
					}
					else { 
						correct = true; 
					}
					ErrorHandler* handler = new ErrorHandler;
					string name = results[0] + " " + results[1];
					string email = results[7];
					string phone = results[6];
					Doctor* doctor = new Doctor(name, phone, email, new Address(results[2], results[3], results[4], results[5]), handler);
					printSeperator();
					if (handler->getErrorStatus()) { 
						delete doctor; 
						cout << "DOCTOR UNSUCESSFULLY ADDED";
						for (string error : handler->getErrorDisplays()) {
							cout << error;
						}
						cout << endl;
					}
					else { 
						if (results[8] == "") { results[8] = "0"; }
						Doctors::addNewDoctor(doctor, stoi(results[8]));
						cout << "DOCTOR SUCCESSFULLY ADDED" << endl;
					}
					delete handler;
				}
				break;
			// ADD PATIENT
			case(1):
				results.resize(12);
				while (!correct) {
					printSeperator();
					std::cout << "PATIENT" << endl;
					printSeperator();
					std::cout << "0) ARRIVAL TIME: "; helpPrint(results, 0);
					std::cout << "1) FIRST NAME: "; helpPrint(results, 1);
					std::cout << "2) LAST NAME: "; helpPrint(results, 2);
					std::cout << "3) ADDRESS: "; helpPrint(results, 3);
					std::cout << "4) CITY: "; helpPrint(results, 4);
					std::cout << "5) STATE: "; helpPrint(results, 5);
					std::cout << "6) ZIP: "; helpPrint(results, 6);
					std::cout << "7) PHONE: "; helpPrint(results, 7);
					std::cout << "8) EMAIL: "; helpPrint(results, 8);
					std::cout << "9) DOB: "; helpPrint(results, 9);
					std::cout << "10) INSURANCE: "; helpPrint(results, 10);
					std::cout << "11) ID: "; helpPrint(results, 11);
					printSeperator();
					std::cout << "Correct information? (Type number 0-11 or DONE if correct)" << endl;

					std::string input;
					std::getline(std::cin, input);
					if (input[0] <= '9' && input[0] >= '0') {
						std::string input2;
						cout << "Re-enter information..." << endl;
						std::getline(std::cin, input2);
						results[stoi(input)] = input2;
					}
					else {
						correct = true;
					}
					ErrorHandler* handler = new ErrorHandler;
					string name = results[1] + " " + results[2];
					string email = results[8];
					string phone = results[7];
					string insurance = results[10];
					Patient* patient = new Patient(name, phone, email, insurance, new Address(results[3], results[4], results[5], results[6]), new Date(results[9]), new Time(results[0]), handler);
					printSeperator();
					if (handler->getErrorStatus()) { 
						delete patient; 
						cout << "PATIENT UNSUCESSFULLY ADDED";
						for (string error : handler->getErrorDisplays()) {
							cout << error << ";";
						}
						cout << endl;
					}
					else {
						Patients::addToQueue(patient);
						cout << "PATIENT SUCCESFULLY ADDED" << endl;
					}
					delete handler;
				}
				break;
			// ADD ROOMS
			case(2):
				keepReading = false;
				printSeperator();
				cout << "ROOMS" << endl;
				printSeperator();
				for (string result : results) {
					cout << "ROOM#: " << result << endl;
					Rooms::addNewRoom(stoi(result));
				}
				printSeperator();
				cout << "ROOMS SUCCESSFULLY ADDED" << endl;
				break;
			default:
				cout << "Not recognized" << endl;
				break;
			}
		}
	}
}

void addNewPatient() {
	std::cout << "\n== ADD NEW PATIENT ==" << endl;
	ErrorHandler* handler = new ErrorHandler();
	Patient* tempPatient = nullptr;
	while (tempPatient == nullptr) {
		std::string name, address, city, state, zip, phone, email, insurance, month, day, year, hour, minute, second;
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
		std::cout << "INSURANCE(OR NA IF NONE): " << endl;
		std::getline(std::cin, insurance);
		std::cout << "DATE OF BIRTH(MONTH):" << endl;
		std::getline(std::cin, month);
		std::cout << "DAY:" << endl;
		std::getline(std::cin, day);
		std::cout << "YEAR:" << endl;
		std::getline(std::cin, year);
		std::cout << "ARRIVAL TIME (HOUR):" << endl;
		std::getline(std::cin, hour);
		std::cout << "ARRIVAL TIME (MINUTE):" << endl;
		std::getline(std::cin, minute);
		std::cout << "ARRIVAL TIME (SECOND):" << endl;
		std::getline(std::cin, second);

		Patient* tempPatient = new Patient(name, phone, email, insurance, new Address(address, city, state, zip), new Date(year, month, day), new Time(hour, minute, second), handler);
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
			handler->clearErrorCodes();
			if (retry == "N") { break; }
		}
		else {
			Patients::addToQueue(tempPatient);
			std::cout << "Patient added successufully." << endl;
			break;
		}
	}
	delete handler;
}

void addNewDoctor() {
	std::cout << "\n== ADD NEW DOCTOR ==" << endl;
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

		tempDoctor = new Doctor(name, phone, email, new Address(address, city, state, zip), handler);
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
			handler->clearErrorCodes();
			if (retry == "N") { break; }
		}
		else {
			Doctors::addNewDoctor(tempDoctor);
			std::cout << "Doctor added successufully." << endl;
			break;
		}
	}
}

void showPatientSummary() {
	bool quit = false;
	while(!quit) {
		printSeperator();
		std::cout << "\n== PATIENT SUMMARY ==" << std::endl;
		if (Patients::isPatients()) {
			Patients::showPatientInfo();
		}
		else {
			std::cout << "NO AVALIABLE PATIENTS" << endl;
			quit = true;
			break;
		}
		printSeperator();
		cout << "\nDo you want to assign a patient? (Y/N)" << endl;
		string input;
		getline(cin, input);
		if (input == "Y") {
			if (Rooms::isEmptyRooms()) {
				printSeperator();
				Rooms::showRooms();
				printSeperator();
				cout << "\nEnter a room number:" << endl;
				getline(cin, input);
				int num = stoi(input);
				if (Rooms::occupyRoom(num)) {
					string type;
					cout << "Sick Visit? (Y/N)" << endl;
					getline(cin, type);
					string reason;
					if (type == "Y") {
						cout << "What is the visit reason?" << endl;
						getline(cin, reason);
					}
					else {
						reason = "Well Visit";
					}
					Appointments::addAppointment(new Appointment(Patients::getFirstPatient(), num, reason, (type == "Y") ? Appointment::sick : Appointment::preventative));
				}
				else {
					cout << "ROOM NUMBER NOT VALID." << endl;
					quit = true;
				}
			}
			else {
				std::cout << "NO AVALIABLE ROOMS" << endl;
				quit = true;
				break;
			}
		}
		else {
			quit = true;
		}
		
	}
	
}

void showDoctorSummary() {
	cout << "\n== DOCTOR SUMMARY ==" << endl;
	int apts = Appointments::getNumberOfAppointments();
	//cout << "OPEN APPOINTMENTS: " << apts << endl;
	printSeperator();
	Doctors::showInfo();
	printSeperator();
	Appointments::showAppointments();
	printSeperator();
	while (apts > 0 && Doctors::getNumberOfDoctors() > 0) {
		cout << "Assign avaliable doctor to appointment? (Y/N)" << endl;
		string input;
		getline(cin, input);
		if (input == "Y") {
			cout << "Enter doc ID to assign" << endl;
			string docId;
			getline(cin, docId);
			if (Doctors::isDoctorAvaliable(stoi(docId))) {
				Doctor* d = Doctors::getAvaliableDoctorById(stoi(docId));
				string roomNumber;
				cout << "Enter room number of appointment." << endl;
				getline(cin, roomNumber);
				if (Appointments::isUnassigned(stoi(roomNumber))) {
					Appointments::assignDoctor(d, stoi(roomNumber));
					Appointments::showAppointments();
					cout << "Dr. " << d->getName() << " has been assigned to " << Appointments::getAppointmentFromRoom(stoi(roomNumber))->getPatient()->getName() << endl;
				}
				else {
					cout << "THERE IS NO UNASSIGNED APPOINTMENT IN ROOM# " << roomNumber << endl;
				}
			}
			else {
				cout << "DOCTOR IS NOT AVALIABLE/DOESN'T EXIST." << endl;
				break;
			}
		}
		else {
			break;
		}
	}
}

void checkoutPatient() {
	cout << "=== CHECKOUT PATIENTS ===" << endl;
	while (Appointments::getNumberOfCheckoutAppointments() > 0) {
		printSeperator();
		Appointments::showAppointments();
		printSeperator();
		cout << "Enter room number to checkout: " << endl;
		string input;
		getline(cin, input);
		if (Appointments::isAssigned(stoi(input))) {
			Appointment* apt = Appointments::getAppointmentFromRoom(stoi(input));
			Appointment::visitType type = apt->getVisitType();
			bool hasInsurance = apt->getPatient()->hasInsurance();
			double fee = 0;
			switch (type) {
			case(Appointment::preventative):
				if (hasInsurance) { fee = 0; }
				else { fee = 29.95; }
				break;
			case(Appointment::sick):
				if (hasInsurance) { fee = 50.95; }
				else { fee = 150.95; }
				break;
			}
			cout << apt->getPatient()->getName() << " has checked out with $" << fee << endl;
			apt->getPatient()->getAccount()->makeTransaction((fee * -1));
			apt->getDoctor()->getAccount()->makeTransaction(fee);
			Appointments::clearAppointment(apt);
			checkoutPatient();
		}
		else {
			cout << "ROOM NUMBER IS NOT ASSOCIATED WITH AN APPOINTMENT/DOCTOR IS NOT CURRENTLY SEEING PATIENT." << endl;
		}
	}
}

void closeOffice() {
	FileHandler file("OfficeHistory.txt");
	for (Doctor* d : Doctors::getAllDoctors()) {
		string write = d->getName() + ": $" + to_string(d->getAccount()->getBalance() + '\n');
		file.writeToFile(write);
	}
	string write = "Seen Patients: " + to_string(Patients::getSeenPatients());
	file.writeToFile(write);
}