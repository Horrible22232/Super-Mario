#include "stdafx.h"
#include "Input.h"


CInput::CInput()
{
}

CInput::~CInput()
{
	delete m_MouseManager;
}



void CInput::Init()
{
	m_MouseManager = new MouseManager();
}



MouseManager& CInput::GetMouseManager()
{
	return *m_MouseManager;
}

void CInput::EventHandler(SDL_Event& e)
{
	m_MouseManager->EventHandler(e);
}
