#include "stdafx.h"
#include "FileManager.h"
#include <SDL.h>

static FileManager m_FileManager;

FileManager::FileManager()
{
}

FileManager::~FileManager()
{

}

std::string FileManager::ReadFile(std::string path)
{
	SDL_RWops *rw = SDL_RWFromFile(path.c_str(), "rb");
	if (rw == NULL) return NULL;

	Sint64 res_size = SDL_RWsize(rw);
	char* res = (char*)malloc(res_size + 1);

	Sint64 nb_read_total = 0, nb_read = 1;
	char* buf = res;
	while (nb_read_total < res_size && nb_read != 0) {
		nb_read = SDL_RWread(rw, buf, 1, (res_size - nb_read_total));
		nb_read_total += nb_read;
		buf += nb_read;
	}
	SDL_RWclose(rw);
	if (nb_read_total != res_size) {
		free(res);
		return NULL;
	}
	res[nb_read_total] = '\0';
	std::string result = res;
	
	return result;
}

bool FileManager::WriteFile(std::string path, std::string& text)
{
	SDL_RWops *rw = SDL_RWFromFile(path.c_str(), "w");
	if (rw == NULL) {
		printf("ERROR by Creating a file Writer: %s\n", SDL_GetError());
		return false;
	}
	if (SDL_RWwrite(rw, text.c_str(), 1, text.length()) != text.length()) {
		printf("ERROR Couldn't write the String: %s, ERROR: %s\n",text.c_str(), SDL_GetError());
		return false;
	}

	SDL_RWclose(rw);

	return true;
}

FileManager* FileManager::Instance()
{
	return &m_FileManager;
}

