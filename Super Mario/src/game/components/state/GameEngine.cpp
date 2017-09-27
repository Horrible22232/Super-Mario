#include "stdafx.h"
#include "GameEngine.h"




CGameEngine::CGameEngine(Window* window, SDL_Renderer* Renderer) :window(window), Renderer(Renderer)
{

}

CGameEngine::~CGameEngine()
{
}


void CGameEngine::Init()
{
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
	states.back()->Init();
}

void CGameEngine::PushState(CGameState* state)
{
	// pause current state
	if (!states.empty()) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
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

void CGameEngine::HandleEvents()
{
	// let the state handle events
	states.back()->HandleEvents(this);
}

void CGameEngine::Update()
{
	// let the state update the game
	states.back()->Update(this);
}

void CGameEngine::Draw()
{
	// let the state draw the screen
	states.back()->Draw(this);
}
