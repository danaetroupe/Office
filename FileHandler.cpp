#include "FileHandler.h"

FileHandler::FileHandler(string fileName) {
	file.open(fileName);
}

FileHandler::FileHandler(string fileName, ErrorHandler* handler) {
	file.open(fileName);
	handler->checkFile(fileName);
}

FileHandler::~FileHandler() {
	file.close();
}

vector<string> FileHandler::readFromFile() {
	vector<string> results;
	string s;
	while(file) {
		getline(file, s);
		results.push_back(s);
	}
	return results;
}

vector<string> FileHandler::readFromFile(string breakpoint) {
	vector<string> results;
	string s = "";
	while (file) {
		getline(file, s);
		if (s != breakpoint) { results.push_back(s); }
		else { break; }
	}
	return results;
}

void FileHandler::writeToFile(std::string text) {
	file << text;
}