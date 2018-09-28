#include"scene.h"
#include"player.h"
#include"Map.h"

scene::scene() {
	init();
}

scene::~scene() {
	final();
}

void scene::init() {
	map = new Map(1);
	players = new player(0, 0);
	target = new player(0, 0);
}

void scene::final() {
	delete map;
	delete players;
	delete target;
	map = nullptr;
	players = nullptr;
	target = nullptr;
	if (map != nullptr || players != nullptr || target != nullptr) {
		DebugBreak();
	}
}

void scene::update() {
	players->update();
}

void scene::draw() {
	map->View();
	players->View();
}

void scene::all() {
	draw();
	update();	
}