#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet() {
	bullet_ = { 0,0,1,0,0 };
};

Bullet::~Bullet() {

};

void Bullet::Update() {
	if (bullet_.isShot) {
		bullet_.y -= bullet_.speed;
	}
	if (bullet_.y < -bullet_.r) {
		bullet_.isShot = 0;
	}
}

void Bullet::Draw() {
	if (bullet_.isShot) {
		Novice::DrawEllipse(bullet_.x, bullet_.y, bullet_.r, bullet_.r, 0, WHITE, kFillModeSolid);
	}
}