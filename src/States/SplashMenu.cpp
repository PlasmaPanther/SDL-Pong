#include "SplashMenu.h"
#include "../Input.h"
#include "StateMachine.h"
#include "PlayState.h"
#include "../Application.h"

SplashMenu SplashMenu::s_Instance;

bool SplashMenu::onEnter() {
	printf("Entering Splash menu\n");

	Title.Load("Moonrising.ttf", 48, "Pong", Colors::RED);
	PressEnter.Load("Moonrising.ttf", 24, "Press Enter to begin", Colors::RED);
	PressEsc.Load("Moonrising.ttf", 24, "Press Esc to exit", Colors::RED);
	
	return true;
}

void SplashMenu::Render() {

	Title.Render(Vector2(310, 200));
	PressEnter.Render(Vector2(250, 300));
	PressEsc.Render(Vector2(270, 350));

}

void SplashMenu::Update() {
	if (Input::Keydown(SDL_SCANCODE_RETURN)) {
		StateMachine::switchState(PlayState::GetInstance());
	}

	if (Input::Keydown(SDL_SCANCODE_ESCAPE)) {
		Application::ShutDown();
	}
}

bool SplashMenu::onExit() {
	printf("Exiting Splash menu\n");

	Title.FreeFont();
	PressEnter.FreeFont();
	PressEsc.FreeFont();

	return true;
}

SplashMenu* SplashMenu::GetInstance() {
	return &s_Instance;
}