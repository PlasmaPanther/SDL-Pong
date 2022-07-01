#pragma once
#include "Shape2D.h"
#include "Font.h"

class Ball
{
public:
	Ball() = default;
	~Ball() = default;

	void Place();

	void Render();
	void Update();
	
	void ResetPosition();
	
	void Reset();

	static SDL_FRect& GetBallCollider();

private:

	static inline Shape2D m_BallCollider;

	static inline SDL_FRect m_BallColliderRect;

	Vector2 m_StartingPosition;
	Vector2 m_BallVelocity;

};

