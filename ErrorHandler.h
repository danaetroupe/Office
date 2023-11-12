#pragma once
#include <string>
#include <vector>
#include <regex>
using namespace std;

class ErrorHandler
{
public:
	enum FLAGS { ERROR_NAME_INVALID, ERROR_ADDRESS_INVALID, ERROR_CITY_INVALID, ERROR_EMAIL_INVALID, ERROR_ZIPCODE_INVALID, ERROR_PHONE_INVALID, 
		ERROR_FILE_INVALID };

	bool getErrorStatus();
	vector<FLAGS> getErrorCodes();
	vector<string> getErrorDisplays();
	
	void addErrorCode(FLAGS flag);
	void clearErrorCodes();

	void checkName(string name);
	void checkEmail(string email);
	void checkAddress(string address, string zip);
	void checkNumber(string phone);
	void checkFile(string file);
private:
	bool errorStatus = false;
	vector<FLAGS> errorCodes;
	vector<string> errorDisplays;
};

