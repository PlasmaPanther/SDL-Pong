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

	static Shape2D& GetAIPaddleCollider();

private:

	static inline Shape2D m_AIPaddleCollider;

	Vector2 m_AiVelocity;

};

