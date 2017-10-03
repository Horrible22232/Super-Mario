#pragma once
#include <game\components\state\CGameState.h>
#include <game\components\state\GameEngine.h>
#include <game\components\graphics\text\Text.h>

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
	Text m_text;

public: 
	static Menue* Instance();

private:
	static Menue m_Menue;
};

