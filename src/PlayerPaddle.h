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

	static SDL_Rect& GetPlayerPaddle();
	static void SetPlayerScore(int val);
	static int GetPlayerScore();

private:
	static SDL_Rect PlayerRect;
	Shape2D Player;
	static int player_score;

};

