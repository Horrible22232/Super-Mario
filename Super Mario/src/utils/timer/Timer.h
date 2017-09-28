#pragma once
#include <SDL.h>
#include <math.h>

class Timer
{
public:
	Timer();
	~Timer();
public:
	void Start();
	void Stop();
	void Pause();
	void Continue();
	Uint32& GetTime();
	bool isStopped();
	bool isRunning();
	bool isPaused();
private:
	bool m_Running;
	bool m_Paused;
	Uint32 m_StartedTicks;
	Uint32 m_PausedTicks;
};

