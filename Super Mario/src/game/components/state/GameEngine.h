#pragma once
#include <vector>
#include <game\components\window\Window.h>
#include <game\components\state\CGameState.h>
#include <game\components\input\mouse\MouseManager.h>
#include <game\components\input\Input.h>
class CGameState;

class CGameEngine
{
public:
	CGameEngine(Window* Window, SDL_Renderer* Renderer);
	CGameEngine::~CGameEngine();

public:
	void Init(Window& window);
	void Cleanup();

	void ChangeState(CGameState* state);
	void PushState(CGameState* state);
	void PopState();

	void HandleEvents(SDL_Event& e);
	void Update();
	void Render();
	void Reset();

	bool Running();
	void Quit();

public:
	Window* window;
	SDL_Renderer* Renderer;
	CInput* Input;


private:
	// the stack of states
	std::vector<CGameState*> states;

	bool m_running;
};

