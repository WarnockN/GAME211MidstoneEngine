#include "SceneManager.h"
#include "Window.h"
#include "Timer.h"
#include "Scene0.h"
#include <iostream>
SceneManager::SceneManager(): ptr(NULL) {
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;
}
/// In this OnCreate() method, fuction, subroutine, whatever the word, 
bool SceneManager::OnCreate() {
	const int SCREEN_WIDTH = 780;
	const int SCREEN_HEIGHT = 400;
	ptr = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (ptr == nullptr) {
		OnDestroy();
		return false;
	}
	if (ptr->OnCreate() == false) {
		OnDestroy();
		return false;
	}
	timer = new Timer();
	if (timer == nullptr) {
		OnDestroy();
		return false;
	}
	currentScene = new Scene0(ptr->GetSDL_Window());
	if (currentScene == nullptr) {
		OnDestroy();
		return false;
	}
	if (currentScene->OnCreate() == false) {
		OnDestroy();
		return false;
	}
	return true;
}
//Deconstructor
SceneManager::~SceneManager() {}
void SceneManager::OnDestroy()
{
	if (ptr) delete ptr;
	if (timer) delete timer;
	if (currentScene) delete currentScene;
}
/// Here's the whole game
void SceneManager::Run() {
	timer->Start();
	while (isRunning) {
		timer->UpdateFrameTicks();
		currentScene->Update(timer->GetDeltaTime());
		currentScene->Render();
/// Keeep the event loop running at a proper rate
	SDL_Delay(timer->GetSleepTime(60)); ///60 frames per sec
	}
}
void SceneManager::HandleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		isRunning = false;
		return;
	}
	/*if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				isRunning = false;
				break;
			}
		}
	}*/
}