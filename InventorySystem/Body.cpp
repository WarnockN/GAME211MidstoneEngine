#include "Body.h"

Body::Body()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;

	vel.x = 0.0f;
	vel.y = 0.0f;
	vel.z = 0.0f;

	accel.x = 0.0f;
	accel.y = 0.0f;
	accel.z = 0.0f;

	mass = 0.0f;
	time = 0.0f;
	nforce = 0.0f;
	radius = 1.0f;
	rotationalInertia = 0.0f;
	angle = 0.0f;
	angularVel = 0.0f;
	angularAcc = 0.0f;

}

Body::~Body()
{

}

Body::Body(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_, float time_, float radius_)
{
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

Body::Body(float mass_, float rotationalInertia_) {
	mass = mass_;
	rotationalInertia = rotationalInertia_;

	angle = 0.0f;
	angularVel = 0.0f;
	angularAcc = 0.0f;
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;

	vel.x = 0.0f;
	vel.y = 0.0f;
	vel.z = 0.0f;

	accel.x = 0.0f;
	accel.y = 0.0f;
	accel.z = 0.0f;
}

void Body::ApplyForce(Vec3 force)
{
	//Update orientation angle

	//Update angular vel, pos, and accel

	//Update linear velocity



}

void Body::ApplyTorque(float torque) {
	//Use a = T/I


}

Vec3 Body::GetPos()
{
	return pos;
}

Vec3 Body::GetVel()
{
	return vel;
}

void Body::SetVel(float number_)
{
	vel.x = number_;
}

void Body::Update(const float deltaTime) {
	// \t = Tab 

	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime;
	vel.x += accel.x * deltaTime;

	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime;
	vel.y += accel.y * deltaTime;

	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime;
	vel.z += accel.z * deltaTime;

	time += deltaTime;
}