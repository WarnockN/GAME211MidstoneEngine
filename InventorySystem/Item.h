#ifndef ITEM_H
#define ITEM_H
#include "PhysicsObject.h"
class Item : public PhysicsObject {
public:
	Item();
	Item(Vec3 pos_, float radius_);
	~Item();
};
#endif