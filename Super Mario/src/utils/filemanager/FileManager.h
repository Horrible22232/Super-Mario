#pragma once
#include <iostream>

class FileManager
{
protected:
	FileManager();
	~FileManager();
public:
	std::string ReadFile(std::string path);
	bool WriteFile(std::string path, std::string& text);
	static FileManager* Instance();

private:
	static FileManager m_FileManager;
};

