#pragma once
#include <SDL.h>
#include <iostream>
#include <game\components\input\Input.h>
#include <game\components\graphics\texture\LTexture.h>
#include <game\components\graphics\text\Text.h>

#define CButton(x); class x: public Button{private: void NotTouched(); void Hovered(); void Released(); void Pressed();};


class Button
{
//Functions
public:
	Button();
	~Button();
public:
	bool init(SDL_Renderer* renderer, std::string path, std::string text, int x, int y, int width, int height);
	void EventHandler(MouseManager& mouse);
	void Render(SDL_Renderer* renderer);
protected:
	virtual void NotTouched() = 0;
	virtual void Hovered() = 0;
	virtual void Pressed() = 0;
private:
	bool hovered(MouseManager& mouse);

//Variables
protected:
	std::string m_text;
	LTexture* m_Button;
	Text m_gfxText;
	int m_ButtonLeftX;
	int m_ButtonRightX;
	int m_ButtonTopY;
	int m_ButtonDownY;
	SDL_Renderer* Renderer;
};

