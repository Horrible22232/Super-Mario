#include "stdafx.h"
#include "startButton.h"


startButton::startButton()
{
}


startButton::~startButton()
{
}

void startButton::NotTouched()
{
	m_gfxText.SetColor(COLOR_BLACK);
	
}

void startButton::Hovered()
{
	m_gfxText.SetColor(COLOR_RED);
}

void startButton::Released()
{
}

void startButton::Pressed()
{
	printf("PRESSED YOLO \n");
}
