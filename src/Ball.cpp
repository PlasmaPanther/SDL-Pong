#include <random>

#include "Ball.h"
#include "PlayerPaddle.h"
#include "AIPaddle.h"
#include "CollisionManager.h"
#include "TimerModule.h"

void Ball::Place(){

	m_StartingPosition.x = 400;
	m_StartingPosition.y = 300;

	m_Ball.Place(m_StartingPosition, Vector2(20, 20));

	m_BallVelocity.x = 400;
	m_BallVelocity.y = 300;

	CollisionManager::AddCollider(&m_Ball, "ball");
}

void Ball::Render() {
	m_Ball.RenderRect(255, 255, 255);

}

void Ball::Update() {

	std::random_device randomizer; //randomize numbers
	std::mt19937 gen(randomizer()); //apply seed
	std::uniform_real_distribution<float> dist(-300.0f, 300.0f); //limit result to -6 and 6

	//Player collision
	if (CollisionManager::CheckGroupCollision("ball", "player")) {
		m_BallVelocity.x *= -1;
		m_BallVelocity.y = dist(gen);
	}

	//AI collision
	if (CollisionManager::CheckGroupCollision("ball", "ai")) {
		m_BallVelocity.x *= -1;
		m_BallVelocity.y = dist(gen);
	}

	//Boundary check
	if (m_Ball.GetRect().x + m_Ball.GetRect().w >= 800) { //check right side
		m_BallVelocity.x *= -1;
	}

	if (m_Ball.GetRect().x <= 0) { //check left side
		m_BallVelocity.x *= -1;
	}

	if (m_Ball.GetRect().y <= 0) { //check top side
		m_BallVelocity.y *= -1;
	}

	if (m_Ball.GetRect().y + m_Ball.GetRect().h >= 600) { // check bottom side
		m_BallVelocity.y *= -1;
	}

	m_Ball.Move(m_BallVelocity * TimerModule::GetDelta());
	
}

void Ball::ResetPosition() {
	m_Ball.Place(m_StartingPosition, Vector2(20, 20));
}

void Ball::Reset() {
	m_Ball.Place(m_StartingPosition, Vector2(20, 20));
}