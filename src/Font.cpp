#include "Font.h"

Font::Font() {
	if (TTF_Init() == -1) {
		printf("Font module could not start: %s\n", TTF_GetError());
	}

	surf = nullptr;
	tex = nullptr;
	font = nullptr;
}

Font::~Font() {

	if (surf) {
		SDL_FreeSurface(surf);
		surf = nullptr;
	}

	if (tex) {
		SDL_DestroyTexture(tex);
		tex = nullptr;
	}

	if (font) {
		TTF_CloseFont(font);
		font = nullptr;
	}
	
	TTF_Quit();
}

void Font::Load(std::string fontname, uint32_t size, std::string text, SDL_Color color) {
	
	std::string fontpath = "Resources/Fonts/" + fontname;

	if (!font) {
		font = TTF_OpenFont(fontpath.c_str(), size);
	}

	if (!surf) {
		surf = TTF_RenderText_Solid(font, text.c_str(), color);
	}

	if (!tex) {
		tex = SDL_CreateTextureFromSurface(Graphics::GetRenderer(), surf);
	}

	SDL_free(&fontpath); //frees the returned pointer from SDL_GetBasePath()
}

void Font::LoadToText(std::string fontname, uint32_t size, int val, SDL_Color color) {

	std::string val_to_str = std::to_string(val);

	this->Load(fontname, size, val_to_str, color);

}

void Font::DrawText(int x, int y) {

	if (surf) { //Prevents annoying segfault when switching between states
		object_rect.x = x;
		object_rect.y = y;
		object_rect.w = surf->w;
		object_rect.h = surf->h;

		SDL_RenderCopy(Graphics::GetRenderer(), tex, nullptr, &object_rect);
	}
}

void Font::ChangeText(std::string text, SDL_Color color) {

	SDL_DestroyTexture(tex);
	tex = nullptr;

	SDL_FreeSurface(surf);
	surf = nullptr;

	surf = TTF_RenderText_Solid(font, text.c_str(), color);
	tex = SDL_CreateTextureFromSurface(Graphics::GetRenderer(), surf);

}

void Font::ChangeToText(int val, SDL_Color color) {

	std::string val_to_str = std::to_string(val);
	this->ChangeText(val_to_str, color);

}

void Font::FreeFont() {

	TTF_CloseFont(font);
	font = nullptr;

	SDL_DestroyTexture(tex);
	tex = nullptr;

	SDL_FreeSurface(surf);
	surf = nullptr;

	printf("font freed\n");

}