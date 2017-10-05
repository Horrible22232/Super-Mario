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
	int bttnstartWidth = 200;
	int bttnstartHeight = 100;
	m_bttnstart.init(game->Renderer, "res/images/buttons/buttonyllw.png", "start", (game->window->GetWidth() - bttnstartWidth) / 2, (game->window->GetHeight() - bttnstartHeight) / 2, bttnstartWidth, bttnstartHeight);
	test.LoadTexture(game->Renderer, std::string("res/images/buttons/buttonyllw.png"));
	m_X = 0;
	test.DestTexture(m_X, 300, 20, 20);
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
	test.DestTexture(++m_X, 300, 20, 20);
	
}

void Menue::Render(CGameEngine* game)
{
	test.Render(game->Renderer);
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
	std::string test = "Start";
	m_gfxText.SetColor(COLOR_BLACK);
	m_gfxText.SetText(Renderer, test);
}

void startButton::Hovered()
{
	m_gfxText.SetColor(COLOR_RED);
}

void startButton::Pressed()
{
	printf("PRESSED YOLO \n");
}
