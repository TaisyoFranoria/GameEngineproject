#pragma once
#include"io.h"
//UI（ユーザーインターフェース。ボタンとかの事）を司る部分

class UI {
public:
	//マス目　単独顕現
	int GRID;
	//UIのグラフィックハンドル　０：押してない状態　１：押し込み状態
	int G_frame;

	int G_play_Button;

	int G_stop_Button;

	int G_speed_UP0;
	int G_speed_UP1;

	int G_speed_Down0;
	int G_speed_Down1;

	bool Play; 
	bool UP_down;
	bool DOWN_down;

	bool button_pressed;

	UI();
	~UI();

	void init();
	void final();
	void update();
	void draw();
	void input_wait();

private:
	int LOGO;//ロゴのハンドル

};