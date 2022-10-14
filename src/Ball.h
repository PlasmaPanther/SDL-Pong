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

private:

	Shape2D m_Ball;

	Vector2 m_StartingPosition;
	Vector2 m_BallVelocity;

};

