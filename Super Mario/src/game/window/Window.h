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
	bool Running();
	void EventManager(SDL_Event& e);
	const int& GetX() const;
	const int& GetY() const;
	const int& GetHeight() const;
	const int& GetWidth() const;
	SDL_Window* GetWindow() const;
	SDL_Renderer* GetRenderer() const;
	SDL_Surface* GetSurface() const;
private:
	int m_x, m_y, m_width, m_height;
	bool m_Running;
	Uint8 m_WindowID;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	SDL_Surface* m_Surface;
};

