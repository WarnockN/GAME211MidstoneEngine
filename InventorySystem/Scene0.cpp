#include "Scene0.h"
#include <SDL.h>
#include <SDL_Image.h>
#include "PhysicsObject.h"
#include "Collider.h"
#include "Inventory.h"
using namespace std;
Scene0::Scene0(SDL_Window* sdlWindow_):player(0), food(), foodImage(0), inventory(0), playerImage(0), inventoryImage(0), timer(0) {
	window = sdlWindow_;
}
Scene0::~Scene0(){}
bool Scene0::OnCreate() {
	
	//creates the screen
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w,h);
	Matrix4 ortho = MMath::orthographic(0.0, 400.0, 0.0, 200.0, 0.0, 1.0);
	projection = ndc * ortho;

	//creates inventory
	inventory = new Inventory();
	inventoryImage = IMG_Load("InventoryPlaceholder.png");
	if (inventoryImage == nullptr) cout << "image lost" << endl;

	//creates food items
	food[0] = new ItemFood(Vec3(150.0, 200.0, 0.0), 1.0f);
	food[1] = new ItemFood(Vec3(200.0, 100.0, 0.0), 1.0f);
	foodImage = IMG_Load("gingy.png");
	if (foodImage == nullptr) cout << "food image lost" << endl;





	//creates player
	player = new Player(Vec3(100.0, 200.0, 0.0), Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0), 15.0f);
	playerImage = IMG_Load("fortnite.png");
	if (playerImage == nullptr) cout << "player image lost" << endl;

	return true;
}
void Scene0::OnDestroy() {
	delete player;
	player = nullptr;
	delete food[0];
	food[0] = nullptr;
	delete food[1];
	food[1] = nullptr;
	delete inventory;
	inventory = nullptr;
	delete playerImage;
	playerImage = nullptr;
	delete foodImage;
	foodImage = nullptr;
	delete inventoryImage;
	inventoryImage = nullptr;
}
void Scene0::HandleEvents(const SDL_Event& event) {
	
}
void Scene0::Update(const float time) {
	for (int j = 0; j < 2; j++) {
		if (Collider::SphereSphereCollision(*player, *food[j])) {
			std::cout << "hit" << std::endl;


			
	
			int a = 0;
			if (a <= (inventory->cap)) {
				inventory->items[a] = food[j];
				inventory->items[a]->Destroy(inventory->items[a]);
				a++;
			}
			

		

			//add the item to this array vvvvv
			
			//array <Item*>itemArray{};

		};

		//std::cout << inventory->itemArr.size() << std::endl;
		//remove item from screen 
	
	};


	if (player->ShowInventory() == true) {
		renderInventory = true;
		//render the inventory
	}
	else {
		renderInventory = false;
	}
	player->PollEvents();

};




void Scene0::Render() {
	SDL_Rect images[4];
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));
	if (renderInventory == false) {
		for (int i = 0; i < 1; i++) {
			Vec3 ScreenPos = projection * player->getPos();
			images[i].x = (int)ScreenPos.x;
			images[i].y = (int)ScreenPos.y;
			images[i].w = playerImage->w;
			images[i].h = playerImage->h;
			SDL_BlitSurface(playerImage, nullptr, screenSurface, &images[i]);
		}
		for (int i = 1; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				Vec3 ScreenPos = projection * food[j]->getPos();
				images[i].x = (int)ScreenPos.x;
				images[i].y = (int)ScreenPos.y;
				images[i].w = foodImage->w;
				images[i].h = foodImage->h;
				SDL_BlitSurface(foodImage, nullptr, screenSurface, &images[i]);
			}
		}
	}
	if (renderInventory == true) {
		for (int i = 0; i < 1; i++) {
				//renders the inventory
				Vec3 ScreenPos = projection * Vec3(30.0, 200.0, 0.0);
				images[i].x = (int)ScreenPos.x;
				images[i].y = (int)ScreenPos.y;
				images[i].w = inventoryImage->w;
				images[i].h = inventoryImage->h;
				SDL_BlitSurface(inventoryImage, nullptr, screenSurface, &images[i]);
			
		}

	}
	SDL_UpdateWindowSurface(window);
}