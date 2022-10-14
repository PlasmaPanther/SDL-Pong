#pragma once
#include "Graphics.h"
#include "Math.h"

class Object2D
{
public:
	Object2D();
	virtual ~Object2D() = default;

	virtual void Move(Vector2 _vec) = 0;

	void SetVelocity(Vector2 _vel);
	Vector2 GetVelocity();

	SDL_FRect& GetRect();

protected:

	SDL_FRect m_DestRect;
	SDL_Rect m_SrcRect;

	Vector2 m_Velocity;

};

