#ifndef PLAYER_H
#define PLAYER_H
#include "PhysicsObject.h"
#include <SDL.h>
#include <iostream>

class Player : public PhysicsObject {

private:
	Vec3 pos;

public:
	Player();
	~Player();
	void PollEvents();

};
#endif