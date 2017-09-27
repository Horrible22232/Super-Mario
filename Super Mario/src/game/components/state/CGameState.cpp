#include "CGameState.h"

void CGameState::ChangeState(CGameEngine * game, CGameState * state)
{
		game->ChangeState(this);
}
