#pragma once
#include "Graphics.h"
#include "Math.h"

struct Circle
{
	float x, y;
	float radius;

};

class Shape2D
{
public:
	Shape2D();
	~Shape2D() = default;

	SDL_FRect PlaceRect(Vector2 _pos, float width, float height);
	void DrawRect(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void DrawLine(Vector2 _startPos, Vector2 _endPos, SDL_Color color);
	
	void PlaceCircle(Vector2 _pos, float radius);
	void DrawCircle(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void MoveRect(Vector2 _vel);
	void MoveCircle(Vector2 _vel);

	friend bool RectangleCollision(const Shape2D& recta, const Shape2D& rectb);
	friend bool CircleCollision(const Shape2D& circlea, const Shape2D& circleb);
	friend bool CircleToRectCollision(const Shape2D& _circle, const Shape2D& rect);

	void Kill();

	void SetSpeed(Vector2 _vel);
	Vector2 GetSpeed();

	SDL_FRect& GetRect();
	
	Circle& GetCircle();

private:

	SDL_FRect m_Rect;

	Circle m_Circle;

	Vector2 _velocity;

};

