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

	Shape2D& GetPlayerPaddleCollider();

private:

	Shape2D m_Player;

};

