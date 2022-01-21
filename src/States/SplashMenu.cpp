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

	Title.DrawText(310, 200);
	PressEnter.DrawText(250, 300);
	PressEsc.DrawText(270, 350);

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