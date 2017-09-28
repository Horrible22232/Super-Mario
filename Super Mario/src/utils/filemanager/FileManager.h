#pragma once
#include <iostream>

class FileManager
{
public:
	FileManager();
	~FileManager();
public:
	char* ReadFile(std::string path);
	bool WriteFile(std::string path, std::string& text);

private:
	char* res;
};

