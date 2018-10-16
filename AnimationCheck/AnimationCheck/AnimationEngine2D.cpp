#include"AnimationEngine2D.h"

AnimationEngine2D::AnimationEngine2D() {
	init();
}

AnimationEngine2D::~AnimationEngine2D() {
	final();
}

void AnimationEngine2D::init(){
	alive = true;
	sc = new scene();
}

void AnimationEngine2D::final(){
	delete sc;
}

void AnimationEngine2D::update(){

	if (CheckHitKey(KEY_INPUT_ESCAPE))alive=false;

	sc->update();
}

void AnimationEngine2D::draw(){
	sc->draw();
}

void AnimationEngine2D::update_late() {
	sc->update_late();
}

