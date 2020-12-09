#include "ItemMisc.h"
ItemMisc::ItemMisc() {

}
ItemMisc::ItemMisc(Vec3 pos_, float radius_):Item(pos_, radius_) {
	pos = pos_;
	radius = radius_;
}
ItemMisc::~ItemMisc() {

}