#include "Graphics.h"
#include <string>

Graphics* Graphics::s_Instance = nullptr;
SDL_Renderer* Graphics::m_Renderer = nullptr;
SDL_Window* Graphics::m_Window = nullptr;

Graphics* Graphics::Instance() {
	if (s_Instance == nullptr) {
		s_Instance = new Graphics();
	}

	return s_Instance;
}

void Graphics::DestroyInstance() {
	delete s_Instance;
	s_Instance = nullptr;
}

Graphics::Graphics() {
	m_Initialized = Init();
}

//======================================================
Graphics::~Graphics() {
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	printf("Window destroyed\n");

	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
	printf("Renderer destroyed\n");

	IMG_Quit();
	SDL_Quit();
}
//======================================================


//======================================================
bool Graphics::Init() {
	if ((SDL_Init(SDL_INIT_EVERYTHING)) != 0) {
		printf("SDL Init failed: %s\n", SDL_GetError());
		return false;
	}

	uint8_t flags = IMG_INIT_JPG | IMG_INIT_PNG;

	if (!(IMG_Init(flags)) && flags) {
		printf("Graphic init failed: %s\n", IMG_GetError());
		return false;
	}
	
	m_Window = SDL_CreateWindow("Pong Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);

	if (m_Window == nullptr) {
		printf("Could not create window: %s\n", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if (m_Renderer == nullptr) {
		printf("Renderer could not be created: %s\n", SDL_GetError());
		return false;
	}

	SDL_SetWindowMinimumSize(m_Window, m_Min_WindowWidth, m_Min_WindowHeight);
	SDL_SetRenderDrawBlendMode(m_Renderer, SDL_BLENDMODE_BLEND);

	return true;
}
//======================================================


//======================================================
bool Graphics::Initialized() {
	return m_Initialized;
}

//======================================================
void Graphics::Update() {
	SDL_RenderClear(m_Renderer);
}

//======================================================
void Graphics::Render() {
	SDL_RenderPresent(m_Renderer);
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
}

//======================================================
SDL_Renderer* Graphics::GetRenderer() {
	return m_Renderer;
}

SDL_Window* Graphics::GetWindow() {
	return m_Window;
}

int Graphics::GetWindowWidth() const {
	return WINDOW_W;
}

int Graphics::GetWindowHeight() const {
	return WINDOW_H;
}