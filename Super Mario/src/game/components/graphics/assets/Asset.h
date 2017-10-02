#pragma once
#include <game\components\graphics\texture\LTexture.h>
#include <utils\shapes\ShapeRec.h>
class Asset
{
public:
	Asset(LTexture* texture);
	~Asset();
public:
	LTexture* GetTexture();
	virtual bool init() = 0;
	virtual bool SetStart(int start);
	virtual bool SetCurrent(int current);
	virtual bool SetEnd(int end);
	virtual int& GetSize();
	virtual ShapeRec& GetShape(int shape);
	virtual ShapeRec& NextShape();
	virtual bool Render(SDL_Renderer* renderer);
private:
	int m_Start;
	int m_Current;
	int m_End;
	int m_size;
	LTexture* m_Texture;
	ShapeRec* m_Shapes;

};

