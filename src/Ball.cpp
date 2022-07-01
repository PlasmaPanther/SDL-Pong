#include "Ball.h"
#include "PlayerPaddle.h"
#include "AIPaddle.h"
#include <random>

void Ball::Place(){

	m_StartingPosition.x = 400;
	m_StartingPosition.y = 300;

	m_BallCollider.PlaceRect(m_StartingPosition, 20, 20);
	m_BallColliderRect = m_BallCollider.GetRect();

	m_BallVelocity.x = 6;
	m_BallVelocity.y = 6;

}

void Ball::Render() {
	m_BallCollider.DrawRect(255, 255, 255, 255);

}

void Ball::Update() {

	std::random_device randomizer; //randomize numbers
	std::mt19937 gen(randomizer()); //apply seed
	std::uniform_int_distribution<int> dist(-6, 6); //limit result to -6 and 6

	m_BallCollider.MoveRect(m_BallVelocity);

	//Player collision
	if (RectangleCollision(m_BallCollider, PlayerPaddle::GetPlayerPaddleCollider())) {
		m_BallVelocity.x *= -1;
		m_BallVelocity.y = dist(gen);
	}

	//AI collisionw
	if (RectangleCollision(m_BallCollider, AIPaddle::GetAIPaddleCollider())) {
		m_BallVelocity.x *= -1;
		m_BallVelocity.y = dist(gen);
	}

	//Boundary check
	if (m_BallCollider.GetRect().x + m_BallCollider.GetRect().w >= 800) { //check right side
		m_BallVelocity.x *= -1;
	}

	if (m_BallCollider.GetRect().x <= 0) { //check left side
		m_BallVelocity.x *= -1;
	}

	if (m_BallCollider.GetRect().y <= 0) { //check top side
		m_BallVelocity.y *= -1;
	}

	if (m_BallCollider.GetRect().y + m_BallCollider.GetRect().h >= 600) { // check bottom side
		m_BallVelocity.y *= -1;
	}

	m_BallColliderRect = m_BallCollider.GetRect();
}

void Ball::ResetPosition() {
	m_BallCollider.PlaceRect(m_StartingPosition, 20, 20);
}

void Ball::Reset() {
	m_BallCollider.PlaceRect(m_StartingPosition, 20, 20);
}

SDL_FRect& Ball::GetBallCollider() {
	return m_BallCollider.GetRect();
}