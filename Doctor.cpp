#include "Doctor.h"

Doctor::Doctor(string name, string number, string email, Address* address, ErrorHandler* handler) : Person(name, number, email, address, handler) {

}

Doctor::Doctor(vector<string> input, ErrorHandler* handler) {

}
