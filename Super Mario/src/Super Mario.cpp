#include "stdafx.h"
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL.h>
#include <game\components\window\Window.h>
#include <game\components\texture\LTexture.h>
#include <utils\filemanager\FileManager.h>
#include <game\components\state\GameEngine.h>
#include <string>
#include <game\components\state\menue\Menue.h>

//Pre Loaded functions
bool init();
void run();
void close(CGameEngine& Game);
inline void input(SDL_Event& e, CGameEngine& Game);
inline void update(CGameEngine& Game);
inline void render(CGameEngine& Game);

//global Variables
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
		return false;
	}
	if (!g_Window.CreateWindow("Super Mario", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)) {
		return false;
	}
	return true;
}

void run()
{
	CGameEngine Game(&g_Window, g_Window.GetRenderer());
	Game.Init();
	Game.ChangeState(Menue::Instance());
	SDL_Event e;

	while (g_Window.Running()) {
		input(e, Game);
		update(Game);
		render(Game);
	}

	close(Game);
}

void close(CGameEngine& Game)
{
	Game.Cleanup();
	SDL_Quit();
}

inline void input(SDL_Event& e, CGameEngine& Game)
{
	while (SDL_PollEvent(&e)) {
		g_Window.EventManager(e);
		Game.HandleEvents(e);

	}
}

inline void update(CGameEngine& Game)
{
	Game.Update();
}

inline void render(CGameEngine& Game) 
{
	SDL_SetRenderDrawColor(g_Window.GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_Window.GetRenderer());
	Game.Render();

	SDL_RenderPresent(g_Window.GetRenderer());
}




int main(int argc, char *argv[])
{
	if (!init()) {
		printf("Error Init!\n");
		exit(EXIT_FAILURE);
	}
	run();
    return 0;
}

