#include "Shape2D.h"
#include <iostream>

Shape2D::Shape2D() {
	m_rect = { 0, 0, 0, 0 };
	circle = { 0, 0, 0 };
	_velocity = { 0, 0 };
}

SDL_Rect Shape2D::PlaceRect(Vector2 _pos, int width, int height) {
	m_rect.x = _pos.x;
	m_rect.y = _pos.y;
	m_rect.w = width;
	m_rect.h = height;

	return m_rect;
}

void Shape2D::DrawRect(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(Graphics::GetRenderer(), r, g, b, a); //Sets rect color
	SDL_RenderFillRect(Graphics::GetRenderer(), &m_rect);
	SDL_RenderDrawRect(Graphics::GetRenderer(), &m_rect);
}

void Shape2D::DrawLine(Vector2 _startPos, Vector2 _endPos, SDL_Color color) {
	SDL_SetRenderDrawColor(Graphics::GetRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(Graphics::GetRenderer(), _startPos.x, _startPos.y, _endPos.x, _endPos.y);
}

void Shape2D::PlaceCircle(Vector2 _pos, int radius) {
	circle.x = _pos.x;
	circle.y = _pos.y;
	circle.radius = radius;
}

void Shape2D::DrawCircle(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {

	SDL_SetRenderDrawColor(Graphics::GetRenderer(), r, g, b, a); //sets circle color

	for (int y = 0; y < circle.radius; ++y)
	{
		float x_point = sqrtf((circle.radius * circle.radius) - (y * y)); //Calculating the X point using the Pythagorean theorem for circles

		SDL_RenderDrawLine(Graphics::GetRenderer(), circle.x - x_point, circle.y - y, circle.x + x_point, circle.y - y); //Draws the top half
		SDL_RenderDrawLine(Graphics::GetRenderer(), circle.x - x_point, circle.y + y, circle.x + x_point, circle.y + y); //Draws the bottom half

	}

}

void Shape2D::MoveRect(Vector2 _vel) {
	_velocity = _vel;

	m_rect.x += _velocity.x;
	m_rect.y += _velocity.y;
}

void Shape2D::MoveCircle(Vector2 _vel) {
	_velocity = _vel;

	circle.x += _velocity.x;
	circle.y += _velocity.y;
}

bool Shape2D::RectangleCollision(SDL_Rect& recta, SDL_Rect& rectb) {
	if (SDL_HasIntersection(&recta, &rectb)) {
		return true;
	}

	return false;
}

bool Shape2D::CircleCollision(Circle& circlea, Circle& circleb) {
	float deltaX = circlea.x - circleb.x;
	float deltaY = circlea.y - circleb.y;

	float distance = sqrtf(deltaX * deltaX + deltaY * deltaY);

	float totalRadius = circlea.radius + circleb.radius;

	if (distance < totalRadius) {
		return true;
	}

	return false;
}

bool Shape2D::CircleToRectCollision(Circle& _circle, SDL_Rect& rect) {
	float HorizontalEdges = _circle.x;
	float VerticalEdges = _circle.y;

	//check to see if cirlce or rect edge is closer
	if (_circle.x < rect.x) {
		HorizontalEdges = rect.x; //try left edges
	}
	else if (_circle.x > rect.x + rect.w) {
		HorizontalEdges = rect.x + rect.w; //try right edges
	}

	if (_circle.y < rect.y) {
		VerticalEdges = rect.y; //top edges
	}
	else if (_circle.y > rect.y + rect.h) {
		VerticalEdges = rect.y + rect.h; //bottom edges
	}

	//get distance from closest edges
	float distanceX = _circle.x - HorizontalEdges;
	float distanceY = _circle.y - VerticalEdges;
	float distance = sqrtf((distanceX * distanceX) + (distanceY * distanceY));

	//if the distance is less than the radius then there is collision
	if (distance <= _circle.radius) {
		return true;
	}

	return false;
}

void Shape2D::Kill() {
	_velocity = { 0, 0 };
	m_rect = { 0, 0, 0, 0 };
	circle = { 0, 0, 0 };
}

void Shape2D::SetSpeed(Vector2 _vel) {
	_velocity = _vel;
}

Vector2 Shape2D::GetSpeed() {
	return _velocity;
}

SDL_Rect& Shape2D::GetRect() {
	return m_rect;
}

Circle& Shape2D::GetCircle() {
	return circle;
}