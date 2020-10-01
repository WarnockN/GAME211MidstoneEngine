#include "Player.h"

Player::Player() {
}

Player::Player(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_, float time_, float radius_):PhysicsObject(pos_, vel_, accel_, mass_, time_, radius_) {

}

Player::~Player() {
}
