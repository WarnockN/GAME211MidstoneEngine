#ifndef PLAYER_H
#define PLAYER_H
#include "PhysicsObject.h"
#include <SDL.h>
#include <iostream>
class Player : public PhysicsObject {
public:
	Player();
	~Player();
	Player(Vec3 pos_, Vec3 accel_, Vec3 vel_);
	void PollEvents();
	inline void SetPos(Vec3 pos_) { pos = pos_; }
	inline Vec3 GetPos() { return pos; }
	inline void SetVel(Vec3 vel_) { vel = vel_; }
	inline Vec3 GetVel() { return vel; }
	inline void SetAccel(Vec3 accel_) { accel = accel_; }
	inline Vec3 GetAccel() { return accel; }
};
#endif