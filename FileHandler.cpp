#include "FileHandler.h"

FileHandler::FileHandler(string fileName) {
	file.open(fileName);
}

FileHandler::~FileHandler() {
	file.close();
}

vector<string> FileHandler::readFromFile() {
	vector<string> results;
	string s;
	while(file) {
		file >> s;
		results.push_back(s);
	}
	return results;
}