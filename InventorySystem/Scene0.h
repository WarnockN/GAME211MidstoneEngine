#ifndef SCENE0_H
#define SCENE0_H
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "PhysicsObject.h"
#include "Player.h"

using namespace MATH;
class Scene0 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projection;
	Player* player;
	float timer;
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

