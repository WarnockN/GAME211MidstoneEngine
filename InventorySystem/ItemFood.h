#ifndef ITEMFOOD_H
#define ITEMFOOD_H
#include "Item.h"
class ItemFood : public Item {
public:
	ItemFood();
	ItemFood(Vec3 pos_);
	~ItemFood();
	inline void SetPos(Vec3 pos_) { pos = pos_; }
	inline Vec3 GetPos() { return pos; }
};
#endif