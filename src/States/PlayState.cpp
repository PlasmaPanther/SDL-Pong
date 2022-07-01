#include "PlayState.h"
#include "../Input.h"
#include "../Application.h"

PlayState PlayState::s_Instance;

bool PlayState::onEnter() {
	printf("Entering Play state\n");

	m_Player.Place();
	m_AI.Place();
	m_Ball.Place();

	m_AiScore = 0;
	m_PlayerScore = 0;
	m_Victory = false;

	m_PressEnterKey.Load("Moonrising.ttf", 32, "Press enter key to play again", Colors::WHITE);
	m_PressEscKey.Load("Moonrising.ttf", 32, "Press esc key to exit", Colors::WHITE);

	m_PlayerScoreText.LoadToText("Moonrising.ttf", 32, m_PlayerScore, Colors::WHITE);
	m_AiScoreText.LoadToText("Moonrising.ttf", 32, m_AiScore, Colors::WHITE);

	m_PlayerVictory.Load("Moonrising.ttf", 32, "Player has won!", Colors::WHITE);
	m_AiVictory.Load("Moonrising.ttf", 32, "Ai has won!", Colors::WHITE);

	return true;
}

void PlayState::Render() {

	m_Player.Render();
	m_AI.Render();
	m_Ball.Render();

	m_Line.DrawLine(Vector2(400, 0), Vector2(400, 600), Colors::WHITE);

	m_PlayerScoreText.DrawText(250, 30);
	m_AiScoreText.DrawText(550, 30);

	if (m_PlayerScore >= 5) {
		m_PlayerVictory.DrawText(100, 330);
	}

	if (m_AiScore >= 5) {
		m_AiVictory.DrawText(450, 330);
	}
}

void PlayState::Update() {

	if (m_Ball.GetBallCollider().x <= 0) {
		m_AiScore++;
		m_AiScoreText.ChangeToText(m_AiScore, Colors::WHITE);
		m_Ball.ResetPosition();
	}

	if (m_Ball.GetBallCollider().x + m_Ball.GetBallCollider().w >= 800) {
		m_PlayerScore++;
		m_PlayerScoreText.ChangeToText(m_PlayerScore, Colors::WHITE);
		m_Ball.ResetPosition();
	}

	if (!m_Victory) { //if no one has claimed victory everything is moving and getting updated
		                     //if victory is claimed however eveything freezes
		m_Player.Update();
		m_AI.Update();
		m_Ball.Update();
	}
	else {
		
		m_PressEnterKey.DrawText(140, 200);
		m_PressEscKey.DrawText(235, 400);

		if (Input::Keydown(SDL_SCANCODE_RETURN)) { //and doesn't move until the enter key is pressed

			m_Ball.Reset(); //Resets ball position

			m_PlayerScore = 0;
			m_PlayerScoreText.ChangeToText(m_PlayerScore, Colors::WHITE);

			m_AiScore = 0;
			m_AiScoreText.ChangeToText(m_AiScore, Colors::WHITE);

			m_Victory = false;
		}

		if (Input::Keydown(SDL_SCANCODE_ESCAPE)) { //if esc key is pressed then program ends
			Application::ShutDown();
		}
	}

	if (m_PlayerScore >= 5) {
		m_Victory = true;
	}

	if (m_AiScore >= 5) {
		m_Victory = true;
	}

}

bool PlayState::onExit() {
	printf("Exiting Play state\n");

	m_PlayerScoreText.FreeFont();
	m_PlayerVictory.FreeFont();

	m_AiScoreText.FreeFont();
	m_AiVictory.FreeFont();
	
	m_PressEnterKey.FreeFont();
	m_PressEscKey.FreeFont();

	return true;
}

PlayState* PlayState::GetInstance() {
	return &s_Instance;
}