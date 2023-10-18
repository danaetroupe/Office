#pragma once
#include <string>
using namespace std;

#include "Account.h"
#include "ErrorHandler.h"

class Person
{
	string name, address, city, email;
	int zipCode, phoneNumber, id;

	Account* account;
	ErrorHandler* handler;
public:
	Person(string, string, string, string, int, int, string);
	~Person();
	
	pair<bool, vector<string>> getErrors();
};

