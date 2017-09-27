#pragma once
#include "stdafx.h"
#include <game\components\window\Window.h>
#include <game\components\state\CGameState.h>
#include <vector>
class CGameState;
class Window;


class CGameEngine
{
public:
	CGameEngine(Window* Window, SDL_Renderer* Renderer);
	CGameEngine::~CGameEngine();
public:
	void Init();
	void Cleanup();

	void ChangeState(CGameState* state);
	void PushState(CGameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running();
	void Quit();

public:
	Window* window;
	SDL_Renderer* Renderer;


private:
	// the stack of states
	std::vector<CGameState*> states;

	bool m_running;
};

