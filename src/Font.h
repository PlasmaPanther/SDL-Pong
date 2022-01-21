#pragma once
#include "Object2D.h"
#include <string>

class Font: public Object2D
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
	void Load(std::string fontname, uint32_t size, std::string text, SDL_Color color);

	//Loads font, takes numerical value and turns it to text
	//\param
	//   \param fontname - name of font (example.ttf)
	//   \param size - size of text
	//   \param val - value that will be turned to text (could also be a variable)
	//   \param color - text to render in desired color (use the color namespace in Graphics.h or declare SDL_Color for custom color)
	void LoadToText(std::string fontname, uint32_t size, int val, SDL_Color color);

	//Changes text
	//\param
	//   \param text - text to change to
	//   \color - color to render in (use the color namespace in Graphics.h or declare SDL_Color for custom color)
	void ChangeText(std::string text, SDL_Color color);

	//Changes numerical value to text
	//\param
	//   \param val - value to change to text (can also use declared variable)
	//   \param color - color to render in (use the color namespace in Graphics.h or declare SDL_Color for custom color)
	void ChangeToText(int val, SDL_Color color);

	void DrawText(int x, int y);

	void FreeFont();

private:
	
	SDL_Texture* tex;
	SDL_Surface* surf;
	TTF_Font* font;
	
};

