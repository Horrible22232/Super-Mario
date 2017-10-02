#pragma once
#include <game\components\window\Window.h>
#include <game\components\state\CGameState.h>
#include <vector>

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

