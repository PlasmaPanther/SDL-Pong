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
#endif*/

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//I don't know where to put this so for now
//it will stay here
namespace Colors {
	constexpr SDL_Color RED = { 255, 0, 0, 255 };
	constexpr SDL_Color GREEN = { 0, 255, 0, 255 };
	constexpr SDL_Color BLUE = { 0, 0, 255, 255 };
	constexpr SDL_Color YELLOW = { 255, 255, 51, 255 };
	constexpr SDL_Color BROWN = { 150, 75, 0, 255 };
	constexpr SDL_Color WHITE = { 255, 255, 255, 255 };
	constexpr SDL_Color BLACK = { 0, 0, 0, 255 };
	constexpr SDL_Color BEIGE = { 245, 245, 220, 255 };
	constexpr SDL_Color CYAN = { 0, 255, 255, 255 };
	constexpr SDL_Color ORANGE = { 255, 165, 0, 255 };
	constexpr SDL_Color PINK = { 255, 100, 180, 255 };
	constexpr SDL_Color PURPLE = { 240, 0, 255, 255 };
	constexpr SDL_Color LIME = { 180, 255, 100, 255 };
}

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

	int WINDOW_W = 800;
	int WINDOW_H = 600;
	
	const int m_Min_WindowWidth = 640;
	const int m_Min_WindowHeight = 360;

	bool m_Initialized;

};