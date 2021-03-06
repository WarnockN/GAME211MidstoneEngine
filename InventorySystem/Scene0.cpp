﻿#include "Scene0.h"
#include <SDL.h>
#include <SDL_Image.h>
#include "PhysicsObject.h"
#include "Collider.h"
#include "Inventory.h"
using namespace std;
Scene0::Scene0(SDL_Window* sdlWindow_):player(0), food(), foodImage(0), inventory(0), playerImage(0), timer(0), weaponImage(0), item() {
	window = sdlWindow_;
}
Scene0::~Scene0(){}
bool Scene0::OnCreate() {
	
	//creates the screen
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w,h);
	Matrix4 ortho = MMath::orthographic(0.0, 400.0, 0.0, 200.0, 0.0, 1.0);
	projection = ndc * ortho;

	//creates inventory
	

	//creates food items
	food[0] = new ItemFood(Vec3(150.0, 70.0, 0.0), 1.0f, 1);
	food[1] = new ItemFood(Vec3(250.0, 70.0, 0.0), 1.0f, 1);

	foodImage = IMG_Load("bred.png");
	if (foodImage == nullptr) cout << "food image lost" << endl;

	//creates weapon
	weapon[0] = new ItemWeapon(Vec3(200.0, 70.0, 0.0), 1.0f, 2);
	weaponImage = IMG_Load("sword.png");
	if (weaponImage == nullptr) cout << "weapon image lost" << endl;

	//creates player
	player = new Player(Vec3(10.0, 70.0, 0.0), Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0), 15.0f);
	playerImage = IMG_Load("character.png");
	if (playerImage == nullptr) cout << "player image lost" << endl;
	inventory = new Inventory();
	player->InventoryInit(inventory);
	
	backgroundImage = IMG_Load("background.jpg");
	return true;
}
void Scene0::OnDestroy() {
	delete player;
	player = nullptr;
	delete food[0];
	food[0] = nullptr;
	delete food[1];
	food[1] = nullptr;
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
	for (int j = 0; j < 2; j++) {
		if (Collider::SphereSphereCollision(*player, *food[j])) {

			std::cout << "item collected" << std::endl;
			Vec3 tempVec = Vec3(food[j]->pos.x, food[j]->pos.y, food[j]->pos.z);
			inventory->addItem(food[j], tempVec);
			food[j]->Destroy(food[j]);

		};
		if (Collider::SphereSphereCollision(*player, *weapon[j])) {

			std::cout << "item collected" << std::endl;
			Vec3 tempVec = Vec3(weapon[j]->pos.x, weapon[j]->pos.y, food[j]->pos.z);
			inventory->addItem(weapon[j], tempVec);
			weapon[j]->Destroy(weapon[j]);

		};
	};


	if (player->ShowInventory() == true) {
		renderInventory = true;
		//render the inventory
	}
	else {
		renderInventory = false;
	}
	player->PollEvents();

};

void Scene0::Render() {
	SDL_Rect images[5];
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));

		Vec3 ScreenPos = projection * Vec3(1.0f,200.0f,0.0f);
		images[4].x = (int)ScreenPos.x;
		images[4].y = (int)ScreenPos.y;
		images[4].w = backgroundImage->w;
		images[4].h = backgroundImage->h;
		SDL_BlitSurface(backgroundImage, nullptr, screenSurface, &images[4]);
		
	//for 
	//inventory->renderItems(true, a);
	if (renderInventory == false) {
		for (int i = 0; i < 1; i++) {
			Vec3 ScreenPos = projection * player->getPos();
			images[i].x = (int)ScreenPos.x;
			images[i].y = (int)ScreenPos.y;
			images[i].w = playerImage->w;
			images[i].h = playerImage->h;
			SDL_BlitSurface(playerImage, nullptr, screenSurface, &images[i]);
		}
		for (int i = 1; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				Vec3 ScreenPos = projection * food[j]->getPos();
				images[i].x = (int)ScreenPos.x;
				images[i].y = (int)ScreenPos.y;
				images[i].w = foodImage->w;
				images[i].h = foodImage->h;
				SDL_BlitSurface(foodImage, nullptr, screenSurface, &images[i]);
			}
		}
		for (int i = 0; i < 1; i++) {
			Vec3 ScreenPos = projection * weapon[i]->getPos();
			images[i].x = (int)ScreenPos.x;
			images[i].y = (int)ScreenPos.y;
			images[i].w = weaponImage->w;
			images[i].h = weaponImage->h;
			SDL_BlitSurface(weaponImage, nullptr, screenSurface, &images[i]);
		}
	}
	if (renderInventory == true) {
		inventory->render(projection, window);
	}
SDL_UpdateWindowSurface(window);
}