#include "StateMachine.h"
std::vector<GameState*> StateMachine::GameState_Vector;

void StateMachine::addState(GameState* state) {
	GameState_Vector.push_back(state);
	GameState_Vector.back()->onEnter();
}

void StateMachine::killState() {
	if (!GameState_Vector.empty()) {
		if (GameState_Vector.back()->onExit())
		{ 
		    GameState_Vector.pop_back();
		}
	}
}

void StateMachine::Render()
{
	if (!GameState_Vector.empty())
	{ 
		GameState_Vector.back()->Render();
	}
}

void StateMachine::Update()
{
	if (!GameState_Vector.empty()) 
	{ 
		GameState_Vector.back()->Update();
	}
}

void StateMachine::switchState(GameState* state) {
	if (!GameState_Vector.empty()) {

		GameState_Vector.back()->onExit();
		GameState_Vector.pop_back();
		
	}
	GameState_Vector.push_back(state);
	GameState_Vector.back()->onEnter();

}

void StateMachine::KillAllStates() {
	if (!GameState_Vector.empty()) {
		
		GameState_Vector.back()->onExit();
		GameState_Vector.pop_back();

		GameState_Vector.clear(); //Kills every stored state
		GameState_Vector.shrink_to_fit(); // Sets capacity back to 0
		
	}

}