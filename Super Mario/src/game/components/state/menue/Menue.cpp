#include "stdafx.h"
#include "Menue.h"
#include "..\..\observer\event\EventList.h"


Menue Menue::m_Menue;


Menue::Menue()
{
}


Menue::~Menue()
{
	delete m_bttnstart;
}

void Menue::Init(CGameEngine* game)
{
	int bttnstartWidth = 200;
	int bttnstartHeight = 100;
	m_bttnstart = new StartButton();
	m_bttnstart->init(game->Renderer, "res/images/buttons/buttonyllw.png", "start", (game->window->GetWidth() - bttnstartWidth) / 2, (game->window->GetHeight() - bttnstartHeight) / 2, bttnstartWidth, bttnstartHeight);
	test.LoadTexture(game->Renderer, std::string("res/images/buttons/buttonyllw.png"));
	m_X = 0;
	test.DestTexture(m_X, 300, 20, 20);
	addObserver(this);
	Notify(EVENT_STATE_MENUE);
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

void Menue::onNotification(Event& event)
{
	switch (event) {
	case EVENT_Button_Clicked:
		break;
	}
}

Menue* Menue::Instance()
{
	return &m_Menue;
}

//_________________________________________________________ Button start
void StartButton::NotTouched()
{
	std::string test = "Start";
	m_gfxText.SetColor(COLOR_BLACK);
	m_gfxText.SetText(Renderer, test);
}

void StartButton::Hovered()
{
	m_gfxText.SetColor(COLOR_RED);
}

void StartButton::Pressed()
{
	Notify(EVENT_Button_Clicked);
}

void StartButton::onNotification(Event& event)
{
	throw std::logic_error("The method or operation is not implemented.");
}
