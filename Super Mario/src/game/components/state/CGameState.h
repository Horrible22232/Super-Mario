#pragma once
#ifndef __GameState_H
#define __GameState_H

class CGameState
{
public:
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(CGameEngine* game) = 0;
	virtual void Update(CGameEngine* game) = 0;
	virtual void Draw(CGameEngine* game) = 0;

	void ChangeState(CGameEngine* game, CGameState* state) {
		game->ChangeState(this);
	}

	protected: CGameState() { }
};
#endif 
