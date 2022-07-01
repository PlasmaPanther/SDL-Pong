#include "PlayerPaddle.h"
#include "Input.h"

void PlayerPaddle::Place() {
	
	m_PlayerCollider.PlaceRect(Vector2(30, 300), 15, 60);
}

void PlayerPaddle::Render() {
	m_PlayerCollider.DrawRect(255, 255, 255, 255);
}

void PlayerPaddle::Update() {

	if (Input::Keydown(SDL_SCANCODE_UP)) {
		m_PlayerCollider.MoveRect(Vector2(0, -8));
	}

	if (Input::Keydown(SDL_SCANCODE_DOWN)) {
		m_PlayerCollider.MoveRect(Vector2(0, 8));
	}

	//Boundary check
	if (m_PlayerCollider.GetRect().y <= 0) {
		m_PlayerCollider.GetRect().y = 0;
	}

	if (m_PlayerCollider.GetRect().y + m_PlayerCollider.GetRect().h >= 600) {
		m_PlayerCollider.GetRect().y = 600 - m_PlayerCollider.GetRect().h;
	}
}

Shape2D& PlayerPaddle::GetPlayerPaddleCollider() {
	return m_PlayerCollider;
}