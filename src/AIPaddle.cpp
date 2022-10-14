#include "AIPaddle.h"
#include "Ball.h"
#include "CollisionManager.h"
#include "TimerModule.h"

void AIPaddle::Place() {
	
	m_AIPaddle.Place(Vector2(755, 300), Vector2(15, 60));

	m_AiVelocity.x = 0;
	m_AiVelocity.y = -300;

	CollisionManager::AddCollider(&m_AIPaddle, "ai");

}

void AIPaddle::Render() {
	m_AIPaddle.RenderRect(255, 255, 255);
}

void AIPaddle::Update() {
	SDL_FRect BallCollider = CollisionManager::GetPrimitiveRectCollider("ball");
	
	//Boundary check
	if (m_AIPaddle.GetRect().y <= 0) {
		m_AIPaddle.GetRect().y = 0;
	}

	if (m_AIPaddle.GetRect().y + m_AIPaddle.GetRect().h >= 600) {
		m_AIPaddle.GetRect().y = 600 - m_AIPaddle.GetRect().h;
	}

	//Determine when the AI starts moving based on the ball X pos; increase value for easier AI; 650 and higher is easiest
	//also ball has to be in front of the ai paddle
	if (BallCollider.x >= 450 && BallCollider.x + BallCollider.w <= m_AIPaddle.GetRect().x) {

		if (BallCollider.y < m_AIPaddle.GetRect().y + m_AIPaddle.GetRect().h / 2) { //if ball y is lower than the center of the paddle
			m_AiVelocity.y = -300; //move accordingly
			m_AIPaddle.Move(m_AiVelocity * TimerModule::GetDelta());
		}

		if (BallCollider.y + BallCollider.h > m_AIPaddle.GetRect().y + m_AIPaddle.GetRect().h / 2) { //if ball y is higher than the center of the paddle
			m_AiVelocity.y = 300;
			m_AIPaddle.Move(m_AiVelocity * TimerModule::GetDelta());
		}
	}
}