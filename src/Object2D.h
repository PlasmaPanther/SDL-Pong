#pragma once
#include "Graphics.h"
#include "Math.h"

class Object2D
{
public:
	Object2D(float x = 0.0f, float y = 0.0f);
	~Object2D() = default;

	void Move(Vector2 _vec);
	void MoveAnimated(Vector2 _vec);

	bool CheckCollision(SDL_Rect* recta, SDL_Rect* rectb);
	
	SDL_Rect* GetRect();
	SDL_Rect* GetAnimatedRect();

	void Event(const SDL_Event& e);
	void animatedEvent(const SDL_Event& e);

protected:

	SDL_Rect animated_object_destRect, animated_object_srcRect;
	SDL_Rect object_rectSrc, object_rect;

private:

	Vector2 _Vector2;

};

