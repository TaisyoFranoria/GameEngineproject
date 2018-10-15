#pragma once
#include"io.h"
#include<vector>
#include<string>

class animItem {
public:
	int x;
	int y;
	std::vector<int> gra;
	int animLength;
	int speed;

	animItem();
	~animItem();
	void init();
	void final();
	void AnimGraph_Load();
};