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
	ui = new UI();
	Q = new Qwindow();
}

void scene::final() {
	delete anim_;
	delete ui;
	delete Q;
}

void scene::update() {
	ui->update();
	if (ui->UP_down)anim_->speed++;
	if (ui->DOWN_down)anim_->speed--;
	if(ui->Play)anim_->update();	
	WaitTimer(5);

	Q->update();
}

void scene::draw() {
	DrawGraph(0, 0, ui->GRID, TRUE);

	Q->view();
	anim_->draw();
	ui->draw();

	SetFontSize(24);
	//DrawFormatString(430,170,GetColor(0,200,150),"‰æ‘œ‚Ì–‡”:%d–‡",anim_->gra.size());
	//DrawFormatString(430, 200, GetColor(0, 200, 150), "PLAY SPEED : %d", anim_->speed+10);
}

void scene::update_late() {
	ui->input_wait();
	if (Q->lunch==1) {
		Q->Lunch(Q->ac2d);
	}
}

int scene::playspeed(int speed) {
	int play_speed;

	switch (speed){
	case 1:
		play_speed = 100;
		break;
	default:
		play_speed = 1000;
		break;
	}

	return play_speed;
}
