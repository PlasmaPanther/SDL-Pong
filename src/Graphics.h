#pragma once

/*#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif
*/
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Graphics
{
public:
	static Graphics* Instance();
	
	void DestroyInstance();

	void Render();
	void Update();

	static SDL_Renderer* GetRenderer();
	static SDL_Window* GetWindow();

	bool Initialized();

	int GetWindowWidth() const;
	int GetWindowHeight() const;

private:

	Graphics();
	~Graphics();

	static SDL_Window* m_Window;
	static SDL_Renderer* m_Renderer;

	static Graphics* s_Instance;

	bool Init();

	const int WINDOW_W = 800;
	const int WINDOW_H = 600;

	bool m_Initialized;

};