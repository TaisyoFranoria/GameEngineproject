#pragma once
#include"io.h"
#include"animItem.h"
#include"UI.h"
//sceneクラスは”実際の動作そのもの”を担うクラス
//映画で言う撮影場所的な存在

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