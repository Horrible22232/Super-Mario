#pragma once
#include <SDL.h>
#include <iostream>
class Window
{
public:
	Window();
	~Window();
public:
	bool CreateWindow(std::string title, int x, int y, int w, int h, Uint32 flags);
	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();
	SDL_Surface* GetSurface();
private:
	int m_x, m_y, m_width, m_height;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	SDL_Surface* m_Surface;
};

