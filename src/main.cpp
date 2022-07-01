#include "Application.h"

int main(int argc, char* argv[]) {

	Application* game = Application::Instance();
	
	game->MainLoop();
	game->DestroyInstance();
	game = nullptr;

	return 0;
}