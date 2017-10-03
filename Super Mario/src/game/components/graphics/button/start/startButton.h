#pragma once
#include <game\components\graphics\button\Button.h>
class startButton: public Button
{
public:
	startButton();
	~startButton();
private:
	void NotTouched();
	void Hovered();
	void Released();
	void Pressed();
};

