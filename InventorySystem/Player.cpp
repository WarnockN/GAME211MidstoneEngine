#include "Player.h"

Player::Player() {
	pos = (0, 0, 0);
}

Player::~Player(){

}

void Player::PollEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_w:
				std::cout << "pressing w" << std::endl;
				pos.y += 15;
				break;
			case SDLK_a:
				std::cout << "pressing a" << std::endl;
				pos.x -= 15;
				break;
			case SDLK_s:
				std::cout << "pressing s" << std::endl;
				pos.y -= 15;
				break;
			case SDLK_d:
				std::cout << "pressing d" << std::endl;
				pos.x += 15;
				break;
			default:
				break;
			}
		}
	}
}
