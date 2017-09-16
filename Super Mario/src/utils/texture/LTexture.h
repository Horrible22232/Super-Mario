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
	bool LoadTexture(SDL_Renderer* renderer, std::string& path, Uint8 r, Uint8 g, Uint8 b);
	bool Render(SDL_Renderer* renderer);
	void CutTexture(int x, int y, int width, int height);
	void CutTexture(ShapeRec& Rect);
	void DestTexture(int x, int y);
	void DestTexture(int x, int y, int width, int height);
	void DestTexture(ShapeRec& Rect);
	void AdjustBoarders();
	const SDL_Rect& getCuttedRec() const;
	const SDL_Rect& getDestRec() const;
	const SDL_Texture* getTexture() const;


private:
	SDL_Rect m_CuttedTex;
	SDL_Rect m_DestTex;
	SDL_Texture* m_Texture;
	int m_width;
	int m_height;


};



