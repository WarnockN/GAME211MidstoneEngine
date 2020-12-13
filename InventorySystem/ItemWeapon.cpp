#include "ItemWeapon.h"
ItemWeapon::ItemWeapon() {

}
ItemWeapon::ItemWeapon(Vec3 pos_, float radius_, int itemType_) : Item(pos_, radius_, itemType_) {
	pos = pos_;
	radius = radius_;
	itemType = itemType_;
}
ItemWeapon::~ItemWeapon() {

}