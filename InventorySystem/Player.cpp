#include "Player.h"
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
				std::cout << pos.x << std::endl;
				pos.y += 5;
				break;
			case SDLK_a:
				std::cout << "pressing a" << std::endl;
				std::cout << pos.x << std::endl;
				pos.x -= 5;
				break;
			case SDLK_s:
				std::cout << "pressing s" << std::endl;
				std::cout << pos.x << std::endl;
				pos.y -= 5;
				break;
			case SDLK_d:
				std::cout << "pressing d" << std::endl;
				std::cout << pos.x << std::endl;
				pos.x += 5;
				break;
			default:
				break;
			}
		}
	}
}
