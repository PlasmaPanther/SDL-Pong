#pragma once
#include "Shape2D.h"

class AIPaddle
{
public:
	AIPaddle() = default;
	~AIPaddle() = default;

	void Place();
	void Render();
	void Update();

private:

	Shape2D m_AIPaddle;

	Vector2 m_AiVelocity;

};

