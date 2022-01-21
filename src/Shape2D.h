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

	SDL_Rect PlaceRect(Vector2 _pos, int width, int height);
	void DrawRect(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void DrawLine(Vector2 _startPos, Vector2 _endPos, SDL_Color color);
	
	void PlaceCircle(Vector2 _pos, int radius);
	void DrawCircle(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void MoveRect(Vector2 _vel);
	void MoveCircle(Vector2 _vel);

	static bool RectangleCollision(SDL_Rect& recta, SDL_Rect& rectb);
	static bool CircleCollision(Circle& circlea, Circle& circleb);
	static bool CircleToRectCollision(Circle& _circle, SDL_Rect& rect);

	void Kill();

	void SetSpeed(Vector2 _vel);
	Vector2 GetSpeed();

	SDL_Rect& GetRect();
	
	Circle& GetCircle();

private:

	SDL_Rect m_rect;

	Circle circle;

	Vector2 _velocity;

};

