#pragma once
#include <game\components\state\CGameState.h>
#include <game\components\state\GameEngine.h>
#include <game\components\graphics\text\Text.h>
#include <game\components\graphics\button\Button.h>

CButton(startButton);

class Menue: public CGameState
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
	startButton m_bttnstart;
	int m_X;
	LTexture test;
public: 
	static Menue* Instance();

private:
	static Menue m_Menue;
};

