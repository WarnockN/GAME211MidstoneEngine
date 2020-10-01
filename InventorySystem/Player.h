#ifndef PLAYER_H
#define PLAYER_H
#include "PhysicsObject.h"

class Player : public PhysicsObject {
public:
	Player();
	Player(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_, float time_, float radius_);
	~Player();
};
#endif