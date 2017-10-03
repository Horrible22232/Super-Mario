#pragma once
#include <game\components\input\mouse\MouseManager.h>
#include <SDL.h>
class CInput
{
public:
	CInput();
	~CInput();
public:
	void Init();
	MouseManager& GetMouseManager();
	void EventHandler(SDL_Event& e);
private:
	MouseManager* m_MouseManager;
};

