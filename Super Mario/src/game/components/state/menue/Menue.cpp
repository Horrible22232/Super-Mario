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
	m_bttnstart.init(game->Renderer, "res/images/buttons/buttonyllw.png", "start", 100, 100, 200, 100);
	
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
	m_bttnstart.EventHandler(game->Input->GetMouseManager());
}

void Menue::Update(CGameEngine* game)
{

	
}

void Menue::Render(CGameEngine* game)
{
	if (game->Renderer == NULL) printf("FCK IT ");
	m_bttnstart.Render(game->Renderer);
}

void Menue::Reset(CGameEngine * game)
{
}

Menue* Menue::Instance()
{
	return &m_Menue;
}

//_________________________________________________________ Button start
void startButton::NotTouched()
{
	std::string test = "fuck it";
	m_gfxText.SetText(Renderer, test);
	m_gfxText.SetColor(COLOR_BLACK);
}

void startButton::Hovered()
{
	std::string test = "fuck it2";
	m_gfxText.SetText(Renderer, test);
	m_gfxText.SetColor(COLOR_BLUE);
}

void startButton::Released()
{
	printf("RELEASED YOLO \n"); 

}

void startButton::Pressed()
{
	printf("PRESSED YOLO \n");
}
