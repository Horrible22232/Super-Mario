#include "stdafx.h"
#include "Button.h"
#include <game\components\graphics\button\manager\ButtonManager.h>


Button::Button()
{
}


Button::~Button()
{
	ButtonManager::Instance()->remove(this);
	delete m_Button;
}

bool Button::init(SDL_Renderer* renderer, std::string path, std::string text, int x, int y, int width, int height)
{
	ButtonManager::Instance()->add(this);
	m_Button = new LTexture();
	if (!m_Button->LoadTexture(renderer, path)) {
		printf("Error in Loading texture for Button! \n");
		return false;
	}
	Renderer = renderer;
	m_Button->DestTexture(x, y, width, height);
	m_text = text;
	m_gfxText.SetText(renderer, m_text);
	m_gfxText.DestText(x, y, width, height); // TODO
	
	m_ButtonLeftX = m_Button->GetDestRec().x;
	m_ButtonRightX = m_Button->GetDestRec().x + m_Button->GetDestRec().w;
	m_ButtonTopY = m_Button->GetDestRec().y;
	m_ButtonDownY = m_Button->GetDestRec().y + m_Button->GetDestRec().h;
	return true;
}

void Button::EventHandler(MouseManager& mouse)
{
	if (hovered(mouse)) {
		Hovered();
		if (mouse.LeftClick()) {
			Pressed();
		}
	}
	else {
		NotTouched();
	}
}

void Button::Render(SDL_Renderer* renderer)
{
	m_Button->Render(renderer);
	m_gfxText.Render(renderer);
}

bool Button::hovered(MouseManager& mouse)
{
	if (mouse.GetX() >= m_ButtonLeftX && mouse.GetX() <= m_ButtonRightX) { // Check if mouse is left + right of the button
		if (mouse.GetY() >= m_ButtonTopY && mouse.GetY() <= m_ButtonDownY) {
			return true;
		}
	}
	return false;
}