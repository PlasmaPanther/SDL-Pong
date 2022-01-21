#include "AIPaddle.h"
#include "Ball.h"

SDL_Rect AIPaddle::AIPaddle_Rect;
int AIPaddle::ai_score;

void AIPaddle::Place() {
	
	AiPaddle.PlaceRect(Vector2(755, 300), 15, 60);
	AIPaddle_Rect = AiPaddle.GetRect();

	ai_velocity.x = 0;
	ai_velocity.y = -8;

	ai_score = 0;
}

void AIPaddle::Render() {
	AiPaddle.DrawRect(255, 255, 255, 255);
}

void AIPaddle::Update() {
	SDL_Rect tmp_ball = Ball::GetBall();

	//Boundary check
	if (AIPaddle_Rect.y <= 0) {
		AIPaddle_Rect.y = 0;
	}
	if (AIPaddle_Rect.y + AIPaddle_Rect.h >= 600) {
		AIPaddle_Rect.y = 600 - AIPaddle_Rect.h;
	}

	//Determine when the AI starts moving based on the ball X pos; increase value for easier AI; 650 and higher is easiest
	//also ball has to be in front of the ai paddle
	if (tmp_ball.x >= 450 && tmp_ball.x + tmp_ball.w <= AIPaddle_Rect.x) {

		if (tmp_ball.y < AIPaddle_Rect.y + AIPaddle_Rect.h / 2) { //if ball y is lower than the center of the paddle
			ai_velocity.y = -8; //move accordingly
			AiPaddle.MoveRect(ai_velocity);
		}

		if (tmp_ball.y + tmp_ball.h > AIPaddle_Rect.y + AIPaddle_Rect.h / 2) { //if ball y is higher than the center of the paddle
			ai_velocity.y = 8;
			AiPaddle.MoveRect(ai_velocity);
		}
	}

	AIPaddle_Rect = AiPaddle.GetRect(); //Keep track of ai position
}

SDL_Rect& AIPaddle::GetAIPaddleRect() {
	return AIPaddle_Rect;
}

void AIPaddle::SetAIScore(int val) {
	ai_score = val;
}

int AIPaddle::GetAIScore() {
	return ai_score;
}