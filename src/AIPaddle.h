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

	static SDL_Rect& GetAIPaddleRect();
	static void SetAIScore(int val);
	static int GetAIScore();

private:

	Shape2D AiPaddle;

	static SDL_Rect AIPaddle_Rect;
	Vector2 ai_velocity;

	static int ai_score;

};

