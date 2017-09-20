#include "stdafx.h"
#include "FileManager.h"
#include <SDL.h>

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
	return res;
}

bool FileManager::WriteFile(std::string path, std::string text)
{
	return false;
}
