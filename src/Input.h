#pragma once
#include <SDL.h>
#include "Math.h"

class Input
{
public:

	static bool Keydown(SDL_Scancode code);

	static void InputUpdate();

	//===Experimental functions===//
	static void MouseUpdate(const SDL_Event& e);
	static bool MouseClickLeft();
	static bool MouseClickRight();
	static bool MouseIsMoving();
	//===========================//

	static Vector2 GetMousePos();

private:
	Input() = default;
	~Input() = default;

	static const uint8_t* m_Keystate;
	static int MouseX;
	static int MouseY;

};

