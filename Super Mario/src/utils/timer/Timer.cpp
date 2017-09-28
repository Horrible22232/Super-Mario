#include "stdafx.h"
#include "Timer.h"


Timer::Timer(): m_Running(false), m_Paused(false), m_StartedTicks(0), m_PausedTicks(0)
{
}


Timer::~Timer()
{
}

void Timer::Start()
{
	m_Running = true;
	m_Paused = false;
	m_StartedTicks = SDL_GetTicks();
}

void Timer::Pause()
{
	if(!m_Paused){
	m_Paused = true;
	m_PausedTicks += SDL_GetTicks();
	}
}

void Timer::Continue()
{
	if(m_Paused){
	m_Paused = false;
	m_PausedTicks = abs(SDL_GetTicks() - m_PausedTicks);
	}
}

void Timer::Stop()
{
	m_Running = false;
	m_Paused = false;
}

Uint32 Timer::GetTime()
{
	Uint32 finalTime = 0;
	if (isPaused()) {
		finalTime = m_PausedTicks - m_StartedTicks;
	}
	else {
		finalTime = SDL_GetTicks() - m_StartedTicks - m_PausedTicks;
	}
	return finalTime;
}

bool Timer::isStopped()
{
	return !m_Running;
}


bool Timer::isRunning()
{
	return m_Running;
}

bool Timer::isPaused()
{
	return m_Paused;
}

