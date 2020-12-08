#ifndef ITEMMISC_H
#define ITEMMISC_H
#include "Item.h"
class ItemMisc : public Item {
public:
	ItemMisc();
	ItemMisc(Vec3 pos_, float radius_);
	~ItemMisc();
};
#endif