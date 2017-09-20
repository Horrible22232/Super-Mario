#include "stdafx.h"
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL.h>
#include <utils\window\Window.h>
#include <utils\texture\LTexture.h>
#include <utils\filemanager\FileManager.h>
#include <string>

Window g_Window;

bool init();
void run();
void close();
inline void input(SDL_Event& e);
inline void update();
inline void render();

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != NULL) {
		fprintf(stderr, "Unable to initialize SDL:  %s\n", SDL_GetError());
		return false;
	}
	if (!(IMG_Init(IMG_INIT_JPG| IMG_INIT_PNG)&(IMG_INIT_JPG | IMG_INIT_PNG))) {
		printf("IMG_Init: Failed to init required jpg and png support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
	}
	if (!g_Window.CreateWindow("Super Mario", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)) {
		return false;
	}
}

void run() {
	SDL_Event e;

	while (g_Window.Running()) {
		input(e);
		update();
		render();
	}
}

void close()
{
	SDL_Quit();
}

inline void input(SDL_Event& e) {
	while (SDL_PollEvent(&e)) {
		g_Window.EventManager(e);

	}
}

inline void update() {

}

inline void render() {
	SDL_SetRenderDrawColor(g_Window.GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_Window.GetRenderer());


	SDL_RenderPresent(g_Window.GetRenderer());
}





int main(int argc, char *argv[])
{
	init();
	run();
	close();
    return 0;
}

