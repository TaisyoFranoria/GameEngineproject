#include"animItem.h"

animItem::animItem() {
	init();
}

animItem::~animItem() {
	final();
}

void animItem::init() {
	AnimGraph_Load();
}

void animItem::final() {

}

void animItem::AnimGraph_Load(){
	std::string fileh = "file\\";
	const char* s_png = ".png";
	std::string filename;
	for (int i = 0; i < 15; i++) {
		filename = fileh + std::to_string(i) + ".png";
		int a = LoadGraph(filename.c_str());
		if (a != NULL) {
			this->gra.push_back(a);
			animLength++;
		}

	}
}