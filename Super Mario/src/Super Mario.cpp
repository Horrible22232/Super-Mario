#include "stdafx.h"
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL.h>
#include <utils\window\Window.h>
#include <utils\texture\LTexture.h>

Window g_Window;

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

void close()
{
	SDL_Quit();
}


int main(int argc, char *argv[])
{
	init();
	bool running = true;
	SDL_Event e;
	while(running){
		SDL_SetRenderDrawColor(g_Window.GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(g_Window.GetRenderer());
		while (SDL_PollEvent(&e)) {

		}

		SDL_RenderPresent(g_Window.GetRenderer());
	
	}
	
	close();
    return 0;
}

