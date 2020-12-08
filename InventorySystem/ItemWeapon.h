#ifndef ITEMWEAPON_H
#define ITEMWEAPON_H
#include "Item.h"
class ItemWeapon : public Item {
public:
	ItemWeapon();
	ItemWeapon(Vec3 pos_);
	~ItemWeapon();
	inline void SetPos(Vec3 pos_) { pos = pos_; }
	inline Vec3 GetPos() { return pos; }
};
#endif