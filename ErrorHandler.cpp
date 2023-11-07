#include "ErrorHandler.h"

bool ErrorHandler::getErrorStatus()
{
    return errorStatus;
}

vector<ErrorHandler::FLAGS> ErrorHandler::getErrorCodes()
{
    return errorCodes;
}

void ErrorHandler::clearErrorCodes()
{
    errorCodes.clear();
    errorDisplays.clear();
    errorStatus = false;
}

void ErrorHandler::checkName(string name) {
    if (!regex_match(name, regex("[a-zA-Z]+"))) {
        addErrorCode(ERROR_NAME_INVALID);
    }
}

void ErrorHandler::checkEmail(string email) {
    if (!regex_match(email, regex("[a-zA-Z0-9_]+@[a-zA-Z]+.[a-ZA-Z]+"))) {
        addErrorCode(ERROR_EMAIL_INVALID);
    }
}

void ErrorHandler::checkAddress(string address, string zip) {
    if (!regex_match(address, regex("[0-9][0-9]*[a-zA-Z]")) || !regex_match(zip, regex("[0-9]+"))) {
        addErrorCode(ERROR_ADDRESS_INVALID);
    }
}

void ErrorHandler::checkNumber(string phone) {
    if (!regex_match(phone, regex("[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]"))) {
        addErrorCode(ERROR_PHONE_INVALID);
    }
}

void ErrorHandler::addErrorCode(FLAGS flag) {
    errorStatus = true;
    errorCodes.push_back(flag);
    string display;
    switch (flag) {
    case(ERROR_ADDRESS_INVALID):
        display = "INVALID ADDRESS";
        break;
    case(ERROR_CITY_INVALID):
        display = "INVALID CITY";
        break;
    case(ERROR_EMAIL_INVALID):
        display = "INVALID EMAIL";
        break;
    case(ERROR_NAME_INVALID):
        display = "INVALID NAME";
        break;
    case(ERROR_PHONE_INVALID):
        display = "INVALID PHONE";
        break;
    case(ERROR_ZIPCODE_INVALID):
        display = "INVALID ZIP";
        break;
    default:
        display = "ERROR CODE NOT RECOGNIZED";
    }
    errorDisplays.push_back(display);
}

vector<string> ErrorHandler::getErrorDisplays() {
    return errorDisplays;
}