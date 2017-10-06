#include "stdafx.h"
#include "Window.h"


Window::Window() :
	m_Window(NULL), m_Renderer(NULL), m_Surface(NULL), m_x(0), m_y(0), m_width(0), m_height(0),
	m_Running(true), m_WindowID(0)
{
}


Window::~Window()
{
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
	m_Window = NULL;
	m_Renderer = NULL;
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
	m_WindowID = SDL_GetWindowID(m_Window);
	//Create Renderer
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE); //Vsync until framerate done! 
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


void Window::EventManager(SDL_Event& e)
{
	if (e.type != SDL_WINDOWEVENT && e.window.windowID != m_WindowID) {
		return;
	}
	switch (e.window.event) {
	case SDL_WINDOWEVENT_MOVED:
		m_x = e.window.data1;
		m_y = e.window.data2;
		break;
	case SDL_WINDOWEVENT_RESIZED:
		m_width = e.window.data1;
		m_height = e.window.data2;
		break;
	case SDL_WINDOWEVENT_CLOSE:
		m_Running = false;
		break;
	}
}

bool Window::Running()
{
	return m_Running;
}

const int& Window::GetX() const
{
	return m_x;
}

const int& Window::GetY() const
{
	return m_y;
}

const int& Window::GetHeight() const
{
	return m_height;
}

const int& Window::GetWidth() const
{
	return m_width;
}

SDL_Window* Window::GetWindow() const
{
	return m_Window;
}

SDL_Renderer* Window::GetRenderer() const
{
	return m_Renderer;
}

SDL_Surface* Window::GetSurface() const
{
	return m_Surface;
}

