#include "stdafx.h"
#include "GameEngine.h"
#include <SDL.h>
#include <game\components\camera\Camera.h>
#include <game\components\graphics\text\Text.h>
#include <game\components\graphics\button\manager\ButtonManager.h>

CGameEngine::CGameEngine(Window* window, SDL_Renderer* Renderer): window(window), Renderer(Renderer)
{

}

CGameEngine::~CGameEngine()
{

}


void CGameEngine::Init(Window& window)
{
	Camera::Instance()->init(new int(window.GetWidth()), new int(window.GetHeight()));
	Input = new CInput();
	Input->Init();
	m_SoundManager.Init();
	//SDL_CaptureMouse(SDL_TRUE);

}

void CGameEngine::Cleanup()
{
	while (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}
	delete Input;
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
	Input->EventHandler(e);
	ButtonManager::Instance()->EventHandler(Input->GetMouseManager());
	states.back()->HandleEvents(this, e);
}

void CGameEngine::Update()
{
	// let the state update the game
	m_SoundManager.Update();
	states.back()->Update(this);
}

void CGameEngine::Render()
{
	// let the state draw the screen
	states.back()->Render(this);
	ButtonManager::Instance()->Render(Renderer);
}

void CGameEngine::Reset()
{
	Input->GetMouseManager().Reset();
	states.back()->Reset(this);
}

bool CGameEngine::Running()
{
	return m_running;
}

void CGameEngine::Quit()
{
	m_running = false;
}
