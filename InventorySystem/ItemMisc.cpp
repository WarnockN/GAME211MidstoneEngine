#include "ItemMisc.h"
ItemMisc::ItemMisc() {

}
ItemMisc::ItemMisc(Vec3 pos_, float radius_, int itemType_) : Item(pos_, radius_, itemType_) {
	pos = pos_;
	radius = radius_;
	itemType = itemType_;
}
ItemMisc::~ItemMisc() {

}