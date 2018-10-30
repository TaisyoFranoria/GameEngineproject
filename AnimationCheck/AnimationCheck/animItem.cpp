#include"animItem.h"

animItem::animItem() {
	init();
}

animItem::~animItem() {
	final();
}

void animItem::init() {
	x = 25;
	y = 45;
	limit = 10;
	play_time = 0;
	counter = 0;
	
	//可変可能にするにはここに変更を加える。(現時点ではサンプルのみ)
	AnimGraph_Load("sample");

	if (gra.size()>=50) {
		speed = 5;
	}
	else speed = -5;//10が最速
}

void animItem::final() {
	for (int i = 0; i < gra.size();i++) {
		DeleteGraph(gra[i]);
	}
}

void animItem::update()  {
	counter++;
	if (counter >= SPEEDtoLIMIT(speed)) {
		play_time++;
		counter = 0;
	}

	if (play_time >= gra.size())play_time = 0;

	if (speed >= 10) speed = 10;
	if (speed <= -10)speed = -9;
}

void animItem::draw() {
	DrawExtendGraph(x,y,x+384,y+384,gra[play_time],TRUE);
}

//画像群を読み込む関数
void animItem::AnimGraph_Load(std::string name){
	bool success = false;
	std::string fileh = "img/animation/" + name + "/";
	std::string filename;
	for (int i = 0; i < 100; i++) {
		filename = fileh + std::to_string(i) + ".png";
		int a = LoadGraph(filename.c_str());
		if (a != -1) {
			this->gra.push_back(a);
			success = true;
		}

	}
	if (!success)this->gra.push_back(LoadGraph("img/animation/nodata.png"));
}

//変更されたスピードの値を再生速度として反映させるために必要な処理
int animItem::SPEEDtoLIMIT(int speed) {

	limit - speed;
	
	if (limit <= 1)limit = 1;

	return limit*-speed/10;
}

