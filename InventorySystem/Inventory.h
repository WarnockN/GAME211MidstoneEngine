#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"

class Inventory {
private:
	
	int numOfItems;

	void expand();
	void initialize(const int from);
public:
	const int cap = 3;
	Item* items[3];

	Inventory();
	~Inventory();
	void addItem(Item* item); //constant item refferrence
	void removeItem(int index); //removes an item from a specific index
};
#endif