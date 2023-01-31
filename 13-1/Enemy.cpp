#include "Enemy.h"
#include <Novice.h>
Enemy::Enemy(int x, int y, Player* player) {
	posX_ = x;
	posY_ = y;
	player_ = player;
	speed_ = 1;
}

Enemy::~Enemy() {

};

void Enemy::Update() {
	posX_ += speed_;
	if (posX_ > 1280 - 2 || posX_ < 2) {
		speed_ *= -1;
	}
	for (int i = 0; i < kBulletMax; i++) {
		if (abs(player_->bullet_[i]->bullet_.x - posX_) < 3 &&
			abs(player_->bullet_[i]->bullet_.y - posY_) < 3) {
			isEnemy = 0;
		}
	}
}

void Enemy::Draw() {
	Novice::DrawEllipse(posX_, posY_, 2, 2, 0, RED, kFillModeSolid);
}