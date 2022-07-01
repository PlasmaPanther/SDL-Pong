#include "Shape2D.h"
#include <iostream>

Shape2D::Shape2D() {
	m_Rect = { 0, 0, 0, 0 };
	m_Circle = { 0, 0, 0 };
	_velocity = { 0, 0 };
}

SDL_FRect Shape2D::PlaceRect(Vector2 _pos, float width, float height) {
	m_Rect.x = _pos.x;
	m_Rect.y = _pos.y;
	m_Rect.w = width;
	m_Rect.h = height;

	return m_Rect;
}

void Shape2D::DrawRect(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(Graphics::GetRenderer(), r, g, b, a); //Sets rect color
	SDL_RenderFillRectF(Graphics::GetRenderer(), &m_Rect);
	SDL_RenderDrawRectF(Graphics::GetRenderer(), &m_Rect);
}

void Shape2D::DrawLine(Vector2 _startPos, Vector2 _endPos, SDL_Color color) {
	SDL_SetRenderDrawColor(Graphics::GetRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderDrawLineF(Graphics::GetRenderer(), _startPos.x, _startPos.y, _endPos.x, _endPos.y);
}

void Shape2D::PlaceCircle(Vector2 _pos, float radius) {
	m_Circle.x = _pos.x;
	m_Circle.y = _pos.y;
	m_Circle.radius = radius;
}

void Shape2D::DrawCircle(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {

	SDL_SetRenderDrawColor(Graphics::GetRenderer(), r, g, b, a); //sets circle color

	for (int y = 0; y < m_Circle.radius; ++y)
	{
		float x_point = sqrtf((m_Circle.radius * m_Circle.radius) - (y * y)); //Calculating the X point using the Pythagorean theorem for circles

		SDL_RenderDrawLineF(Graphics::GetRenderer(), m_Circle.x - x_point, m_Circle.y - y, m_Circle.x + x_point, m_Circle.y - y); //Draws the top half
		SDL_RenderDrawLineF(Graphics::GetRenderer(), m_Circle.x - x_point, m_Circle.y + y, m_Circle.x + x_point, m_Circle.y + y); //Draws the bottom half

	}

}

void Shape2D::MoveRect(Vector2 _vel) {
	_velocity = _vel;

	m_Rect.x += _velocity.x;
	m_Rect.y += _velocity.y;
}

void Shape2D::MoveCircle(Vector2 _vel) {
	_velocity = _vel;

	m_Circle.x += _velocity.x;
	m_Circle.y += _velocity.y;
}

bool RectangleCollision(const Shape2D& recta, const Shape2D& rectb) {
	
	SDL_FRect RectA = recta.m_Rect;
	SDL_FRect RectB = rectb.m_Rect;

	if (RectA.y + RectA.h <= RectB.y) {
		return false;
	}

	if (RectA.y >= RectB.y + RectB.h) {
		return false;
	}

	if (RectA.x + RectA.w <= RectB.x) {
		return false;
	}

	if (RectA.x >= RectB.x + RectB.w) {
		return false;
	}

	return true;
}

bool CircleCollision(const Shape2D& circlea, const Shape2D& circleb) {
	float deltaX = circlea.m_Circle.x;
	float deltaY = circleb.m_Circle.y;

	float distance = sqrtf(deltaX * deltaX + deltaY * deltaY);

	float totalRadius = circlea.m_Circle.radius + circleb.m_Circle.radius;

	if (distance < totalRadius) {
		return true;
	}

	return false;
}

bool CircleToRectCollision(const Shape2D& _circle, const Shape2D& rect) {
	float HorizontalEdges = _circle.m_Circle.x;
	float VerticalEdges = _circle.m_Circle.y;

	//check to see if cirlce or rect edge is closer
	if (_circle.m_Circle.x < rect.m_Rect.x) {
		HorizontalEdges = rect.m_Rect.x; //try left edges
	}
	else if (_circle.m_Circle.x > rect.m_Rect.x + rect.m_Rect.w) {
		HorizontalEdges = rect.m_Rect.x + rect.m_Rect.w; //try right edges
	}

	if (_circle.m_Circle.y < rect.m_Rect.y) {
		VerticalEdges = rect.m_Rect.y; //top edges
	}
	else if (_circle.m_Circle.y > rect.m_Rect.y + rect.m_Rect.h) {
		VerticalEdges = rect.m_Rect.y + rect.m_Rect.h; //bottom edges
	}

	//get distance from closest edges
	float distanceX = _circle.m_Circle.x - HorizontalEdges;
	float distanceY = _circle.m_Circle.y - VerticalEdges;
	float distance = sqrtf((distanceX * distanceX) + (distanceY * distanceY));

	//if the distance is less than the radius then there is collision
	if (distance <= _circle.m_Circle.radius) {
		return true;
	}

	return false;
}

void Shape2D::Kill() {
	_velocity = { 0, 0 };
	m_Rect = { 0, 0, 0, 0 };
	m_Circle = { 0, 0, 0 };
}

void Shape2D::SetSpeed(Vector2 _vel) {
	_velocity = _vel;
}

Vector2 Shape2D::GetSpeed() {
	return _velocity;
}

SDL_FRect& Shape2D::GetRect() {
	return m_Rect;
}

Circle& Shape2D::GetCircle() {
	return m_Circle;
}