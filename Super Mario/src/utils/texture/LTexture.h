#pragma once
#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <utils/shapes/ShapeRec.h>

class LTexture
{
public:
	LTexture();
	~LTexture();

public:
	bool LoadTexture(SDL_Renderer* renderer, std::string& path);
	bool Render(SDL_Renderer* renderer);
	void CutTexture(int x, int y, int width, int height);
	void CutTexture(ShapeRec& Rect);
	void DestTexture(int x, int y);
	void DestTexture(int x, int y, int width, int height);
	void DestTexture(ShapeRec& Rect);
	void AdjustBoarders();

private:
	SDL_Rect m_CuttedTex;
	SDL_Rect m_DestTex;
	SDL_Texture* m_Texture;
	int m_width;
	int m_height;


};



