#ifndef ITEMFOOD_H
#define ITEMFOOD_H
#include "Item.h"
class ItemFood : public Item {
public:
	ItemFood();
	ItemFood(Vec3 pos_, float radius_);
	~ItemFood();
};
#endif