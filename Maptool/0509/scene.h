#pragma once
#include"io.h"


class scene {
public:
	bool alive;
	std::vector<int> mapchip;
	int menu;
	bool menu_switch;
	int hantei[15][20];
	int sound;

	scene(std::string csv_path);
	~scene();
	void init(std::string csv_path);
	void final();
	void update();
	void draw();
	void update_late();


private:
	void LoadMapGraph();
	void LoadData(std::string path);
};