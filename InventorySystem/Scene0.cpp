#include "Scene0.h"
#include <SDL.h>
#include <SDL_Image.h>
#include "Body.h"

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
	
	return true;
}

void Scene0::OnDestroy() {
}

void Scene0::HandleEvents(const SDL_Event& event) {

}

void Scene0::Update(const float time) {	
	
}

void Scene0::Render() {
	/*Vec3 pos = jetski->GetPos();
	Vec3 screenPos = projection * pos;
	SDL_Rect dstrect;
	dstrect.x = static_cast<int>(screenPos.x);
	dstrect.y = static_cast<int>(screenPos.y);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 255, 142, 26));
	SDL_BlitSurface(jetskiImage, nullptr, screenSurface, &dstrect);
	SDL_UpdateWindowSurface(window);*/
}


