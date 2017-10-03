#pragma once
#include "GameEngine.h"

class CGameEngine;


class CGameState
{
public:
	virtual void Init(CGameEngine* game) = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(CGameEngine* game, SDL_Event& e) = 0;
	virtual void Update(CGameEngine* game) = 0;
	virtual void Render(CGameEngine* game) = 0;
	virtual void Reset(CGameEngine* game) = 0;

	void ChangeState(CGameEngine* game, CGameState* state);

protected: CGameState() { }
};
