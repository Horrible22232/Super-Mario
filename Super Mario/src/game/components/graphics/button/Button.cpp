#include "stdafx.h"
#include "Button.h"


Button::Button()
{
}


Button::~Button()
{
}

void Button::EventHandler(SDL_Event& e)
{
}

bool Button::init(SDL_Renderer* renderer, std::string path, int x, int y, int width, int height)
{
	m_Button = new LTexture();
	m_Button->LoadTexture(renderer, path); //Check bool
	m_Button->DestTexture(x, y, width, height);
	return true;
}
