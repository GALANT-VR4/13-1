#pragma once
#include "Player.h"

class Enemy {
public:
	static int isEnemy;
	Enemy(int x, int y, Player* player);
	~Enemy();
	void Update();
	void Draw();
public:
	int posX_,posY_;
	int speed_;
	Player* player_;
};