#include"STARTorSELECT.h"

st_sel::st_sel(std::string path,int mode) {
	alive = true;
	gra = LoadGraph(path.c_str());
	this->mode = mode;
	sound = LoadSoundMem("ki.mp3");
}

st_sel::~st_sel() {
	DeleteGraph(gra);
}

void st_sel::update() {

	switch (mode) {
	case 0:
		if (CheckHitKey(KEY_INPUT_1)) {
			PlaySoundMem(sound, DX_PLAYTYPE_BACK);
			state_num = 1;
			alive = false;
			break;
		}
		if (CheckHitKey(KEY_INPUT_2)) {
			PlaySoundMem(sound, DX_PLAYTYPE_BACK);
			state_num = 2;
			alive = false;
			break;
		}
		if (CheckHitKey(KEY_INPUT_3)) {
			PlaySoundMem(sound, DX_PLAYTYPE_BACK);
			state_num = 3;
			break;
		}
		if (CheckHitKey(KEY_INPUT_4)) {
			PlaySoundMem(sound, DX_PLAYTYPE_BACK);
			state_num = 4;
			alive = false;
			break;
		}
		if (CheckHitKey(KEY_INPUT_5)) {
			PlaySoundMem(sound, DX_PLAYTYPE_BACK);
			state_num = 5;
			alive = false;
			break;
		}
		break;
	case 1:
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			PlaySoundMem(sound, DX_PLAYTYPE_BACK);
			alive = false;
		}
		break;
	default:
		break;
	}
}



void st_sel::draw() {
	DrawGraph(0,0,gra,TRUE);
}