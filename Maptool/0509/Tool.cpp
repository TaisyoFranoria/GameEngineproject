#include"TOOL.h"

Tool::Tool() {
	init();
}

Tool::~Tool() {
	final();
}

void Tool::init() {
	alive = true;
	state = 0;
	csv_num = 0;
	MakeScene();
	start_screen = new st_sel("img/start.png",1);
	select_screen = new st_sel("img/select.png",0);
}

void Tool::final() {
	for (int i = 0, n = (signed)sc.size(); i < n; i++) {
		delete sc[i];
	}
	delete start_screen;
	delete select_screen;
}

void Tool::update() {
	switch (state) {
	case 0:
		if (select_screen->alive) {
			select_screen->update();
		}
		else {
			state++; 
			csv_num = select_screen->state_num;
		}
		break;
	case 1:
		if (start_screen->alive) {
			start_screen->update();
		}
		else state++;
		break;
	case 2:
		if(sc[csv_num]->alive)sc[csv_num]->update();
		else alive=false;
		break;
	default:
		break;
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE))alive = false;
}

void Tool::draw() {
	switch (state) {
	case 0:
		select_screen->draw();
		break;
	case 1:
		start_screen->draw();
		break;
	case 2:
		sc[csv_num]->draw();
		break;
	default:
		break;
	}
}

void Tool::update_late() {

}

void Tool::MakeScene() {
	for (int i = 1; i <= 5; i++) {
		std::string path = "map_col/1.csv";
		this->sc.push_back(new scene(path));
	}
}

void Tool::all() {
	update();
	draw();
	update_late();
	DrawFormatString(0, 0, 0xFFFFFF, "test:%d", sc[0]->hantei[1][1]);
}