#include "MainForm.h"
#include "Patients.h"
#include <iostream>
using namespace std;
using namespace OfficeManager;
using namespace System;
using namespace System::Windows::Forms;
using namespace Patients;

void addNewPatient() {
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
}

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew MainForm());

	deallocateMemory();
	return 0;
}