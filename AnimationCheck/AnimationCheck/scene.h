#pragma once
#include"io.h"
#include"animItem.h"
#include"UI.h"
//scene�N���X�́h���ۂ̓��삻�̂��́h��S���N���X
//�f��Ō����B�e�ꏊ�I�ȑ���

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