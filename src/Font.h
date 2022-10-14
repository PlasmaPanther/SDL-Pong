#pragma once
#include <string>

#include "Object2D.h"

namespace Colors {
	constexpr SDL_Color RED = { 255, 0, 0, 255 };
	constexpr SDL_Color GREEN = { 0, 255, 0, 255 };
	constexpr SDL_Color BLUE = { 0, 0, 255, 255 };
	constexpr SDL_Color YELLOW = { 255, 255, 51, 255 };
	constexpr SDL_Color BROWN = { 150, 75, 0, 255 };
	constexpr SDL_Color WHITE = { 255, 255, 255, 255 };
	constexpr SDL_Color BLACK = { 0, 0, 0, 255 };
	constexpr SDL_Color BEIGE = { 245, 245, 220, 255 };
	constexpr SDL_Color CYAN = { 0, 255, 255, 255 };
	constexpr SDL_Color ORANGE = { 255, 165, 0, 255 };
	constexpr SDL_Color PINK = { 255, 100, 180, 255 };
	constexpr SDL_Color PURPLE = { 240, 0, 255, 255 };
	constexpr SDL_Color LIME = { 180, 255, 100, 255 };
}

class Font : public Object2D
{
public:
	Font();
	~Font();

	//Loads text
	//\param
	// 	 \param fontname - name of font (example.ttf)
	//   \param size - size of text
	//   \param text - text to render
	//   \param color - text to render in desired color (use the color namespace in Graphics.h or declare SDL_Color for custom color)
	void Load(const std::string& fontname, uint32_t size, const std::string& text, SDL_Color color);

	//Loads text
	//\param
	// 	 \param fontname - name of font (example.ttf)
	//   \param size - size of text
	//   \param text - text to render
	//   \param color - text to render in desired color (use the color namespace or declare SDL_Color for custom color)
	void Load(const std::string& fontname, Vector2 _pos, uint32_t size, const std::string& text, SDL_Color color);

	//Loads font, takes numerical value and turns it to text
	//\param
	//   \param fontname - name of font (example.ttf)
	//   \param size - size of text
	//   \param val - value that will be turned to text (could also be a variable)
	//   \param color - text to render in desired color (use the color namespace or declare SDL_Color for custom color)
	void LoadToText(const std::string& fontname, uint32_t size, int val, SDL_Color color);

	//Changes text
	//\param
	//   \param text - text to change to
	//   \color - color to render in (use the color namespace in Graphics.h or declare SDL_Color for custom color)
	void ChangeText(const std::string& text, SDL_Color color);

	//Changes numerical value to text
	//\param
	//   \param val - value to change to text (can also use declared variable)
	//   \param color - color to render in (use the color namespace in Graphics.h or declare SDL_Color for custom color)
	void ChangeToText(int val, SDL_Color color);

	void Render(bool renderFlag = true);
	void Render(Vector2 _pos, bool renderFlag = true);

	void Move(Vector2 _vec);

	void FreeFont();

private:

	SDL_Texture* m_FontTexture;
	SDL_Surface* m_FontSurface;
	TTF_Font* m_Font;

};

