#pragma once
#include"io.h"
#include"scene.h"
//AnimationEngine2D�N���X�́h�A�j���[�V�����`�F�b�J�[���̂��́h�̃N���X
//������e�ł���h�V�[���h�N���X���Ǘ�����B


class AnimationEngine2D{
public:
	bool alive;
	scene* sc;
	
	AnimationEngine2D();
	~AnimationEngine2D();
	void init();
	void final();
	void update();
	void draw();
	void update_late();
};