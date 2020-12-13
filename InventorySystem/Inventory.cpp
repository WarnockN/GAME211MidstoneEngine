#include "Inventory.h"
using namespace std;
Inventory::Inventory():items(), numOfItems(0) {
	this->initialize(0);
	this->inventoryImage = IMG_Load("InventoryPlaceholder.png");
	this->foodImage = IMG_Load("gingy.png");
	this->itemImage = IMG_Load("gingy.jpg");
}
Inventory::~Inventory() {
	for (size_t i = 0; i < this->numOfItems; i++) { this->items[i]; }
	delete[] items;
}
void Inventory::addItem(Item* item) {
	
	
	std::cout << item->getPos() << std::endl;
	int a = 0;
	if (a <= (cap)) {
		items[a] = item;
	
		a++;
		placeItem(item);
		//items[a]->setPos(tempPos);
	}
}
void Inventory::placeItem(Item* item)
{
	//item->setPos(Vec3(0.0f, 133.0f, 0.0f));
	//float xPos = 155.0f;
	//float offset = 125.0f;
	//item->setPos(Vec3(xPos, 133.0f, 0.0f));
	//std::cout << xPos << std::endl;
	//xPos += offset;


}
void Inventory::removeItem(int i, Item* item) {
	items[i] = nullptr;



	item->Destroy(item);

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
	for (int i = 0; i < 3; i++) {
		/*if (items[i]->itemType == 1) {
			itemImage = foodImage;
		}*/
		//Vec3 tempPos = items[i]->getPos();
		//renders the items in the inventory
		Vec3 ScreenPos = projection * Vec3(30.0, 200.0, 0.0);
		images[i].x = (int)ScreenPos.x;
		images[i].y = (int)ScreenPos.y;
		images[i].w = itemImage->w;
		images[i].h = itemImage->h;
		SDL_BlitSurface(itemImage, nullptr, screenSurface, &images[i]);
	}
	SDL_UpdateWindowSurface(window);
}