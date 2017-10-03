#include "stdafx.h"
#include "MouseManager.h"


MouseManager::MouseManager()
{
	Reset();
}


MouseManager::~MouseManager()
{
}

void MouseManager::EventHandler(SDL_Event& e)
{
	Reset(); // NEED TO ADD
	SDL_GetMouseState(&m_X, &m_Y);
	m_xRel = e.motion.xrel;
	m_yRel = e.motion.yrel;
	switch(e.button.button){
		case SDL_BUTTON_LEFT:
			//Check left clicks
			switch (e.button.clicks) {
			case 1:
				m_leftClick = true;
				break;
			case 2:
				m_leftDoubleClick = true;
				break;
			}
			//Check left state (hold release)
			switch (e.type) {
			case SDL_MOUSEBUTTONDOWN:
				m_leftButtonHold = true;
				break;
			case SDL_MOUSEBUTTONUP:
				m_leftReleased = true;
				break;
			}
			break;
		case SDL_BUTTON_RIGHT:
			//Check right clicks
			switch (e.button.clicks) {
			case 1:
				m_rightClick = true;
				break;
			case 2:
				m_rightDoubleClick = true;
				break;
			}
			//Check right state (hold release)
			switch (e.type) {
			case SDL_MOUSEBUTTONDOWN:
				m_rightButtonHold = true;
				break;
			case SDL_MOUSEBUTTONUP:
				m_rightReleased = true;
				break;
			}
			break;
	}
}

void MouseManager::Reset()
{
	m_leftClick = false;
	m_leftDoubleClick = false;
	m_leftReleased = false;
	m_leftButtonHold = false;
	m_rightClick = false;
	m_rightDoubleClick = false;
	m_rightReleased = false;
	m_rightButtonHold = false;
}

bool MouseManager::LeftClick()
{
	return m_leftClick || m_leftDoubleClick;
}

bool MouseManager::LeftDoubleClick()
{
	return m_leftDoubleClick;
}

bool MouseManager::LeftReleased()
{
	return m_leftReleased;
}

bool MouseManager::LeftButtonHold()
{
	return m_leftButtonHold;
}

bool MouseManager::RightClick()
{
	return m_rightClick || m_rightDoubleClick;
}

bool MouseManager::RightDoubleClick()
{
	return m_rightDoubleClick;
}

bool MouseManager::MouseWheel() //TODO MOUSEWHEEL
{
	return false;
}

bool MouseManager::RightReleased()
{
	return m_rightReleased;
}

bool MouseManager::RightButtonHold()
{
	return m_rightButtonHold;
}

int* MouseManager::GetXRelative()
{
	return &m_xRel;
}

int* MouseManager::getYRelative()
{
	return &m_yRel;
}

int* MouseManager::GetX()
{
	return &m_X;
}

int* MouseManager::GetY()
{
	return &m_Y;
}
