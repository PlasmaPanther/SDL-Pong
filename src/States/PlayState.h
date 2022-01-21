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

	PlayerPaddle Player;
	AIPaddle AI;
	Ball Ball;
	Shape2D Line;

	Font PressEnterKey;
	Font PressEscKey;

};

