#pragma once
#include "Graphics.h"
#include "States/StateMachine.h"

class Application
{
public:
	static Application* Instance();
	void DestroyInstance();
	
	void MainLoop();

	static SDL_Event GetEvent();

	static void ShutDown();

private:
	static Application* s_Instance;
	
	static SDL_Event Event;

	Graphics* m_Graphics;

	StateMachine _StateMachine;

	static bool m_Running;

	const float FPS = 60.0f;

	Application();
	~Application();
};

