#pragma once
#include "GameState.h"
#include "../Font.h"
#include <vector>

class Shape2D;

class SplashMenu: public GameState
{
public:
	void Render();
	void Update();

	bool onEnter();
	bool onExit();

	static SplashMenu* GetInstance();

private:

	static SplashMenu s_Instance;

	Font Title;
	Font PressEnter;
	Font PressEsc;

};

