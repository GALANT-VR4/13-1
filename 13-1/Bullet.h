#pragma once
typedef struct Bullet_ {
	int x;
	int y;
	int r;
	int speed;
	int isShot;
};
class Bullet {
public:
	Bullet();
	~Bullet();
	void Update();
	void Draw();
public:
	Bullet_ bullet_;
};