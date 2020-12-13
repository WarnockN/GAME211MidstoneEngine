#include "Player.h"
#include "Inventory.h"
Player::Player(){}
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
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_w:
				std::cout << "pressing w" << std::endl;
				pos.y += 5;
				break;
			case SDLK_a:
				std::cout << "pressing a" << std::endl;
				pos.x -= 5;
				break;
			case SDLK_s:
				std::cout << "pressing s" << std::endl;
				pos.y -= 5;
				break;
			case SDLK_d:
				std::cout << "pressing d" << std::endl;
				pos.x += 5;
				break;
			case SDLK_e:
				openInventory = !openInventory;
				//show items in inventory
				std::cout << "Open inventory" << std::endl;
				break;
			default:
				break;
			}
		}
		else if (event.type == SDL_MOUSEMOTION && openInventory == true) {
			if (event.button.x < 100) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					std::cout << "left" << std::endl;
				}
				else if (event.button.button == SDL_BUTTON_RIGHT) {
					//inventory->removeItem(1, );
					std::cout << "right" << std::endl;
				}
				std::cout << "-100" << std::endl;
			}
			else if (event.button.x < 200) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					std::cout << "left" << std::endl;
				}
				else if (event.button.button == SDL_BUTTON_RIGHT) {
					//inventory->removeItem(1, );
					std::cout << "right" << std::endl;
				}
				std::cout << "-200" << std::endl;
			}
			else if (event.button.x < 300) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					std::cout << "left" << std::endl;
				}
				else if (event.button.button == SDL_BUTTON_RIGHT) {
					//inventory->removeItem(1, );
					std::cout << "right" << std::endl;
				}
				std::cout << "-300" << std::endl;
			}
			else if (event.button.x < 400) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					std::cout << "left" << std::endl;
				}
				else if (event.button.button == SDL_BUTTON_RIGHT) {
					//inventory->removeItem(1, );
					std::cout << "right" << std::endl;
				}
				std::cout << "-400" << std::endl;
			}
			else if (event.button.x < 500) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					std::cout << "left" << std::endl;
				}
				else if (event.button.button == SDL_BUTTON_RIGHT) {
					//inventory->removeItem(1, );
					std::cout << "right" << std::endl;
				}
				std::cout << "-500" << std::endl;
			}
			else if (event.button.x < 600) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					std::cout << "left" << std::endl;
				}
				else if (event.button.button == SDL_BUTTON_RIGHT) {
					//inventory->removeItem(1, );
					std::cout << "right" << std::endl;
				}
				std::cout << "-600" << std::endl;
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
