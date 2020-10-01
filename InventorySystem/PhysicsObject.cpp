#include "PhysicsObject.h"

PhysicsObject::PhysicsObject():pos(0.0f), vel(0.0f), accel(0.0f), mass(0.0f), angle(0.0f), angularVel(0.0f), angularAcc(0.0f), rotationalInertia(0.0f), radius(0.0f), time(0.0f) {}

PhysicsObject::~PhysicsObject() {}

PhysicsObject::PhysicsObject(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_, float time_, float radius_):angle(0.0f), angularVel(0.0f), angularAcc(0.0f), rotationalInertia(0.0f) {
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;
	vel.x = vel_.x;
	vel.y = vel_.y;
	vel.z = vel_.z;
	accel.x = accel_.x;
	accel.y = accel_.y;
	accel.z = accel_.z;
	mass = mass_;
	time = time_;
	radius = radius_;
}

PhysicsObject::PhysicsObject(float mass_, float rotationalInertia_):pos(0.0f), vel(0.0f), accel(0.0f), angle(0.0f), angularVel(0.0f), angularAcc(0.0f), radius(0.0f), time(0.0f) {
	mass = mass_;
	rotationalInertia = rotationalInertia_;
}

void PhysicsObject::Update(const float deltaTime) {
	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime;
	vel.x += accel.x * deltaTime;
	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime;
	vel.y += accel.y * deltaTime;
	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime;
	vel.z += accel.z * deltaTime;
	time += deltaTime;
}