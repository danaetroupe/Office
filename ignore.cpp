
#include "global.h"
/*
menuOptions showMenu() {
	vector<string> options = { "Load office data", "Add new patient", "Add new doctor", "Patient queue summary", "Doctor summary", "Checkout patient", "Close office" };
	int option = -1;
	while (option == -1) {
		cin >> option;
		switch (option) {
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
			option = -1;
		}
	}
	return close;
}

void addNewPatient(Patients* PATIENTS) {
	ErrorHandler* handler = new ErrorHandler();
	string name, address, city, state, zip, phone, email, insurance;
	cin >> name;
	cin >> address;
	cin >> city;
	cin >> state;
	cin >> zip;
	cin >> phone;
	cin >> email;
	cin >> insurance;
	/*
	Patient* tempPatient = new Patient(name, phone, email, insurance, &Address(address, city, state, zip), Date(5, 27, 2003), handler);
	if (handler->getErrorStatus()) {
		cout << "Error found";
	}*/
//}
/*
int main() {
	Patients* PATIENTS = new Patients();

	ErrorHandler* handler = new ErrorHandler;
	Address* address = new Address("address", "city", "state", "zip");
	Date* date = new Date(5, 27, 2003);
	Patient* tempPatient = new Patient("name", "phone", "danaetroupe.gmail.com", "insurance", address, date, handler);
	if (handler->getErrorStatus()) {
		cout << "Error found";
		string wait;
		cin >> wait;
	}
	else {
		cout << "No error found.";
		string wait;
		cin >> wait;
	}
	/*menuOptions choice = showMenu();
	switch (choice) {
	case(addPatient):
		addNewPatient(PATIENTS);
	}
	delete PATIENTS;
	delete handler;
	delete address;
	delete date;
	delete tempPatient;
	return 1;
}*/