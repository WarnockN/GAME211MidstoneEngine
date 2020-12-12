#ifndef SCENE0_H
#define SCENE0_H
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "PhysicsObject.h"
#include "Player.h"
#include "ItemFood.h"
#include "Inventory.h"
using namespace MATH;
class Scene0 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projection;
	Player* player;
	ItemFood* food;
	Inventory* inventory;

	SDL_Surface* inventoryImage;
	SDL_Surface* foodImage;
	SDL_Surface* playerImage;


	float timer;
	bool renderInventory = false;
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& event);
};
#endif