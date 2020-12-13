#include "Item.h"
void Item::Destroy(Item* item)
{
	delete item;
	item = nullptr;

}
Item::Item(){

}
Item::Item(Vec3 pos_, float radius_, int itemType_):PhysicsObject(pos_, radius_) {
	pos = pos_;
	radius = radius_;
	itemType = itemType_;
}
Item::~Item() {

}