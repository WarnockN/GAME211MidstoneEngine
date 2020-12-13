#ifndef SCENE0_H
#define SCENE0_H
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "PhysicsObject.h"
#include "Player.h"
#include "ItemFood.h"
#include "Inventory.h"
#include <array>
using namespace MATH;
class Scene0 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projection;
	Player* player;
	ItemFood* food[2];
	Item* item[3];
	Inventory* inventory;

	SDL_Surface* playerImage;
	SDL_Surface* foodImage;
	SDL_Surface* weaponImage;

	float timer;
	bool renderInventory = false;
public:
	std::array<int, 4>nums{ 1, 2, 3, 4 };
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& event);
};
#endif