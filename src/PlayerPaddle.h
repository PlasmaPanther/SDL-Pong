#pragma once
#include "Shape2D.h"

class PlayerPaddle
{
public:
	PlayerPaddle() = default;
	~PlayerPaddle() = default;

	void Place();
	void Render();
	void Update();

	static Shape2D& GetPlayerPaddleCollider();

private:

	static inline Shape2D m_PlayerCollider;

};

