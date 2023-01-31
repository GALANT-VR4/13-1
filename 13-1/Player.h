#include "Bullet.h"
#pragma once
typedef struct Transform {
	int x;
	int y;
	int r;
};
const int kBulletMax = 20;
class Player {
public:
	Player(Transform t, int speed);
	~Player();
	void Update(char* keys, char* preKeys);
	void Draw();
public:
	Transform transform_;
	int speed_;
	Bullet* bullet_[kBulletMax];
};