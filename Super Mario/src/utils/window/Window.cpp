#include "stdafx.h"
#include "Window.h"


Window::Window():m_Window(NULL)
{
}


Window::~Window()
{
	SDL_DestroyWindow(m_Window);
}

bool Window::CreateWindow(std::string title, int x, int y, int width, int height, Uint32 flags)
{
	// get Window parameters
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;

	//Create Window
	m_Window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
	if (m_Window == NULL) {
		printf("Window Creation ERROR: %s", SDL_GetError());
		return false;
	}
	//Create Renderer
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE); //Vsync until framerate done!
	if (m_Renderer == NULL) {
		printf("Renderer Creation ERROR: %s", SDL_GetError());
		return false;
	}
	//Create Surface
	m_Surface = SDL_GetWindowSurface(m_Window);
	if (m_Surface == NULL) {
		printf("Surface Creation ERROR: %s", SDL_GetError());
		return false;
	}

	return true;
}

SDL_Window* Window::GetWindow()
{
	return m_Window;
}

SDL_Renderer* Window::GetRenderer()
{
	return m_Renderer;
}

SDL_Surface* Window::GetSurface()
{
	return m_Surface;
}

