#pragma once
#include <SDL.h>
#include <iostream>
#include <game\components\graphics\texture\LTexture.h>

class Button
{
public:
	Button();
	~Button();
public:
	void EventHandler(SDL_Event& e);
	bool init(SDL_Renderer* renderer, std::string path, int x, int y, int width, int height);
	virtual void handleClicked() = 0;
	virtual void handleHovered() = 0;
private:
	LTexture* m_Button;
};

