#include"scene.h"

scene::scene() {
	init();
}

scene::~scene() {
	final();
}

//init�֐��@UI�i�{�^���Ƃ��j��animItem(�������A�j���[�V�����j�̃I�u�W�F�N�g�𐶐�����
void scene::init() {
	scene_Alive = true;
	anim_ = new animItem();
	ui = new UI();
}

//���������I�u�W�F�N�g������
void scene::final() {
	delete anim_;
	delete ui;
}

//�v�Z�����@UI�ւ̑����animItem�ɓn���������s���Ă���
void scene::update() {
	ui->update();
	if (ui->UP_down)anim_->speed++;
	if (ui->DOWN_down)anim_->speed--;
	if(ui->Play)anim_->update();	
	WaitTimer(5);
}

void scene::draw() {
	DrawGraph(0, 0, ui->GRID, TRUE);

	anim_->draw();
	ui->draw();

	SetFontSize(24);
	DrawFormatString(430,170,GetColor(0,200,150),"�摜�̖���:%d��",anim_->gra.size());
	DrawFormatString(430, 200, GetColor(0, 200, 150), "PLAY SPEED : %d", anim_->speed+10);
}

void scene::update_late() {
	ui->input_wait();
}

