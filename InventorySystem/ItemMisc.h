#ifndef ITEMMISC_H
#define ITEMMISC_H
#include "Item.h"
class ItemMisc : public Item {
public:
	ItemMisc();
	ItemMisc(Vec3 pos_);
	~ItemMisc();
	inline void SetPos(Vec3 pos_) { pos = pos_; }
	inline Vec3 GetPos() { return pos; }
};
#endif