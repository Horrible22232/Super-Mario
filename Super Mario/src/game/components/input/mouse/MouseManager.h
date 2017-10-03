#pragma once
#include <SDL.h>
class MouseManager
{
public:
	MouseManager();
	~MouseManager();
public:
	void Reset();
	void EventHandler(SDL_Event& e);
	bool LeftClick();
	bool LeftDoubleClick();
	bool LeftReleased();
	bool LeftButtonHold();
	bool MouseWheel();
	bool RightClick();
	bool RightDoubleClick();
	bool RightReleased();
	bool RightButtonHold();
	int* GetX();
	int* GetY();
	int* GetXRelative();
	int* getYRelative();

private:
	int m_X;
	int m_Y;
	int m_xRel;
	int m_yRel;
	bool m_leftClick;
	bool m_leftDoubleClick;
	bool m_leftReleased;
	bool m_leftButtonHold;
	bool m_rightClick;
	bool m_rightDoubleClick;
	bool m_rightReleased;
	bool m_rightButtonHold;
};

