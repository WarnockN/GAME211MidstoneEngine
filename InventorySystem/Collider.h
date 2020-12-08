#ifndef COLLIDER_H
#define COLLIDER_H
#include "PhysicsObject.h"
#include "Player.h"
#include "Item.h"
#include <SDL.h>

class Collider {
public:
	static bool SphereSphereCollision(const PhysicsObject &ball1, const PhysicsObject &ball2);
	static void SphereSphereCollisionResponse(PhysicsObject& ball1, PhysicsObject& ball2);
	static bool SpherePlaneCollision(const PhysicsObject& ball, const Plane& plane);
	static void SpherePlaneCollisionResponse(PhysicsObject& ball, const Plane& plane);
	static bool PlayerItemCollision(const Player& box1, const SDL_Surface& box1Pic, const Item& box2, const SDL_Surface& box2Pic);

	Vec3 radius1;
	Vec3 radius2;
};
#endif