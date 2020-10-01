#include "Collider.h"
#include "VMath.h"
#include <iostream>

bool Collider::SphereSphereCollision(const Body& ball1, const Body& ball2) {
	//basic stuff -- check if distance between the two spheres is less than radius + radius of two spheres
	Vec3 center1 = ball1.pos;
	Vec3 center2 = ball2.pos;

	//this distance func just subtracts center1 - center2 and gets magnitude of that answer which is a float value.
	float distance = VMath::distance(center1, center2); 
	
	//check distance < radius + radius and return collision or not 
	if (distance < (ball1.radius + ball2.radius)) {
		return true;
	}
	return false;
}

void Collider::SphereSphereCollisionResponse(Body& ball1, Body& ball2) {
	float e = 1.0f; //Coefficient of Restitution

	//get position vector between the two spheres and normalize
	Vec3 lineOfAction = ball1.pos - ball2.pos;
	Vec3 normalizedLineOfAction = VMath::normalize(lineOfAction);

	//dot that normal vector with the velocity of each sphere. -> new velocity vector
	float v1p = VMath::dot(normalizedLineOfAction, ball1.vel);
	float v2p = VMath::dot(normalizedLineOfAction, ball2.vel);
	
	//derivative equation to get new elocity vectors
	float newv1p = ((ball1.mass - e * ball2.mass) * v1p) + ((1.0f + e) * ball2.mass * v2p) / (ball1.mass + ball2.mass);
	float newv2p = ((ball2.mass - e * ball1.mass) * v2p) + ((1.0f + e) * ball1.mass * v1p) / (ball1.mass + ball2.mass);

	//change velocity accordingly for each sphere based on derivative equation
	if (v1p - v2p > 0.0f) return;
	ball1.vel += (newv1p - v1p) * normalizedLineOfAction;
	ball2.vel += (newv2p - v2p) * normalizedLineOfAction;
}

bool Collider::SpherePlaneCollision(const Body& ball, const Plane& plane) {
	if (VMath::distance(ball.pos, plane) < (ball.radius)) {
		return true;
	}
	return false;
}

void Collider::SpherePlaneCollisionResponse(Body& ball, const Plane& plane) {
	if (VMath::dot(ball.vel, plane) >= 0.0f) {
		return;
	}
	//get magnitude to reflect with same speed as incoming
	float magnitude = VMath::mag(ball.vel);

	//find normalized velocity vector to use reflection function
	Vec3 normalVelocity = VMath::normalize(ball.vel);
	Vec3 reflection = VMath::reflect(normalVelocity, plane);

	//make new velocity equal to reflection * magnitude to reflect and keep same speed with magnituide
	ball.vel = reflection * magnitude;
}
