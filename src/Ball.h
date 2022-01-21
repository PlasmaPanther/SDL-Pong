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
	void Clean();

	static SDL_Rect& GetBall();
	static bool GetVictory();

private:

	Shape2D m_Ball;

	static inline SDL_Rect ball;
	static inline bool victory;

	Vector2 starting_position;
	Vector2 ball_velocity;

	int player_score;
	int ai_score;

	bool player_victory;
	bool ai_victory;

	Font player_scoreText;
	Font ai_scoreText;

	Font PlayerVictoryText;
	Font AIVictoryText;

};

