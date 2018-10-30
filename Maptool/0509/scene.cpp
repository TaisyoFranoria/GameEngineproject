#include"scene.h"

scene::scene(std::string csv_path) {
	init(csv_path);
}

scene::~scene() {
	final();
}

void scene::init(std::string csv_path) {
	alive = true;
	LoadMapGraph();
	LoadData(csv_path);
	menu = LoadGraph("img/menu.png");
	menu_switch = false;
	sound = LoadSoundMem("ki.mp3");
}

void scene::final() {

}

void scene::update() {
	if (CheckHitKey(KEY_INPUT_Z))menu_switch = true;

	if (menu_switch&&CheckHitKey(KEY_INPUT_Y))alive =false;
	if (menu_switch&&CheckHitKey(KEY_INPUT_N))menu_switch = false;

	if (CheckHitKey(KEY_INPUT_0)) {
		SaveDrawScreenToPNG(0, 0, 640, 480, "1.png", 1);
		PlaySoundMem(sound, DX_PLAYTYPE_BACK);
	}
}

void scene::draw() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 20; j++) {
			(j * 32, i * 32, mapchip[hantei[i][j]], TRUE);
		}
	}
	if (menu_switch)DrawGraph(200, 200, menu, TRUE);
}

void scene::update_late() {

}

void scene::LoadMapGraph() {
	for (int i = 0; i < 10; i++) {
		std::string path = "img/num/" + std::to_string(i) +".png";
		this->mapchip.push_back(LoadGraph(path.c_str()));
	}
}

void scene::LoadData(std::string path) {
	std::ifstream ifs(path);
	std::string str;
	int retu = 0;
	int gyou = 0;

	if (ifs.fail()) {
		std::cerr << "“Ç‚Ýž‚ÝŽ¸”s" << std::endl;
		DebugBreak();
	}

	while (getline (ifs, str)) {
		std::istringstream iss(str);
		while (getline(iss, str, ',')) {
		    //hantei[retu][gyou] = std::stoi(str);
			retu++;
		}
		gyou++;
	}
}