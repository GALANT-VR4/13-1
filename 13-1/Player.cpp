#include "Player.h"
#include <Novice.h>

Player::Player(Transform t, int speed) {
	this->transform_ = t;
	speed_ = speed;
	for (int i = 0; i < kBulletMax; i++) {
		bullet_[i] = new Bullet();
	}
}

Player::~Player() {
	for (int i = 0; i < kBulletMax; i++) {
		delete bullet_[i];
	}
};

void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		transform_.y -= speed_;
	}
	if (keys[DIK_S]) {
		transform_.y += speed_;
	}
	if (keys[DIK_A]) {
		transform_.x -= speed_;
	}
	if (keys[DIK_D]) {
		transform_.x += speed_;
	}
	for (int i = 0; i < kBulletMax; i++) {
		bullet_[i]->Update();
	}
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		for (int i = 0; i < kBulletMax; i++) {
			if (!bullet_[i]->bullet_.isShot) {
				bullet_[i]->bullet_ = { this->transform_.x,this->transform_.y, 1,2,1 };
				break;
			}
		}
	}
}

void Player::Draw() {
	Novice::DrawEllipse(transform_.x, transform_.y, transform_.r, transform_.r, 0, WHITE, kFillModeSolid);
	for (int i = 0; i < kBulletMax; i++) {
		bullet_[i]->Draw();
	}
}