#pragma once
#include <SDL.h>
class ShapeRec
{
public:
	ShapeRec();
	~ShapeRec();

public:
	ShapeRec& CreateShape(int x, int y, int width, int height);
	const SDL_Rect& GetShape() const;
private:
	SDL_Rect m_Shape;
};

