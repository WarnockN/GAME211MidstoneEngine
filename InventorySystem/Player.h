#ifndef PLAYER_H
#define PLAYER_H
#include "PhysicsObject.h"
#include <SDL.h>
#include <iostream>
#include "Inventory.h"
class Player : public PhysicsObject {
private:
	Inventory *inventory;
	Vec3 mouseIsAt;
public:
	bool openInventory = false;
	Player();
	~Player();
	Player(Vec3 pos_, Vec3 accel_, Vec3 vel_, float radius_);
	void PollEvents();
	bool ShowInventory();
	void InventoryInit(Inventory* inv);
};
#endif