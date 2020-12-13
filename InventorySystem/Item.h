#ifndef ITEM_H
#define ITEM_H
#include "PhysicsObject.h"
class Item : public PhysicsObject {
public:
	void Destroy(Item* item);
	Item();
	Item(Vec3 pos_, float radius_);
	~Item();
};
#endif