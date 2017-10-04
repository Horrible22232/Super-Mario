#pragma once
#include <vector>
#include <game\components\input\Input.h>
#include <game\components\graphics\button\Button.h>
class ButtonManager
{
protected:
	ButtonManager();
	~ButtonManager();
public:
	void add(Button* Button);
	void remove(Button* button);
	void Render(SDL_Renderer* renderer);
	void EventHandler(MouseManager& mouse);
	static ButtonManager* Instance();
private:
	std::vector<Button*> m_BttnManager;
	static ButtonManager m_Manager;

};

