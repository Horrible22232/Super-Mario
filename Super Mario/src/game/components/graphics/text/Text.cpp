#include "stdafx.h"
#include "Text.h"

TTF_Font* Text::m_Font;



Text::Text()
{
}

Text::~Text()
{
	if (m_Texture != NULL) {
		SDL_DestroyTexture(m_Texture);
	}
}

bool Text::Init(std::string path)
{
	if (m_Font != NULL) return false;
	m_Font = TTF_OpenFont(path.c_str(), 16);
	if (!m_Font) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		return false;
	}
	//set standart color Black
	SetColor(COLOR_BLACK);
	return true;
}

bool Text::Render(SDL_Renderer* renderer)
{
	if (SDL_RenderCopy(renderer, m_Texture, NULL, &m_DestText) < 0) {
		printf("ERROR in Rendering Text: %s ", SDL_GetError());
		return false;
	}
	return true;
}

bool Text::RenderBoarders(SDL_Renderer* renderer)
{
	if (SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00) < 0) {
		printf("SetRenderDrawColor ERROR: %s", SDL_GetError());
		return false;
	}
	if (SDL_RenderDrawRect(renderer, &m_DestText) < 0) {
		printf("RenderBoarders ERROR: %s", SDL_GetError());
		return false;
	}
	return true;
}

bool Text::RenderBoarders(SDL_Renderer * renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	if (SDL_SetRenderDrawColor(renderer, red, green, blue, alpha) < 0) {
		printf("SetRenderDrawColor ERROR: %s", SDL_GetError());
		return false;
	}
	if (SDL_RenderDrawRect(renderer, &m_DestText) < 0) {
		printf("RenderBoarders ERROR: %s", SDL_GetError());
		return false;
	}
	return true;
}

bool Text::SetText(SDL_Renderer* renderer, std::string& text)
{
	if (m_Font == NULL) {
		printf("Init first");
	}
	//check valid Renderer
	if (renderer == NULL) {
		printf("Bad Renderer passed");
		return false;
	}
	
	//else point to Renderer
	m_Renderer = renderer;

	//copy text 
	m_text = text;
	//load Text
	SDL_Surface* texSurface = TTF_RenderText_Solid(m_Font, m_text.c_str(), m_Color);
	if (!texSurface) {
		printf("Text_Load ERROR: %s at string: %s \n", TTF_GetError(), m_text.c_str());
		return false;
	}

	//Create Text + set width + height
	m_Texture = SDL_CreateTextureFromSurface(renderer, texSurface);
	if (!m_Texture) {
		printf("Texture Loading ERROR: %s at string : %s \n", SDL_GetError(), m_text.c_str());
	}
	SDL_FreeSurface(texSurface);
}

void Text::DestText(int x, int y, int width, int height)
{
	m_DestText = { x, y, width, height };
}

void Text::DestText(ShapeRec& Rect)
{
	m_DestText = Rect.GetShape();
}

void Text::SetColor(Color color) //first color THEN setText!
{
	switch (color) {
	case COLOR_RED:
		m_Color = { 0xFF, 0x00, 0x00 };
		break;
	case COLOR_ORANGE:
		m_Color = { 0xFF, 0xA5, 0x00 };
		break;
	case COLOR_YELLOW:
		m_Color = { 0xFF, 0xFF, 0x00 };
		break;
	case COLOR_GREEN:
		m_Color = { 0x00, 0x8B, 0x00 };
		break;
	case COLOR_BLUE:
		m_Color = { 0x00, 0x00, 0xFF };
		break;
	case COLOR_VIOLET:
		m_Color = { 0xEE, 0x82, 0xEE };
		break;
	case COLOR_BLACK:
		m_Color = { 0x00, 0x00, 0x00};
		break;
	default:
		m_Color = { 0x00, 0x00, 0x00 };
		break;
	}
	SetText(m_Renderer, m_text);
}

void Text::DestText(int x, int y)
{
	m_DestText = { x , y, m_DestText.w, m_DestText.h };
}


const SDL_Rect& Text::GetDestRec() const
{
	return m_DestText;
}

void Text::free()
{
	if (m_Font != NULL) {
		TTF_CloseFont(m_Font);
	}
}

