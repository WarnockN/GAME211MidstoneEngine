#include "Player.h"
#include "Inventory.h"
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
		else if (mouseIsAt.x > 0 && mouseIsAt.x < 400 && 
				 mouseIsAt.y > 0 && mouseIsAt.y < 200 && openInventory == true) {
			if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "left clicked" << std::endl;
			}
			if (event.button.button == SDL_BUTTON_RIGHT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "right clicked" << std::endl;
			}
		}
		else if (mouseIsAt.x > 400 && mouseIsAt.x < 800 && 
				 mouseIsAt.y > 200 && mouseIsAt.y < 400 && openInventory == true) {
			if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "left clicked" << std::endl;
			}
			if (event.button.button == SDL_BUTTON_RIGHT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "right clicked" << std::endl;
			}
		}
		else if (mouseIsAt.x > 0 && mouseIsAt.x < 400 && 
				 mouseIsAt.y > 200 && mouseIsAt.y < 400 && openInventory == true) {
			if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "left clicked" << std::endl;
			}
			if (event.button.button == SDL_BUTTON_RIGHT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "right clicked" << std::endl;
			}
		}
		else if (mouseIsAt.x > 400 && mouseIsAt.x < 800 && 
				 mouseIsAt.y > 0 && mouseIsAt.y < 200 && openInventory == true) {
			if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "left clicked" << std::endl;
			}
			if (event.button.button == SDL_BUTTON_RIGHT && event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "right clicked" << std::endl;
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