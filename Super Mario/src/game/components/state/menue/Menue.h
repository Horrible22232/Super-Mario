#pragma once
#include <game\components\state\CGameState.h>
#include <game\components\state\GameEngine.h>
#include <game\components\graphics\text\Text.h>
#include <game\components\graphics\button\Button.h>
#include "..\..\observer\Observer.h"

class StartButton : public Observer, public Button {

private:
	void NotTouched();
	void Hovered();
	void Pressed();
	virtual void onNotification(Event& event) override;

};

class Menue: public CGameState, public Observer
{
protected:
	Menue();
	~Menue();
public:
	void Init(CGameEngine* game) override;
	void Cleanup() override;

	void Pause() override;
	void Resume() override;

	void HandleEvents(CGameEngine* game, SDL_Event& e) override;
	void Update(CGameEngine* game) override;
	void Render(CGameEngine* game) override;
	void Reset(CGameEngine* game) override;

private:
	virtual void onNotification(Event& event) override;

private:
	StartButton m_bttnstart;
	int m_X;
	LTexture test;
public: 
	static Menue* Instance();

private:
	static Menue m_Menue;
};
