#pragma once
#include <fstream>
#include <vector>
using namespace std;

#include "ErrorHandler.h"

class FileHandler
{
	fstream file;
public:
	FileHandler(string fileName);
	FileHandler(string fileName, ErrorHandler* handler);
	~FileHandler();

	template <typename T = string> void writeToFile(T text);
	vector<string> readFromFile();
	vector<string> readFromFile(int lines);
	vector<string> readFromFile(string breakpoint);
	// More helper functions to come
};

