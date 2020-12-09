#ifndef COLLIDER_H
#define COLLIDER_H
#include "PhysicsObject.h"
#include <SDL.h>
#include "Item.h"
class Collider {
public:
	static bool SphereSphereCollision(const PhysicsObject & sphere1, const PhysicsObject & sphere2);
	static void SphereSphereCollisionResponse(PhysicsObject& sphere1, PhysicsObject& sphere2);
	static bool SpherePlaneCollision(const PhysicsObject& sphere, const Plane& plane);
	static void SpherePlaneCollisionResponse(PhysicsObject& sphere, const Plane& plane);
};
#endif