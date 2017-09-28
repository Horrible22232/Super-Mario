#pragma once
#include <game\components\state\CGameState.h>
#include <game\components\state\GameEngine.h>

class Menue: public CGameState
{
protected:
	Menue();
	~Menue();
public:
	void Init() override;
	void Cleanup() override;

	void Pause() override;
	void Resume() override;

	void HandleEvents(CGameEngine* game, SDL_Event& e) override;
	void Update(CGameEngine* game) override;
	void Render(CGameEngine* game) override;

private:
	

public: 
	static Menue* Instance();

private:
	static Menue m_Menue;
};

