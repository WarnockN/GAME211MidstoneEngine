#include "ItemFood.h"
ItemFood::ItemFood(){

}
ItemFood::ItemFood(Vec3 pos_, float radius_, int itemType_) : Item(pos_, radius_, itemType_) {
	pos = pos_;
	radius = radius_;
}
ItemFood::~ItemFood() {

}