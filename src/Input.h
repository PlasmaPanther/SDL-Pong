#pragma once
#include <SDL.h>
#include "Math.h"

class Input
{
public:

	//Continous key press
	static bool Keydown(SDL_Scancode code);

	//Singular key press
	static bool KeyPressed(SDL_Scancode code);

	static void InputUpdate(const SDL_Event& e);

private:

	static const uint8_t* m_Keystate;

	static inline SDL_Event s_InputEvent;
};