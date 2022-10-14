#include "PlayerPaddle.h"
#include "Input.h"
#include "CollisionManager.h"
#include "TimerModule.h"

void PlayerPaddle::Place() {
	
	m_Player.Place(Vector2(30, 300), Vector2(15, 60));

	CollisionManager::AddCollider(&m_Player, "player");
}

void PlayerPaddle::Render() {
	m_Player.RenderRect(255, 255, 255, 255);
}

void PlayerPaddle::Update() {

	if (Input::Keydown(SDL_SCANCODE_UP)) {
		m_Player.Move(Vector2(0, -300) * TimerModule::GetDelta());
	}

	if (Input::Keydown(SDL_SCANCODE_DOWN)) {
		m_Player.Move(Vector2(0, 300) * TimerModule::GetDelta());
	}

	//Boundary check
	if (m_Player.GetRect().y <= 0) {
		m_Player.GetRect().y = 0;
	}

	if (m_Player.GetRect().y + m_Player.GetRect().h >= 600) {
		m_Player.GetRect().y = 600 - m_Player.GetRect().h;
	}
}

Shape2D& PlayerPaddle::GetPlayerPaddleCollider() {
	return m_Player;
}