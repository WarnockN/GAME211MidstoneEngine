#include "Item.h"

class Inventory
{
private:
	int capacity;
	int numOfItems;
	Item** itemArr; //item array
	void expand();
	void initialize(const int from);


public:
	Inventory();
	~Inventory();
	void addItem(const Item& item); //constant item refferrence
	void removeItem(int index); //removes an item from a specific index

};

