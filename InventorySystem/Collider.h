#ifndef COLLIDER_H
#define COLLIDER_H
#include "PhysicsObject.h"
class Collider {
public:
	static bool SphereSphereCollision(const PhysicsObject &ball1, const PhysicsObject &ball2);
	static void SphereSphereCollisionResponse(PhysicsObject& ball1, PhysicsObject& ball2);
	static bool SpherePlaneCollision(const PhysicsObject& ball, const Plane& plane);
	static void SpherePlaneCollisionResponse(PhysicsObject& ball, const Plane& plane);
	Vec3 radius1;
	Vec3 radius2;
};
#endif