#include "Application.h"

/*void detect_memory_leaks(bool on_off)
{
	int flags = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	if (!on_off)
		flags &= ~_CRTDBG_LEAK_CHECK_DF;
	else {
		flags |= _CRTDBG_LEAK_CHECK_DF;
		_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
		_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	}
	_CrtSetDbgFlag(flags);
}*/

int main(int argc, char* argv[]) {

	Application* game = Application::Instance();
	
	game->MainLoop();
	game->DestroyInstance();
	game = nullptr;

	//detect_memory_leaks(true);

	return 0;
}