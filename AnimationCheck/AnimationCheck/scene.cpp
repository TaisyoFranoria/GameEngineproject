#include"scene.h"

scene::scene() {
	init();
}

scene::~scene() {
	final();
}

void scene::init() {
	scene_Alive = true;
	anim_ = new animItem();
}

void scene::final() {
	
}

void scene::update() {

}

void scene::draw() {
	DrawFormatString(0,0,GetColor(255,255,255),"AnimLength:%d",anim_->animLength);
}
