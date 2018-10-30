#pragma once
#include"io.h"
#include"scene.h"
#include"STARTorSELECT.h"


class Tool {
public:
	bool alive;
	int state;
	int csv_num;
	std::vector<scene*> sc;
	st_sel* start_screen;
	st_sel* select_screen;

	Tool();
	~Tool();
	void init();
	void final();
	void all();
	
private:
	void MakeScene();
	void update();
	void draw();
	void update_late();
};