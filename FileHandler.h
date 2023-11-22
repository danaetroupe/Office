#pragma once
#include <fstream>
#include <vector>

#include "ErrorHandler.h"

class FileHandler
{
	fstream file;
public:
	FileHandler(string fileName);
	FileHandler(string fileName, ErrorHandler* handler);
	~FileHandler();

	void writeToFile(std::string text);
	vector<string> readFromFile();
	//vector<string> readFromFile(int lines);
	vector<string> readFromFile(string breakpoint);
	// More helper functions to come
};

