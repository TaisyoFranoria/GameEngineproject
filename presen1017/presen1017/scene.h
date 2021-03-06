#pragma once
#include"io.h"
#include"animItem.h"
#include"UI.h"
#include"Qwindow.h"

class scene {
public:
	scene();
	~scene();
	void init();
	void final();

	void update();
	void draw();
	void update_late();
	
private:
	bool scene_Alive;
	animItem* anim_;
	UI* ui;
	Qwindow* Q;

	int playspeed(int speed);
};