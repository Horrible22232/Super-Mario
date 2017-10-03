#include "stdafx.h"
#include "Menue.h"

Menue Menue::m_Menue;

Menue::Menue()
{
}


Menue::~Menue()
{
}

void Menue::Init(CGameEngine* game)
{
	m_text.Init("res/font/CONFN.TTF");
	m_text.DestText(50, 100, 400, 100);
	m_text.SetColor(COLOR_ORANGE);
	m_text.SetText(game->Renderer, "YES IT WORKS");
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
	m_text.Render(game->Renderer);
}

void Menue::Reset(CGameEngine * game)
{
}

Menue* Menue::Instance()
{
	return &m_Menue;
}
