#include "stdafx.h"
#include "SoundManager.h"



SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
	for (int i = 0; i != EVENT_SIZE; i++) {
		if (m_SoundFiles[i] != NULL) {
			Mix_FreeChunk(m_SoundFiles[i]);
		}
	}
}

bool SoundManager::Init()
{
	addObserver(this);
	return true;
}

bool SoundManager::LoadFile(std::string& path, Event& event)
{
	m_SoundFiles[event] = Mix_LoadWAV(path.c_str());
	if (!m_SoundFiles[event]) {
		printf("Mix_LoadWAV: %s at path %s\n", Mix_GetError(), path);
		return false;
	}
	return true;
}

bool SoundManager::PlayWAV(std::string path, Event& event)
{
	if (m_SoundFiles[event] == NULL && !LoadFile(path, event)) {
		return false;
	}
	if (Mix_PlayChannel(-1, m_SoundFiles[event], 0) == -1) {
		printf("Mix_PlayChannel: %s\n", Mix_GetError());
	}

	return true;
}

void SoundManager::Update()
{
}


void SoundManager::onNotification(Event& event)
{
	switch(event){
	case EVENT_Button_Clicked:
		PlayWAV("res/sound/smw_game_over.wav", event); //implement AVL-Tree currently to lazy
		break;
	}
}
