#include "stdafx.h"
#include "GameEngine.h"
#include <SDL.h>
#include <game\components\camera\Camera.h>
#include <game\components\graphics\text\Text.h>

CGameEngine::CGameEngine(Window* window, SDL_Renderer* Renderer):window(window), Renderer(Renderer)
{

}

CGameEngine::~CGameEngine()
{
}


void CGameEngine::Init(Window& window)
{
	Camera::Instance()->init(new int(window.GetWidth()), new int(window.GetHeight()));
}

void CGameEngine::Cleanup()
{
	while (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}
}

void CGameEngine::ChangeState(CGameState* state)
{
	// cleanup the current state
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}

void CGameEngine::PushState(CGameState* state)
{
	// pause current state
	if (!states.empty()) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}

void CGameEngine::PopState()
{
	// cleanup the current state
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if (!states.empty()) {
		states.back()->Resume();
	}
}

void CGameEngine::HandleEvents(SDL_Event& e)
{
	// let the state handle events
	states.back()->HandleEvents(this, e);
}

void CGameEngine::Update()
{
	// let the state update the game
	states.back()->Update(this);
}

void CGameEngine::Render()
{
	// let the state draw the screen
	states.back()->Render(this);
}

bool CGameEngine::Running()
{
	return m_running;
}

void CGameEngine::Quit()
{
	m_running = false;
}
