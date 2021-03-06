#include "Inventory.h"
using namespace std;
Inventory::Inventory():items(), numOfItems(0) {
	this->initialize(0);
	this->inventoryImage = IMG_Load("InventoryPlaceholder.png");
	this->foodImage = IMG_Load("bred.png");
	this->weaponImage = IMG_Load("sword.png");
	this->itemImage[0] = IMG_Load("gingy.jpg");
	this->itemImage[1] = IMG_Load("gingy.jpg");
	this->itemImage[2] = IMG_Load("gingy.jpg");
}
Inventory::~Inventory() {
	for (size_t i = 0; i < this->numOfItems; i++) { this->items[i]; }
	delete[] items;
}
void Inventory::addItem(Item* item,Vec3 pos) {


	if (item->itemType == 1) {
		std::cout << "we got a food" << std::endl;
		itemImage[numOfItems] = foodImage;
	}
	else {
		std::cout << "we aint got a food" << std::endl;
		itemImage[numOfItems] = weaponImage;
	}
	numOfItems++;

	int a = 0;
	if (a <= (cap)) {
		items[a] = item;
	
		a++;
		placeItem();
		//items[a]->setPos(tempPos);
	}
}
void Inventory::placeItem()
{
	float offset = 50.0f;
	float slotX = 65.0f;
	float slotY = 145.0f;
		iconPos[0].x = 65.0f;
		iconPos[0].y = slotY;

		iconPos[1].x = slotX + offset;
		iconPos[1].y = slotY;

		iconPos[2].x = slotX + offset*2;
		iconPos[2].y = slotY;

}
void Inventory::removeItem(int i, Item* item) {
	if (i == 1) {
		itemImage[0] = itemImage[1];
		itemImage[1] = itemImage[2];
		numOfItems--;
	}
	else if (i == 2) {
		itemImage[1] = itemImage[2];
		numOfItems--;
	}
	else if (i == 3) {
		numOfItems--;
	}

	//items[i] = nullptr;

	//item->Destroy(item);

}
void Inventory::initialize(const int from) {
	for (size_t i = from; i < cap; i++) { items[i] = nullptr; }
}
void Inventory::render(Matrix4& projection, SDL_Window* window) {
	SDL_Rect images[4];
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));
	for (int i = 0; i < 1; i++) {
		//renders the inventory
		Vec3 ScreenPos = projection * Vec3(30.0, 200.0, 0.0);
		images[i].x = (int)ScreenPos.x;
		images[i].y = (int)ScreenPos.y;
		images[i].w = inventoryImage->w;
		images[i].h = inventoryImage->h;
		SDL_BlitSurface(inventoryImage, nullptr, screenSurface, &images[i]);
	}
	for (int i = 0; i < numOfItems; i++) {


		Vec3 ScreenPos = projection * Vec3(iconPos[i].x, iconPos[i].y, 0.0);
		images[i].x = (int)ScreenPos.x;
		images[i].y = (int)ScreenPos.y;
		images[i].w = itemImage[i]->w;
		images[i].h = itemImage[i]->h;
		SDL_BlitSurface(itemImage[i], nullptr, screenSurface, &images[i]);
	}
	SDL_UpdateWindowSurface(window);
}