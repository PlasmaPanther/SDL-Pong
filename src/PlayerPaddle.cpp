#include "PlayerPaddle.h"
#include "Input.h"

int PlayerPaddle::player_score;
SDL_Rect PlayerPaddle::PlayerRect;

void PlayerPaddle::Place() {
	
	Player.PlaceRect(Vector2(30, 300), 15, 60);
	PlayerRect = Player.GetRect();
	player_score = 0;
}

void PlayerPaddle::Render() {
	Player.DrawRect(255, 255, 255, 255);
}

void PlayerPaddle::Update() {

	if (Input::Keydown(SDL_SCANCODE_UP)) {
		Player.MoveRect(Vector2(0, -8));
	}

	if (Input::Keydown(SDL_SCANCODE_DOWN)) {
		Player.MoveRect(Vector2(0, 8));
	}

	//Boundary check
	if (Player.GetRect().y <= 0) {
		Player.GetRect().y = 0;
	}

	if (Player.GetRect().y + Player.GetRect().h >= 600) {
		Player.GetRect().y = 600 - Player.GetRect().h;
	}

	PlayerRect = Player.GetRect(); //Keep track of player position
}

SDL_Rect& PlayerPaddle::GetPlayerPaddle() {
	return PlayerRect;
}

void PlayerPaddle::SetPlayerScore(int val) {
	player_score = val;
}

int PlayerPaddle::GetPlayerScore() {
	return player_score;
}