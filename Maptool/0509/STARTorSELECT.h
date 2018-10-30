#pragma once
#include"io.h"

class st_sel {
public:
	bool alive;
	int gra;
	int sound;
	int state_num;

	st_sel(std::string path,int mode);
	~st_sel();
	void update();
	void draw();
private:
	int mode;
};