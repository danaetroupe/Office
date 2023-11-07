#pragma once
#include <fstream>
#include <vector>
using namespace std;

class FileHandler
{
	fstream file;
public:
	FileHandler(string fileName);
	~FileHandler();

	template <typename T = string> void writeToFile(T text);
	vector<string> readFromFile();
	// More helper functions to come
};

