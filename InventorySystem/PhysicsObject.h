#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H
#include "Vector.h"

using namespace MATH;

class PhysicsObject {
	friend class Collider;
public:
	Vec3 pos, vel, accel;
	float mass, time, radius, rotationalInertia, angle, angularVel, angularAcc;

	PhysicsObject();
	~PhysicsObject();
	PhysicsObject(Vec3 pos_, Vec3 vel, Vec3 accel_, float mass_, float time_, float radius_);
	PhysicsObject(float mass_, float rotationalInertia_);
	void Update(const float deltaTime);

	inline void setPos(const Vec3& pos_) { pos = pos_; }
	inline void setVel(const Vec3& vel_) { vel = vel_; }
	inline void setAccel(const Vec3& accel_) { accel = accel_; }
	inline void setMass(const float mass_) { mass = mass_; }
	inline void setAngle(const float angle_) { angle = angle_; }
	inline void setAngularVel(const float angularVel_) { angularVel = angularVel_; }
	inline void setAngularAcc(const float angularAcc_) { angularAcc = angularAcc_; }
	inline void setRotationalInertia(const float rotationalInertia_) { rotationalInertia = rotationalInertia_; }
	inline void applyTorque(const float torque) { angularAcc = torque / rotationalInertia; }
	inline void applyForce(const Vec3 force) { accel = force / mass; }
};
#endif