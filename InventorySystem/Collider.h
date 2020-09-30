#include "Body.h"

class Collider {
public:
	static bool SphereSphereCollision(const Body &ball1, const Body &ball2);
	static void SphereSphereCollisionResponse(Body& ball1, Body& ball2);
	static bool SpherePlaneCollision(const Body& ball, const Plane& plane);
	static void SpherePlaneCollisionResponse(Body& ball, const Plane& plane);

	Vec3 radius1;
	Vec3 radius2;
};

