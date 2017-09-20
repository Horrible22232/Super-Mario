#pragma once
#include <iostream>

class FileManager
{
public:
	FileManager();
	~FileManager();
public:
	std::string ReadFile(std::string path);
	bool WriteFile(std::string path, std::string text);
};

