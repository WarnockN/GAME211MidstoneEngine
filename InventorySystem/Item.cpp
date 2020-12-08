#include "Item.h"
Item::Item(){

}
Item::Item(Vec3 pos_, float radius_):PhysicsObject(pos_, radius_) {
	pos = pos_;
	radius = radius_;
}
Item::~Item() {

}