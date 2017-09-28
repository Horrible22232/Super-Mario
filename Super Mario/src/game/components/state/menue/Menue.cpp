#include "stdafx.h"
#include "Menue.h"

Menue Menue::m_Menue;

Menue::Menue()
{
}


Menue::~Menue()
{
}

void Menue::Init()
{

}

void Menue::Cleanup()
{
}

void Menue::Pause()
{
}

void Menue::Resume()
{
}

void Menue::HandleEvents(CGameEngine* game, SDL_Event& e)
{
}

void Menue::Update(CGameEngine* game)
{

}

void Menue::Render(CGameEngine* game)
{

}

Menue* Menue::Instance()
{
	return &m_Menue;
}
