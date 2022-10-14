#include "Input.h"
#include "Application.h"

const uint8_t* Input::m_Keystate;

bool Input::Keydown(SDL_Scancode code) {
	return m_Keystate[code];
}

bool Input::KeyPressed(SDL_Scancode code)
{

	if (s_InputEvent.type == SDL_KEYDOWN && s_InputEvent.key.repeat == 0) {
		return m_Keystate[code];
	}

	return false;
}

void Input::InputUpdate(const SDL_Event& e) {
	s_InputEvent = e;
	m_Keystate = SDL_GetKeyboardState(nullptr);
}