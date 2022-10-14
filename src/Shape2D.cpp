#include "Shape2D.h"
#include <iostream>

Shape2D::Shape2D() {

	m_Velocity = { 0, 0 };

	m_Circle = { 0, 0, 0 };

	m_Radius = 0.0f;
}

void Shape2D::Place(Vector2 _pos, float _radius)
{

	m_Circle.x = _pos.x;
	m_Circle.y = _pos.y;
	m_Circle.radius = _radius;

	m_Radius = _radius;
}

void Shape2D::Place(Vector2 _pos, Vector2 _scale)
{
	m_DestRect.x = _pos.x;
	m_DestRect.y = _pos.y;

	m_DestRect.w = _scale.x;
	m_DestRect.h = _scale.y;

}

void Shape2D::PlaceLine(Vector2 sp, Vector2 ep, SDL_Color color, uint8_t a)
{
	SDL_SetRenderDrawColor(Graphics::GetRenderer(), color.r, color.g, color.b, a); //Sets rect color
	SDL_RenderDrawLineF(Graphics::GetRenderer(), sp.x, sp.y, ep.x, ep.y);
}

void Shape2D::RenderRect(uint8_t r, uint8_t g, uint8_t b, uint8_t a, bool renderFlag)
{
	if (renderFlag) {

		SDL_SetRenderDrawColor(Graphics::GetRenderer(), r, g, b, a); //Sets rect color
		SDL_RenderDrawRectF(Graphics::GetRenderer(), &m_DestRect);
		SDL_RenderFillRectF(Graphics::GetRenderer(), &m_DestRect);
	}
}

void Shape2D::RenderCircle(uint8_t r, uint8_t g, uint8_t b, uint8_t a, bool renderFlag) {

	if (renderFlag) {

		SDL_SetRenderDrawColor(Graphics::GetRenderer(), r, g, b, a); //sets circle color

		for (int y = 0; y < m_Circle.radius; ++y)
		{
			float x_point = sqrtf((m_Circle.radius * m_Circle.radius) - (y * y)); //Calculating the X point using the Pythagorean theorem for circles

			SDL_RenderDrawLineF(Graphics::GetRenderer(), m_Circle.x - x_point, m_Circle.y - y, m_Circle.x + x_point, m_Circle.y - y); //Draws the top half
			SDL_RenderDrawLineF(Graphics::GetRenderer(), m_Circle.x - x_point, m_Circle.y + y, m_Circle.x + x_point, m_Circle.y + y); //Draws the bottom half

		}
	}
}

void Shape2D::Move(Vector2 _vec)
{
	m_Velocity = _vec;

	m_Circle.x += m_Velocity.x;
	m_Circle.y += m_Velocity.y;

	m_DestRect.x += m_Velocity.x;
	m_DestRect.y += m_Velocity.y;
}

void Shape2D::Kill() {
	m_DestRect = { 0, 0, 0, 0 };
	m_Circle = { 0, 0, 0 };
}

Circle& Shape2D::GetCircle() {
	return m_Circle;
}