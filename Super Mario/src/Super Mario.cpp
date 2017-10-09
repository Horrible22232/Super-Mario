#include "stdafx.h"
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL.h>
#include <string>
#include "SDL_ttf.h"
#include <game\components\window\Window.h>
#include <utils\filemanager\FileManager.h>
#include <game\components\state\GameEngine.h>
#include <game\components\state\menue\Menue.h>
#include <game\components\graphics\text\Text.h>
#include <game\components\input\Input.h>
#include <utils\timer\Timer.h>
#include <game\components\observer\Observer.h>
#include "SDL_mixer.h"
#include "game\components\sound\SoundManager.h"


//Pre Loaded functions
bool init();
void run();
void close(CGameEngine& Game);
inline void input(SDL_Event& e, CGameEngine& Game);
inline void update(CGameEngine& Game);
inline void render(CGameEngine& Game);
inline void reset(CGameEngine& Game);
inline void msgSystems();


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
	if (!g_Window.CreateWindow("Super Mario", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)) {
		return false;
	}
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		return false;
	}

	int flags = MIX_INIT_OGG | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_FLAC;
	int initted = Mix_Init(flags);
	if (initted&flags != flags) {
		printf("Mix_Init: Failed to init required ogg and mod support!\n");
		printf("Mix_Init: %s\n", Mix_GetError());
		return false;
	}

	// open 44.1KHz, signed 16bit, system byte order,
	//      stereo audio, using 1024 byte chunks
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
		return false;
	}
	

	return true;
}

void run()
{
	CGameEngine Game(&g_Window, g_Window.GetRenderer());
	Game.Init(g_Window);
	Game.ChangeState(Menue::Instance());
	SDL_Event e;	
	Timer Clock; // Sync Gameloop
	Timer FPSClock; 
	double Max_Time_Per_Tick = 1000 / 30;
	double fps = 0;
	double lag;
	double oldLag = 0;
	Clock.Start();
	FPSClock.Start();
	while (g_Window.Running()) { // DONT LOOK AT THAT MESS
		if (FPSClock.GetTime() >= 1000) {
			std::cout << fps / (double)FPSClock.GetTime() * 1000 << std::endl;
			FPSClock.Reset();
			fps = 0;
		}
		lag = Clock.GetTime() + oldLag;
		while (lag >= Max_Time_Per_Tick) { //Synchronize Update_Tick
			msgSystems();
				lag -= Max_Time_Per_Tick;
			//Update Systems
			input(e, Game);
			Clock.Reset(); //Update the game at least at Max_Time_Per_Tick
			update(Game);
			lag -= Clock.GetTime();
			render(Game); //Render
			// Update variables
			oldLag = lag;
			fps++;	//Count fps
		}
		render(Game);
		fps++;
		reset(Game);
		
	}

	close(Game);
}


void reset(CGameEngine& Game)
{
	Game.Reset();
}

inline void msgSystems()
{
	while (Observer::getNotificationList().size() > 0) {
		for (unsigned int i = 0; i < Observer::getObserverList().size(); i++) {
			Observer::getObserverList().at(i)->onNotification(Observer::getNotificationList().back()); // Notify every System with Events
		}
		Observer::getNotificationList().pop_back(); //remove msged event from the list
	}
}


void close(CGameEngine& Game)
{
	Game.Cleanup();
	Text::free();
	Mix_CloseAudio();
	while (Mix_Init(0)){
		Mix_Quit();
	}
	TTF_Quit();
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

