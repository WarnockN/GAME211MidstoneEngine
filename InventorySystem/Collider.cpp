#include "Collider.h"
#include "VMath.h"
#include <iostream>
bool Collider::SphereSphereCollision(const PhysicsObject& sphere1, const PhysicsObject& sphere2) {
	//basic stuff -- check if distance between the two spheres is less than radius + radius of two spheres
	Vec3 center1 = sphere1.pos;
	Vec3 center2 = sphere2.pos;

	//this distance func just subtracts center1 - center2 and gets magnitude of that answer which is a float value.
	float distance = VMath::distance(center1, center2); 
	
	//check distance < radius + radius and return collision or not 
	if (distance < (sphere1.radius + sphere2.radius)) {
		return true;
	}
	return false;
}
void Collider::SphereSphereCollisionResponse(PhysicsObject& sphere1, PhysicsObject& sphere2) {
	float e = 1.0f; //Coefficient of Restitution

	//get position vector between the two spheres and normalize
	Vec3 lineOfAction = sphere1.pos - sphere2.pos;
	Vec3 normalizedLineOfAction = VMath::normalize(lineOfAction);

	//dot that normal vector with the velocity of each sphere. -> new velocity vector
	float v1p = VMath::dot(normalizedLineOfAction, sphere1.vel);
	float v2p = VMath::dot(normalizedLineOfAction, sphere2.vel);
	
	//derivative equation to get new elocity vectors
	float newv1p = ((sphere1.mass - e * sphere2.mass) * v1p) + ((1.0f + e) * sphere2.mass * v2p) / (sphere1.mass + sphere2.mass);
	float newv2p = ((sphere2.mass - e * sphere1.mass) * v2p) + ((1.0f + e) * sphere1.mass * v1p) / (sphere1.mass + sphere2.mass);

	//change velocity accordingly for each sphere based on derivative equation
	if (v1p - v2p > 0.0f) return;
	sphere1.vel += (newv1p - v1p) * normalizedLineOfAction;
	sphere2.vel += (newv2p - v2p) * normalizedLineOfAction;
}
bool Collider::SpherePlaneCollision(const PhysicsObject& sphere, const Plane& plane) {
	if (VMath::distance(sphere.pos, plane) < (sphere.radius)) {
		return true;
	}
	return false;
}
void Collider::SpherePlaneCollisionResponse(PhysicsObject& sphere, const Plane& plane) {
	if (VMath::dot(sphere.vel, plane) >= 0.0f) {
		return;
	}
	//get magnitude to reflect with same speed as incoming
	float magnitude = VMath::mag(sphere.vel);

	//find normalized velocity vector to use reflection function
	Vec3 normalVelocity = VMath::normalize(sphere.vel);
	Vec3 reflection = VMath::reflect(normalVelocity, plane);

	//make new velocity equal to reflection * magnitude to reflect and keep same speed with magnituide
	sphere.vel = reflection * magnitude;
}