#pragma once
#include "GameState.h"
#include "../PlayerPaddle.h"
#include "../AIPaddle.h"
#include "../Ball.h"

class PlayState: public GameState
{
public:
	void Render();
	void Update();

	bool onEnter();
	bool onExit();

	static PlayState* GetInstance();

private:

	static PlayState s_Instance;

	PlayerPaddle m_Player;
	AIPaddle m_AI;
	Ball m_Ball;
	Shape2D m_Line;

	Font m_PressEnterKey;
	Font m_PressEscKey;

	Font m_PlayerScoreText;
	Font m_AiScoreText;

	Font m_AiVictory;
	Font m_PlayerVictory;

	int m_PlayerScore;
	int m_AiScore;
	bool m_Victory;

};

