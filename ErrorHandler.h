#pragma once
#include <string>
#include <vector>
using namespace std;

class ErrorHandler
{
public:
	ErrorHandler();
	ErrorHandler(string errorCode);

	bool getErrorStatus();
	vector<string> getErrorCodes();
	
	void addErrorCode(string code);
	void clearErrorCodes();
private:
	bool hasError;
	vector<string> errorCodes;
};

