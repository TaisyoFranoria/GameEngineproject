#pragma once
#include"io.h"
#include"animItem.h"
#include"UI.h"
//sceneƒNƒ‰ƒX‚ÍhÀÛ‚Ì“®ì‚»‚Ì‚à‚Ìh‚ğ’S‚¤ƒNƒ‰ƒX
//‰f‰æ‚ÅŒ¾‚¤B‰eêŠ“I‚È‘¶İ

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
};