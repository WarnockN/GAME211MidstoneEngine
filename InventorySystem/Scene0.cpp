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


	food = new ItemFood(Vec3(75.0, 35.0, 0.0));
	foodImage = IMG_Load("fortnite.png");
	if (foodImage == nullptr) cout << "image lost" << endl;


	player = new Player(Vec3(75.0, 35.0, 0.0), 
						Vec3(0.0, 0.0, 0.0), 
						Vec3(0.0, 0.0, 0.0));
	playerImage = IMG_Load("fortnite.png");
	if (playerImage == nullptr) cout << "image lost" << endl;

	return true;
}

void Scene0::OnDestroy() {
	delete player;
	player = nullptr;

	delete food;
	food = nullptr;

	delete inventory;
	inventory = nullptr;

	delete playerImage;
	playerImage = nullptr;

	delete foodImage;
	foodImage = nullptr;
}

void Scene0::HandleEvents(const SDL_Event& event) {
	
}

void Scene0::Update(const float time) {	
	player->PollEvents();
}

void Scene0::Render() {

	SDL_Rect images[3];
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));
	for (int i = 0; i < 1; i++) {


		Vec3 ScreenPos = projection * player->GetPos();

		images[i].x = (int)ScreenPos.x;
		images[i].y = (int)ScreenPos.y;

		images[i].w = playerImage->w;
		images[i].h = playerImage->h;

		SDL_BlitSurface(playerImage, nullptr, screenSurface, &images[i]);
	}
	for (int j = 1; j < 2; j++) {


		Vec3 ScreenPos = projection * player->GetPos();

		images[j].x = (int)ScreenPos.x;
		images[j].y = (int)ScreenPos.y;

		images[j].w = foodImage->w;
		images[j].h = foodImage->h;

		SDL_BlitSurface(foodImage, nullptr, screenSurface, &images[j]);
	}
	SDL_UpdateWindowSurface(window);

}


