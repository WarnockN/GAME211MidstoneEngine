#ifndef ITEM_H
#define ITEM_H

#include "PhysicsObject.h"

class Item {

private:

	Vec3 pos;

public:
	Item();
	Item(Vec3 pos_);
	~Item();

	inline void SetPos(Vec3 pos_) { pos = pos_; }
	inline Vec3 GetPos() { return pos; }
};
#endif