#include "Input.h"
#include "Application.h"

const uint8_t* Input::m_Keystate;
int Input::MouseX;
int Input::MouseY;

bool Input::Keydown(SDL_Scancode code) {
	return m_Keystate[code];
}

void Input::InputUpdate() {
	m_Keystate = SDL_GetKeyboardState(nullptr);
}

void Input::MouseUpdate(const SDL_Event& e) {
	
	if (e.type == SDL_MOUSEMOTION) {
		MouseX = e.motion.x;
		MouseY = e.motion.y;
	}

}

bool Input::MouseClickLeft() {
	SDL_Event e = Application::GetEvent();

	if (e.type == SDL_MOUSEBUTTONDOWN) {
		if (e.button.button == SDL_BUTTON_LEFT) {
			MouseX = e.button.x;
			MouseY = e.button.y;

			return true;
		}
	}

	return false;
}

bool Input::MouseClickRight() {
	SDL_Event e = Application::GetEvent();

	if (e.type == SDL_MOUSEBUTTONDOWN) {
		if (e.button.button == SDL_BUTTON_RIGHT) {
			MouseX = e.button.x;
			MouseY = e.button.y;

			return true;
		}
	}

	return false;
}

bool Input::MouseIsMoving() {
	SDL_Event e = Application::GetEvent();

	if (e.type == SDL_MOUSEMOTION) {
		return true;
	}

	return false;
}

Vector2 Input::GetMousePos() {
	return Vector2(MouseX, MouseY);
}