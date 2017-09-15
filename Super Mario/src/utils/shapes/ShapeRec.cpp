#include "stdafx.h"
#include "ShapeRec.h"


ShapeRec::ShapeRec()
{
}

ShapeRec& ShapeRec::CreateShape(int x, int y, int width, int height) {
	m_Shape = SDL_Rect{ x, y, width, height };
	return *this;
}

const SDL_Rect& ShapeRec::GetShape() const
{
	return m_Shape;
}


ShapeRec::~ShapeRec()
{

}
