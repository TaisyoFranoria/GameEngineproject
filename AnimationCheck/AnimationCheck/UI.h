#pragma once
#include"io.h"
//UI�i���[�U�[�C���^�[�t�F�[�X�B�{�^���Ƃ��̎��j���i�镔��

class UI {
public:
	//�}�X�ځ@�P�ƌ���
	int GRID;
	//UI�̃O���t�B�b�N�n���h���@�O�F�����ĂȂ���ԁ@�P�F�������ݏ��
	int G_frame;

	int G_play_Button;

	int G_stop_Button;

	int G_speed_UP0;
	int G_speed_UP1;

	int G_speed_Down0;
	int G_speed_Down1;

	bool Play; 
	bool UP_down;
	bool DOWN_down;

	bool button_pressed;

	UI();
	~UI();

	void init();
	void final();
	void update();
	void draw();
	void input_wait();

private:
	int LOGO;//���S�̃n���h��

};