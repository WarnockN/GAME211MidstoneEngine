#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include "Matrix.h"
#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
class Inventory {
private:
	int numOfItems;
	SDL_Surface* inventoryImage;
	SDL_Surface* itemImage;
	SDL_Surface* foodImage;
	SDL_Surface* weaponImage;
	void initialize(const int from);
public:
	const int cap = 3;
	Item* items[3];

	Inventory();
	~Inventory();
	void addItem(Item* item); //constant item refferrence
	void placeItem(Item* item);
	void removeItem(int index, Item* item); //removes an item from a specific index
	void render(Matrix4& projection, SDL_Window* window);
};
#endif