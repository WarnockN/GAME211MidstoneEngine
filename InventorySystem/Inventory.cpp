#include "Inventory.h"
using namespace std;
Inventory::Inventory() {
	this->capacity = 3; // # of items a player can hold
	this->numOfItems = 0; //player starts with 0 items
	this->itemArr = new Item * [capacity];
}
Inventory::~Inventory() {
	for (size_t i = 0; i < this->numOfItems; i++) { this->itemArr[i]; }
	delete[] itemArr;
}
void Inventory::addItem(const Item& item) {
	if (this->numOfItems >= this->capacity) { expand(); }
	this->itemArr[this->numOfItems] = new Item(item);
}
void Inventory::removeItem(int index) {

}
void Inventory::expand() {
	this->capacity *= 2;
	Item** tempArr = new Item * [this->capacity];
	for (size_t i = 0; i < this->numOfItems; i++){ tempArr[i] = new Item(*this->itemArr[i]); }
	for (size_t i = 0; i < this->numOfItems; i++){ delete this->itemArr[i]; }
	delete[] this->itemArr;
	//permanent pointer is pointing to the new array
	this->itemArr = tempArr;
	//initializes 
	this->initialize(this->numOfItems);
}
void Inventory::initialize(const int from) {
	for (size_t i = from; i < capacity; i++) { itemArr[i] = nullptr; }
}