#pragma once
#include"io.h"
#include"player.h"
#include"Map.h"

class scene {
private:
	Map* map;
	player* players;
	player* target;

public:
	bool scene_Alive;
	float scene_Time;

	scene();
	~scene();
	void init();
	void final();
	void update();
	void draw();
	void all();
};