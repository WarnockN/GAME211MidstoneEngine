#include "Player.h"

Player::Player():mouseIsAt(0.0f, 0.0f, 0.0f), inventory() {}
Player::~Player(){}
Player::Player(Vec3 pos_, Vec3 accel_, Vec3 vel_, float radius_):PhysicsObject(pos_, vel_, accel_, radius_) {
	pos = pos_;
	accel = accel_;
	vel = vel_;
	radius = radius_;
}
void Player::PollEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN && openInventory == false) {
			switch (event.key.keysym.sym) {
			case SDLK_w:
				pos.y += 5;
				break;
			case SDLK_a:
				pos.x -= 5;
				break;
			case SDLK_s:
				pos.y -= 5;
				break;
			case SDLK_d:
				pos.x += 5;
				break;
			case SDLK_e:
				openInventory = !openInventory;
				std::cout << "opening inventory" << std::endl;
				break;
			default:
				break;
			}
		}
		else if (event.type == SDL_KEYDOWN && openInventory == true) {
			switch (event.key.keysym.sym) {
			case SDLK_e:
				openInventory = !openInventory;
				std::cout << "closing inventory" << std::endl;
				break;
			default:
				break;
			}
		}
		else if (event.type == SDL_MOUSEMOTION && openInventory == true) {
			mouseIsAt = Vec3(float(event.button.x), float(event.button.y), 0.0f);
			std::cout << "mouse location X: " << mouseIsAt.x << " Y: " << mouseIsAt.y << std::endl;
		}
		else if (mouseIsAt.x > 155 && mouseIsAt.x < 250 && 
				 mouseIsAt.y > 133 && mouseIsAt.y < 225 && openInventory == true) {
			if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "left clicked item 1" << std::endl;
				if (inventory->numOfItems >=1) {
					//equip

				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "right clicked item 1" << std::endl;
				if (inventory->numOfItems >= 1) {
					//drop
					inventory->removeItem(inventory->items[0]->itemType, inventory->items[0]);
				}
			}
		}
		else if (mouseIsAt.x > 280 && mouseIsAt.x < 375 && 
				 mouseIsAt.y > 133 && mouseIsAt.y < 225 && openInventory == true) {
			if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "left clicked item 2" << std::endl;
				if (inventory->numOfItems >= 2) {
					//equip
					//do equip thing lmaooooo
				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "right clicked item 2" << std::endl;
				if (inventory->numOfItems >= 2) {
					//drop
					inventory->removeItem(inventory->items[1]->itemType, inventory->items[1]);
				}
			}
		}
		else if (mouseIsAt.x > 400 && mouseIsAt.x < 495 && 
				 mouseIsAt.y > 133 && mouseIsAt.y < 225 && openInventory == true) {
			if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "left clicked item 3" << std::endl;
				if (inventory->numOfItems >= 3) {
					//equip
				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "right clicked item 3" << std::endl;
				if (inventory->numOfItems >= 3) {
					//drop
					inventory->removeItem(inventory->items[2]->itemType, inventory->items[2]);
				}
			}
		}
	}
}
bool Player::ShowInventory()
{
	if (openInventory == true) {
		return true;
	}
		return false;
	//show inventory ui
	//redisplay collected items in thier respective locations
}

void Player::InventoryInit(Inventory* inv)
{

	inventory = inv;
}
