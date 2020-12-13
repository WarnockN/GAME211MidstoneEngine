#ifndef ITEMWEAPON_H
#define ITEMWEAPON_H
#include "Item.h"
class ItemWeapon : public Item {
public:
	ItemWeapon();
	ItemWeapon(Vec3 pos_, float radius_, int itemType_);
	~ItemWeapon();
};
#endif