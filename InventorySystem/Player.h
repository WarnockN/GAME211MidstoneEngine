#ifndef PLAYER_H
#define PLAYER_H
#include "PhysicsObject.h"
#include <SDL.h>
#include <iostream>
class Player : public PhysicsObject {
public:
	bool openInventory = false;
	Player();
	~Player();
	Player(Vec3 pos_, Vec3 accel_, Vec3 vel_, float radius_);
	void PollEvents();
	bool ShowInventory();
};
#endif