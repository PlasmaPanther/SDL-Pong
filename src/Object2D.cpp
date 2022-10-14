#include "Object2D.h"

Object2D::Object2D() {

	m_DestRect = { 0, 0, 0, 0 };
	m_SrcRect = { 0, 0, 0, 0 };

	m_Velocity = { 0, 0 };
}

void Object2D::SetVelocity(Vector2 _vel)
{
	m_Velocity = _vel;
}

Vector2 Object2D::GetVelocity()
{
	return m_Velocity;
}

SDL_FRect& Object2D::GetRect()
{
	return m_DestRect;
}