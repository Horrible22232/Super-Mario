#include "stdafx.h"
#include "LTexture.h"
#include <SDL_image.h>


LTexture::LTexture() :
	m_Texture(NULL), m_width(0), m_height(0)
{
}


LTexture::~LTexture()
{
	SDL_DestroyTexture(m_Texture);
}

bool LTexture::LoadTexture(SDL_Renderer* renderer, std::string path)
{
	//check valid Renderer
	if (renderer == NULL) {
		printf("Bad Renderer passed");
		return false;
	}

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

bool LTexture::LoadTexture(SDL_Renderer* renderer, std::string path, Uint8 r, Uint8 g, Uint8 b)
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

bool LTexture::RenderBoarders(SDL_Renderer* renderer)
{
	if (SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00) < 0) {
		printf("SetRenderDrawColor ERROR: %s", SDL_GetError());
		return false;
	}
	if (SDL_RenderDrawRect(renderer, &m_DestTex) < 0) {
		printf("RenderBoarders ERROR: %s", SDL_GetError());
		return false;
	}
	return true;
}

bool LTexture::RenderBoarders(SDL_Renderer * renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	if (SDL_SetRenderDrawColor(renderer, red, green, blue, alpha) < 0) {
		printf("SetRenderDrawColor ERROR: %s", SDL_GetError());
		return false;
	}
	if (SDL_RenderDrawRect(renderer, &m_DestTex) < 0) {
		printf("RenderBoarders ERROR: %s", SDL_GetError());
		return false;
	}
	return true;
}

bool LTexture::SetAlphaMod(Uint8 alpha)
{
	if (SDL_SetTextureBlendMode(m_Texture, SDL_BLENDMODE_BLEND) < 0) {
		printf("ERROR in setting Blend Mode: %s", SDL_GetError());
		return false;
	}

	if (SDL_SetTextureAlphaMod(m_Texture, alpha)) {
		printf("ERROR in setting Alpha Mode: %s", SDL_GetError());
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

const SDL_Rect& LTexture::GetCuttedRec() const
{
	return m_CuttedTex;
}

const SDL_Rect& LTexture::GetDestRec() const
{
	return m_DestTex;
}

const SDL_Texture* LTexture::GetTexture() const
{
	return m_Texture;
}


