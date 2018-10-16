#include"UI.h"

UI::UI(){
	init();
}

UI::~UI(){
	final();
}

void UI::init() {
	G_frame       = LoadGraph("img/UI/frame.png");
	G_play_Button = LoadGraph("img/UI/PlayButton.png");
	G_stop_Button = LoadGraph("img/UI/StopButton.png");
	G_speed_UP0   = LoadGraph("img/UI/UP_0.png");
	G_speed_UP1   = LoadGraph("img/UI/UP_1.png");
	G_speed_Down0 = LoadGraph("img/UI/DOWN_0.png");
	G_speed_Down1 = LoadGraph("img/UI/DOWN_1.png");

	Play = true;
	UP_down = false;
	DOWN_down = false;

	button_pressed = false;
}

void UI::final() {
	DeleteGraph(G_frame);
	DeleteGraph(G_play_Button);
	DeleteGraph(G_stop_Button);
	DeleteGraph(G_speed_UP0);
	DeleteGraph(G_speed_UP1);
	DeleteGraph(G_speed_Down0);
	DeleteGraph(G_speed_Down1);

}

void UI::update() {
	button_pressed = false;

	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (Play)Play = false;
		else Play = true;

		button_pressed = true;
	}

	if (CheckHitKey(KEY_INPUT_UP)) {
		UP_down = true;

		button_pressed = true;
	}
	else UP_down = false;

	if (CheckHitKey(KEY_INPUT_DOWN)) {
		DOWN_down = true;

		button_pressed = true;
	}
	else DOWN_down = false;
}

void UI::draw() {
	DrawGraph(0,0,G_frame,TRUE);

	if (Play)DrawGraph(430,300,G_play_Button,TRUE);
	else DrawGraph(430, 300,G_stop_Button, TRUE);

	if (!UP_down)DrawGraph(530,300,G_speed_UP0,TRUE);
	else DrawGraph(530, 300, G_speed_UP1, TRUE);

	if (!DOWN_down)DrawGraph(530,337,G_speed_Down0,TRUE);
	else DrawGraph(530, 337, G_speed_Down1, TRUE);
}

void UI::input_wait() {
	if (button_pressed)WaitTimer(200);
}