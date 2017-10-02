#pragma once
#include "SDL_ttf.h"
#include <iostream>
#include <utils/shapes/ShapeRec.h>
enum Color {
	RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, BLACK
};

class Text
{
public:
	Text();
	~Text();
public:
	bool Init(std::string path);
	bool Render(SDL_Renderer* renderer);
	bool RenderBoarders(SDL_Renderer* renderer);
	bool RenderBoarders(SDL_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
	bool SetText(SDL_Renderer* renderer, std::string text);
	void DestText(int x, int y);
	void DestText(int x, int y, int width, int height);
	void DestText(ShapeRec& Rect);
	void SetColor(Color color);
	const SDL_Rect& GetDestRec() const;
	static void free();

private:
	static TTF_Font *m_Font;
	SDL_Rect m_DestText;
	SDL_Texture* m_Texture;
	SDL_Color m_Color;
};

