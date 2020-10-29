#include "Scene0.h"
#include <SDL.h>
#include <SDL_Image.h>
#include "PhysicsObject.h"

using namespace std;

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
	
	player = new Player(Vec3(75.0, 35.0, 0.0), 
						Vec3(0.0, 0.0, 0.0), 
						Vec3(0.0, 0.0, 0.0));
	playerImage = IMG_Load("gingy.jpg");
	if (playerImage == nullptr) cout << "image lost" << endl;

	return true;
}

void Scene0::OnDestroy() {
	delete player;
	player = nullptr;
}

void Scene0::HandleEvents(const SDL_Event& event) {
	
}

void Scene0::Update(const float time) {	
	player->PollEvents();
}

void Scene0::Render() {
	Vec3 pos = player->GetPos();
	Vec3 screenPos = projection * pos;
	SDL_Rect dstrect;
	dstrect.x = static_cast<int>(screenPos.x);
	dstrect.y = static_cast<int>(screenPos.y);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));
	SDL_BlitSurface(playerImage, nullptr, screenSurface, &dstrect);
	SDL_UpdateWindowSurface(window);
}


