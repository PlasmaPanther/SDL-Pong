#include "AIPaddle.h"
#include "Ball.h"

void AIPaddle::Place() {
	
	m_AIPaddleCollider.PlaceRect(Vector2(755, 300), 15, 60);

	m_AiVelocity.x = 0;
	m_AiVelocity.y = -8;

}

void AIPaddle::Render() {
	m_AIPaddleCollider.DrawRect(255, 255, 255, 255);
}

void AIPaddle::Update() {
	SDL_FRect BallCollider = Ball::GetBallCollider();

	//Boundary check
	if (m_AIPaddleCollider.GetRect().y <= 0) {
		m_AIPaddleCollider.GetRect().y = 0;
	}

	if (m_AIPaddleCollider.GetRect().y + m_AIPaddleCollider.GetRect().h >= 600) {
		m_AIPaddleCollider.GetRect().y = 600 - m_AIPaddleCollider.GetRect().h;
	}

	//Determine when the AI starts moving based on the ball X pos; increase value for easier AI; 650 and higher is easiest
	//also ball has to be in front of the ai paddle
	if (BallCollider.x >= 450 && BallCollider.x + BallCollider.w <= m_AIPaddleCollider.GetRect().x) {

		if (BallCollider.y < m_AIPaddleCollider.GetRect().y + m_AIPaddleCollider.GetRect().h / 2) { //if ball y is lower than the center of the paddle
			m_AiVelocity.y = -8; //move accordingly
			m_AIPaddleCollider.MoveRect(m_AiVelocity);
		}

		if (BallCollider.y + BallCollider.h > m_AIPaddleCollider.GetRect().y + m_AIPaddleCollider.GetRect().h / 2) { //if ball y is higher than the center of the paddle
			m_AiVelocity.y = 8;
			m_AIPaddleCollider.MoveRect(m_AiVelocity);
		}
	}
}

Shape2D& AIPaddle::GetAIPaddleCollider() {
	return m_AIPaddleCollider;
}