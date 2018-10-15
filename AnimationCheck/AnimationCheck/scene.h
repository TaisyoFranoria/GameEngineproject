#pragma once
#include"io.h"
#include"animItem.h"

class scene {
public:
	bool scene_Alive;
	animItem* anim_;

	scene();
	~scene();
	void init();
	void final();

	void update();
	void draw();
};