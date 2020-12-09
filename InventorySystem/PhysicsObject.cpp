#include "PhysicsObject.h"
PhysicsObject::PhysicsObject():pos(0.0f), vel(0.0f), accel(0.0f), radius(1.0f), time(0.0f), mass(0.0f) {}
PhysicsObject::PhysicsObject(Vec3 pos_, float radius_): vel(0.0f), accel(0.0f), time(0.0f), mass(0.0f) {
	pos = pos_;
	radius = radius_;
}
PhysicsObject::PhysicsObject(Vec3 pos_, Vec3 vel_, Vec3 accel_, float radius_):time(0.0f), mass(0.0f) {
	pos = pos_;
	vel = vel_;
	accel = accel_;
	radius = radius_;
}
PhysicsObject::PhysicsObject(Vec3 pos_, Vec3 vel_, Vec3 accel_, float radius_, float time_, float mass_) {
	pos = pos_;
	vel = vel_;
	accel = accel_;
	time = time_;
	radius = radius_;
	mass = mass_;
}
PhysicsObject::~PhysicsObject() {}
void PhysicsObject::Update(const float deltaTime) {
	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime;
	vel.x += accel.x * deltaTime;
	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime;
	vel.y += accel.y * deltaTime;
	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime;
	vel.z += accel.z * deltaTime;
	time += deltaTime;
}