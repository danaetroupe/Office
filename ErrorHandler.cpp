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

void ErrorHandler::addErrorCode(FLAGS flag) {
    errorStatus = true;
    errorCodes.push_back(flag);
    string display;
    switch (flag) {
    case(ERROR_ADDRESS_INVALID):
        display = "Address invalid.";
        break;
    case(ERROR_CITY_INVALID):
        display = "City invalid.";
        break;
    case(ERROR_EMAIL_INVALID):
        display = "Email invalid.";
        break;
    case(ERROR_NAME_INVALID):
        display = "Name invalid.";
        break;
    case(ERROR_PHONE_INVALID):
        display = "Phone invalid.";
        break;
    case(ERROR_ZIPCODE_INVALID):
        display = "Zip code invalid.";
        break;
    default:
        display = "Error code not recognized";
    }
    errorDisplays.push_back(display);
}

vector<string> ErrorHandler::getErrorDisplays() {
    return errorDisplays;
}