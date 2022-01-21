#include "Ball.h"
#include "PlayerPaddle.h"
#include "AIPaddle.h"
#include <random>

void Ball::Place(){
	victory = false;
	player_victory = false;
	ai_victory = false;

	starting_position.x = 400;
	starting_position.y = 300;

	m_Ball.PlaceRect(starting_position, 20, 20);

	ball_velocity.x = 6;
	ball_velocity.y = 6;

	this->player_score = 0;
	this->ai_score = 0;

	player_scoreText.LoadToText("Moonrising.ttf", 36, player_score, Colors::WHITE);
	ai_scoreText.LoadToText("Moonrising.ttf", 36, ai_score, Colors::WHITE);

	PlayerVictoryText.Load("Moonrising.ttf", 36, "Player has won", Colors::WHITE);
	AIVictoryText.Load("Moonrising.ttf", 36, "AI has won", Colors::WHITE);
}

void Ball::Render() {
	m_Ball.DrawRect(255, 255, 255, 255);

	player_scoreText.DrawText(250, 30);
	ai_scoreText.DrawText(550, 30);

	if (player_victory) {
		PlayerVictoryText.DrawText(30, 100);
	}

	if (ai_victory) {
		AIVictoryText.DrawText(420, 100);
	}

}

void Ball::Update() {

	std::random_device randomizer; //randomize numbers
	std::mt19937 gen(randomizer()); //apply seed
	std::uniform_int_distribution<int> dist(-6, 6); //limit result to -6 and 6

	m_Ball.MoveRect(ball_velocity);
	ball = m_Ball.GetRect();

	//Player collision
	if (Shape2D::RectangleCollision(ball, PlayerPaddle::GetPlayerPaddle())) {
		ball_velocity.x *= -1;
		ball_velocity.y = dist(gen);
	}

	//AI collision
	if (Shape2D::RectangleCollision(ball, AIPaddle::GetAIPaddleRect())) {
		ball_velocity.x *= -1;
		ball_velocity.y = dist(gen);
	}

	//Boundary check
	if (ball.x + ball.w >= 800) { //check right side
		ball_velocity.x *= -1;

		this->player_score = PlayerPaddle::GetPlayerScore();
		this->player_score += 1;

		PlayerPaddle::SetPlayerScore(player_score);
		player_scoreText.ChangeToText(player_score, Colors::WHITE);

		ResetPosition();
	}

	if (ball.x <= 0) { //check left side
		ball_velocity.x *= -1;

		this->ai_score = AIPaddle::GetAIScore();
		this->ai_score += 1;

		AIPaddle::SetAIScore(ai_score);
		ai_scoreText.ChangeToText(ai_score, Colors::WHITE);

		ResetPosition();
	}

	if (ball.y <= 0) { //check top side
		ball_velocity.y *= -1;
	}

	if (ball.y + ball.h >= 600) { // check bottom side
		ball_velocity.y *= -1;
	}

	if (player_score >= 5) {
		victory = true;
		player_victory = true;
	}

	if (ai_score >= 5) {
		victory = true;
		ai_victory = true;
	}

}

void Ball::ResetPosition() {
	m_Ball.PlaceRect(starting_position, 20, 20);
}

void Ball::Reset() {
	m_Ball.PlaceRect(starting_position, 20, 20);

	PlayerPaddle::SetPlayerScore(0);
	player_score = 0;

	AIPaddle::SetAIScore(0);
	ai_score = 0;

	player_scoreText.ChangeToText(0, Colors::WHITE);
	ai_scoreText.ChangeToText(0, Colors::WHITE);

	victory = false;
	ai_victory = false;
	player_victory = false;
}

void Ball::Clean() {
	player_scoreText.FreeFont();
	ai_scoreText.FreeFont();
	PlayerVictoryText.FreeFont();
	AIVictoryText.FreeFont();
}

SDL_Rect& Ball::GetBall() {
	return ball;
}

bool Ball::GetVictory() {
	return victory;
}