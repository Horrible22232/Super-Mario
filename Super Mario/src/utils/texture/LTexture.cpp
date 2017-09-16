#include "stdafx.h"
#include "LTexture.h"
#include <SDL_image.h>


LTexture::LTexture()
{
}


LTexture::~LTexture()
{
	SDL_DestroyTexture(m_Texture);
}

bool LTexture::LoadTexture(SDL_Renderer* renderer, std::string& path)
{
	//load Image
	SDL_Surface* texSurface = IMG_Load(path.c_str());
	if (!texSurface) {
		printf("IMG_Load ERROR: %s at path: %s \n", IMG_GetError(), path.c_str());
		return false;
	}

	//Color key image
	SDL_SetColorKey(texSurface, SDL_TRUE, SDL_MapRGB(texSurface->format, 0xFF, 0xFF, 0xFF));

	//Create Tex + set width + height
	m_width = texSurface->w;
	m_height = texSurface->h;
	m_Texture = SDL_CreateTextureFromSurface(renderer, texSurface);
	if (!m_Texture) {
		printf("Texture Loading ERROR: %s at path : %s \n", SDL_GetError(), path.c_str());
	}
	SDL_FreeSurface(texSurface);

	//Set standards for CuttedRec, DestRec
	m_CuttedTex.w = m_width;
	m_CuttedTex.h = m_height;
	m_DestTex.w = m_width;
	m_DestTex.h = m_height;

	return true;
}

bool LTexture::LoadTexture(SDL_Renderer* renderer, std::string& path, Uint8 r, Uint8 g, Uint8 b)
{
	//load Image
	SDL_Surface* texSurface = IMG_Load(path.c_str());
	if (!texSurface) {
		printf("IMG_Load ERROR: %s at path: %s \n", IMG_GetError(), path.c_str());
		return false;
	}

	//Color key image
	if (SDL_SetColorKey(texSurface, SDL_TRUE, SDL_MapRGB(texSurface->format, r, g, b)) < 0) {
		printf("SetColorKey ERROR: %s at path : %s \n", SDL_GetError(), path.c_str());
	}

	//Create Tex + set width + height
	m_width = texSurface->w;
	m_height = texSurface->h;
	m_Texture = SDL_CreateTextureFromSurface(renderer, texSurface);
	if (!m_Texture) {
		printf("Texture Loading ERROR: %s at path : %s \n", SDL_GetError(), path.c_str());
	}
	SDL_FreeSurface(texSurface);

	//Set standards for CuttedRec, DestRec
	m_CuttedTex.w = m_width;
	m_CuttedTex.h = m_height;
	m_DestTex.w = m_width;
	m_DestTex.h = m_height;

	return true;
}

bool LTexture::Render(SDL_Renderer* renderer)
{
	if (SDL_RenderCopy(renderer, m_Texture, &m_CuttedTex, &m_DestTex) < 0) {
		printf("ERROR in Rendering Text: %s ", SDL_GetError());
		return false;
	}
	return true;
}

void LTexture::CutTexture(int x, int y, int width, int height)
{
	m_CuttedTex = { x, y, width, height };
}

void LTexture::CutTexture(ShapeRec& Rect)
{
	m_CuttedTex = Rect.GetShape();
}

void LTexture::DestTexture(int x, int y, int width, int height)
{
	m_DestTex = { x, y, width, height };
}

void LTexture::DestTexture(ShapeRec& Rect)
{
	m_DestTex = Rect.GetShape();
}

void LTexture::DestTexture(int x, int y)
{
	m_DestTex = { x , y, m_DestTex.w, m_DestTex.h };
}

void LTexture::AdjustBoarders()
{
	m_DestTex.w = m_CuttedTex.w;
	m_DestTex.h = m_DestTex.h;
}

const SDL_Rect& LTexture::getCuttedRec() const
{
	return m_CuttedTex;
}

const SDL_Rect& LTexture::getDestRec() const
{
	return m_DestTex;
}

const SDL_Texture* LTexture::getTexture() const
{
	return m_Texture;
}


