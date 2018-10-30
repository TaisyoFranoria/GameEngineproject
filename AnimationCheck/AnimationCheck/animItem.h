#pragma once
#include"io.h"
#include<vector>
#include<string>
//animItem�N���X�́h�A�j���[�V������������́h���܂Ƃ߂��N���X�B�摜�Ȃǂ��܂�

class animItem {
public:
	std::vector<int> gra;
	int play_time;
	int speed;
	int counter;

	animItem();
	~animItem();
	void init();
	void final();
	void update();
	void draw();
	

private:
	int x;
	int y;
	int limit;

	void AnimGraph_Load(std::string name);
	int SPEEDtoLIMIT(int speed);
};