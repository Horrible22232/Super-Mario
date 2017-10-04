#include "stdafx.h"
#include "ButtonManager.h"

ButtonManager ButtonManager::m_Manager;

ButtonManager::ButtonManager()
{
}


ButtonManager::~ButtonManager()
{
}

void ButtonManager::add(Button* button)
{
	m_BttnManager.push_back(button);
}

void ButtonManager::remove(Button* button)
{
	for (int i = 0; i < m_BttnManager.size(); i++) {
		if (button == m_BttnManager.at(i)) {
			m_BttnManager.erase(m_BttnManager.begin() + i);
		}
	}
}

void ButtonManager::Render(SDL_Renderer* renderer)
{
	for (Button* bttn : m_BttnManager) {
		bttn->Render(renderer);
	}
}

void ButtonManager::EventHandler(MouseManager& mouse)
{
	for (Button* bttn : m_BttnManager) {
		bttn->EventHandler(mouse);
	}
}

ButtonManager* ButtonManager::Instance()
{
	return &m_Manager;
}
