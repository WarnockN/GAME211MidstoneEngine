#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H
#include "Vector.h"
#include <SDL.h>
using namespace MATH;
class PhysicsObject {
	friend class Collider;
	friend class Scene0;
	friend class Inventory;
protected:
	Vec3 pos, vel, accel;
public:
	float radius, time, mass;
	PhysicsObject();
	~PhysicsObject();
	PhysicsObject(Vec3 pos_, float radius);
	PhysicsObject(Vec3 pos_, Vec3 vel_, Vec3 accel_, float radius_);
	PhysicsObject(Vec3 pos_, Vec3 vel_, Vec3 accel_, float radius_, float time_, float mass_);
	void Update(const float deltaTime);
	inline void setPos(const Vec3& pos_) { pos = pos_; }
	inline Vec3 getPos() { return pos; }
};
#endif