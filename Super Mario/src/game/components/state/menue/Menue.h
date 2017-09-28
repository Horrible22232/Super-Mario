#pragma once
#include <game\components\state\CGameState.h>
#include <game\components\state\GameEngine.h>

class Menue: public CGameState
{
protected:
public:
	Menue();
	~Menue();
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Render(CGameEngine* game);

public: 
	static Menue* Instance();

private:
	static Menue m_Menue;

};

