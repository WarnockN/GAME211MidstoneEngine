#include "ItemWeapon.h"
ItemWeapon::ItemWeapon() {

}
ItemWeapon::ItemWeapon(Vec3 pos_, float radius_):Item(pos_, radius_) {
	pos = pos_;
	radius = radius_;
}
ItemWeapon::~ItemWeapon() {

}