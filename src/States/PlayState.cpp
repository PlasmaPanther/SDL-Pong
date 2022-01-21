#include "PlayState.h"
#include "../Input.h"
#include "../Application.h"

PlayState PlayState::s_Instance;

bool PlayState::onEnter() {
	printf("Entering Play state\n");

	Player.Place();
	AI.Place();
	Ball.Place();

	PressEnterKey.Load("Moonrising.ttf", 32, "Press enter key to play again", Colors::WHITE);
	PressEscKey.Load("Moonrising.ttf", 32, "Press esc key to exit", Colors::WHITE);

	return true;
}

void PlayState::Render() {
	Player.Render();
	AI.Render();
	Ball.Render();
	Line.DrawLine(Vector2(400, 0), Vector2(400, 600), Colors::WHITE);
}

void PlayState::Update() {

	if (Ball::GetVictory() == false) { //if no one has claimed victory everything is moving and getting updated
		                              //if victory is claimed however eveything freezes
		Player.Update();
		AI.Update();
		Ball.Update();
	}
	else {

		PressEnterKey.DrawText(140, 200);
		PressEscKey.DrawText(235, 400);

		if (Input::Keydown(SDL_SCANCODE_RETURN)) { //and doesn't move until the enter key is pressed
			Ball.Reset();
		}

		if (Input::Keydown(SDL_SCANCODE_ESCAPE)) { //if esc key is pressed then program ends
			Application::ShutDown();
		}
	}
}

bool PlayState::onExit() {
	printf("Exiting Play state\n");

	Ball.Clean(); //frees fonts
	PressEnterKey.FreeFont();
	PressEscKey.FreeFont();

	return true;
}

PlayState* PlayState::GetInstance() {
	return &s_Instance;
}