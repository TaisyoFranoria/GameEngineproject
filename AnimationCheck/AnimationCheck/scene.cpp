#include"scene.h"

scene::scene() {
	init();
}

scene::~scene() {
	final();
}

//init関数　UI（ボタンとか）とanimItem(動かすアニメーション）のオブジェクトを生成する
void scene::init() {
	scene_Alive = true;
	anim_ = new animItem();
	ui = new UI();
}

//生成したオブジェクトを消す
void scene::final() {
	delete anim_;
	delete ui;
}

//計算部分　UIへの操作をanimItemに渡す役割も行っている
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
	DrawFormatString(430,170,GetColor(0,200,150),"画像の枚数:%d枚",anim_->gra.size());
	DrawFormatString(430, 200, GetColor(0, 200, 150), "PLAY SPEED : %d", anim_->speed+10);
}

void scene::update_late() {
	ui->input_wait();
}

