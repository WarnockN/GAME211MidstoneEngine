#include "Scene0.h"
#include <SDL.h>
#include <SDL_Image.h>
#include "PhysicsObject.h"

Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
}

Scene0::~Scene0(){}

bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w,h);
	Matrix4 ortho = MMath::orthographic(0.0, 200.0, 0.0, 50.0, 0.0, 1.0);
	projection = ndc * ortho;
	
	player = new Player();

	return true;
}

void Scene0::OnDestroy() {


}

void Scene0::HandleEvents(const SDL_Event& event) {
	
}

void Scene0::Update(const float time) {	
	player->PollEvents();
}

void Scene0::Render() {
	
}


