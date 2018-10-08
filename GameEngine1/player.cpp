#include"player.h"
#include"graphX.h"

#define WALKTIME 15
#define CELL_WIDTH 32
#define CELL_HEIGHT 32


player::player(int x, int y) {
	//ドット絵
	//LoadDivGraph("img/charS01.png", 24, 6, 4, 32, 48, gh);
	//LoadDivGraph("img/charS02.png", 24, 6, 4, 32, 48, ghg);

	//
	for (int j = 0; j < 56; j++) {
		gh[j] = SHIK::GraShikimi(j);
	}


	GetGraphSize(gh[0], &width, &height);

	skill3flag = false;
	boostFlag = false;
	walkFlag = false;
	OVERHEAT = false;
	OVERHEAT_P = 0;
	Xcount = 0;
	ableWalk = true;
	walk_now = false;
	stan = false;
	walkvec = 6;
	animCount = 0;
	this->x = x * CELL_WIDTH;
	this->y = y * CELL_WIDTH;
	speed = 2;
	targetX = this->x;
	targetY = this->y;
	boost_Gage_Max = 5.0;
	boost_Gage = boost_Gage_Max;
	skill1stan = 0;
	skill2stan = 0;
	skill3stan = 0;


	LoadDivGraph("img/energycanon.png", 3, 3, 1, 32, 32, tam);

	i = 0;

	//ステータス初期化
	HP_MAX = 25000;
	HP = HP_MAX;
	SP_MAX = 25000;
	SP = SP_MAX;
	SPD = 1;
	DEF = 0;
}

player::~player() {
	for (int i = 0; i < sizeof(gh) / sizeof(gh[0]);i++) {
		DeleteGraph(gh[i]);
	}
}

void player::AnimationView(int animState, int firstNum) {
	//(*1)は完成の際に消す。もとは（＊2）
	if (skill3flag) {
		if (animState == 0)DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[firstNum], TRUE);
		if (animState == 1)DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[firstNum + 1], TRUE);
		if (animState == 2)DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[firstNum + 2], TRUE);
		if (animState == 3)DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[firstNum + 1], TRUE);
	}
	else {
		if (animState == 0)DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[firstNum], TRUE);
		if (animState == 1)DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[firstNum + 1], TRUE);
		if (animState == 2)DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[firstNum + 2], TRUE);
		if (animState == 3)DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[firstNum + 1], TRUE);
	}
	//if (animState == 0)DrawExtendGraph(x, y + height / 2, x + width * 1, y + height * 1 + height / 2, gh[firstNum], TRUE); 
	//差分サンプル:下は通常

}





void player::Move() {
	walkFlag = false;
	if (targetX == x && targetY == y) {//移動中でなければ
		if (CheckHitKey(KEY_INPUT_DOWN)) {
			walk_now = true;
			walkFlag = true;
			walkvec = 2;
			targetY += CELL_HEIGHT;//targetYを1マス分移動
								   //hanntei
			//if (IsAbleToGo(targetX, targetY - CELL_HEIGHT, walkvec) == 1)targetY -= CELL_HEIGHT;
			//右下移動
			if (CheckHitKey(KEY_INPUT_DOWN) && CheckHitKey(KEY_INPUT_RIGHT)) {
				walkFlag = true;
				walkvec = 3;
				targetX += CELL_WIDTH;
				//hanntei

			}
			//左下移動
			if (CheckHitKey(KEY_INPUT_DOWN) && CheckHitKey(KEY_INPUT_LEFT)) {
				walkFlag = true;
				walkvec = 1;
				targetX -= CELL_WIDTH;
				//hanntei

			}
			HP--;

			Xcount += CELL_WIDTH;
		}
		else if (CheckHitKey(KEY_INPUT_LEFT)) {
			walk_now = true;
			walkFlag = true;
			walkvec = 4;
			targetX -= CELL_WIDTH;
			//hanntei
			//if (IsAbleToGo(targetX - CELL_WIDTH, targetY, walkvec) == 1)targetX += CELL_HEIGHT;
			//左下移動
			if (CheckHitKey(KEY_INPUT_DOWN) && CheckHitKey(KEY_INPUT_LEFT)) {
				walkFlag = true;
				walkvec = 1;
				targetY += CELL_HEIGHT;
				//hanntei

			}
			//左上移動
			if (CheckHitKey(KEY_INPUT_UP) && CheckHitKey(KEY_INPUT_LEFT)) {
				walkFlag = true;
				walkvec = 7;
				targetY -= CELL_HEIGHT;
				//hanteu

			}
			HP--;
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT)) {
			walk_now = true;
			walkFlag = true;
			walkvec = 6;
			targetX += CELL_WIDTH;
			//通行不可能判定
			//if (IsAbleToGo(targetX - CELL_WIDTH, targetY, walkvec) == 1)targetX -= CELL_HEIGHT;
			//右下井戸う
			if (CheckHitKey(KEY_INPUT_DOWN) && CheckHitKey(KEY_INPUT_RIGHT)) {
				walkFlag = true;
				walkvec = 3;
				targetY += CELL_HEIGHT;
				//通行不可能判定

			}
			//右上移動
			if (CheckHitKey(KEY_INPUT_UP) && CheckHitKey(KEY_INPUT_RIGHT)) {
				walkFlag = true;
				walkvec = 9;
				targetY -= CELL_HEIGHT;
				//通行不可能判定

			}
			HP--;
		}
		else if (CheckHitKey(KEY_INPUT_UP)) {
			walk_now = true;
			walkFlag = true;
			walkvec = 8;
			targetY -= CELL_HEIGHT;
			//通行不可能判定
			//if (IsAbleToGo(targetX, targetY + CELL_HEIGHT, walkvec) == 1)targetY += CELL_HEIGHT;

			//右上移動
			if (CheckHitKey(KEY_INPUT_UP) && CheckHitKey(KEY_INPUT_RIGHT)) {
				walkFlag = true;
				walkvec = 9;
				targetX += CELL_WIDTH;
				//通行不可能判定

			}
			//左上移動
			if (CheckHitKey(KEY_INPUT_UP) && CheckHitKey(KEY_INPUT_LEFT)) {
				walkFlag = true;
				walkvec = 7;
				targetX -= CELL_WIDTH;
				//通行不可能判定

			}
			HP--;

		}

		else {
			animCount = 0;//キーが押されておらず、移動が完了していればanimCountをリセット
		}
	}
	else {
		walkFlag = true;
	}

	if (y < targetY)y += speed;
	if (x > targetX)x -= speed;
	if (x < targetX)x += speed;
	if (y > targetY)y -= speed;



}

void player::View() {
	int animState = animCount / WALKTIME;//WALKTIMEの倍数

	if (animState == 4) {
		animCount = 0;
		animState = 0;
	}
	if (OVERHEAT == true || stan == true) {

		if (walkvec == 2) {
			DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[24], TRUE);
		}
		if (walkvec == 3) {
			DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[27], TRUE);
		}
		if (walkvec == 4) {
			DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[26], TRUE);
		}
		if (walkvec == 6) {
			DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[28], TRUE);
		}
		if (walkvec == 7) {
			DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[29], TRUE);
		}
		if (walkvec == 8) {
			DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[30], TRUE);
		}
		if (walkvec == 9) {
			DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[31], TRUE)
				;
		}
		if (walkvec == 1) {
			DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[25], TRUE);
		}
	}
	else if (skill3flag == true) {
		if (walkFlag) {

			if (walkvec == 2) {
				AnimationView(animState, 0);
			}
			if (walkvec == 3) {
				AnimationView(animState, 9);
			}
			if (walkvec == 4) {
				AnimationView(animState, 6);
			}
			if (walkvec == 6) {
				AnimationView(animState, 12);
			}
			if (walkvec == 7) {
				AnimationView(animState, 15);
			}
			if (walkvec == 8) {
				AnimationView(animState, 18);
			}
			if (walkvec == 9) {
				AnimationView(animState, 21);
			}
			if (walkvec == 1) {
				AnimationView(animState, 4);
			}

			animCount++;
		}
		else {
			//(*1)は完成の際に消す。もとは（＊2）
			i++;
			if (i > 1) {
				i = 0;
			}
			if (walkvec == 2) {
				DrawExtendGraph(x - width / 4 - (i * 3), y - height / 4, x + width / 4 - (i * 3), y + height / 4, gh[32 + i], TRUE);
			}
			if (walkvec == 3) {
				DrawExtendGraph(x - width / 4 - (i * 3), y - height / 4, x + width / 4 - (i * 3), y + height / 4, gh[41 + i], TRUE);
			}
			if (walkvec == 4) {
				DrawExtendGraph(x - width / 4 - (i * 3), y - height / 4, x + width / 4 - (i * 3), y + height / 4, gh[38 + i], TRUE);
			}
			if (walkvec == 6) {
				DrawExtendGraph(x - width / 4 - (i * 3), y - height / 4, x + width / 4 - (i * 3), y + height / 4, gh[44 + i], TRUE);
			}
			if (walkvec == 7) {
				DrawExtendGraph(x - width / 4 - (i * 3), y - height / 4, x + width / 4 - (i * 3), y + height / 4, gh[47 + i], TRUE);
			}
			if (walkvec == 8) {
				DrawExtendGraph(x - width / 4 - (i * 3), y - height / 4, x + width / 4 - (i * 3), y + height / 4, gh[50 + i], TRUE);
			}
			if (walkvec == 9) {
				DrawExtendGraph(x - width / 4 - (i * 3), y - height / 4, x + width / 4 - (i * 3), y + height / 4, gh[53 + i], TRUE);
			}
			if (walkvec == 1) {
				DrawExtendGraph(x - width / 4 - (i * 3), y - height / 4, x + width / 4 - (i * 3), y + height / 4, gh[35 + i], TRUE);
			}

		}
	}
	else {
		if (walkFlag) {
			if (walkvec == 2) {
				AnimationView(animState, 0);
			}
			if (walkvec == 3) {
				AnimationView(animState, 9);
			}
			if (walkvec == 4) {
				AnimationView(animState, 6);
			}
			if (walkvec == 6) {
				AnimationView(animState, 12);
			}
			if (walkvec == 7) {
				AnimationView(animState, 15);
			}
			if (walkvec == 8) {
				AnimationView(animState, 18);
			}
			if (walkvec == 9) {
				AnimationView(animState, 21);
			}
			if (walkvec == 1) {
				AnimationView(animState, 4);
			}

			animCount++;
		}
		else {
			//(*1)は完成の際に消す。もとは（＊2）
			if (walkvec == 2) {
				DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[1], TRUE);
			}
			if (walkvec == 3) {
				DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[10], TRUE);
			}
			if (walkvec == 4) {
				DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[7], TRUE);
			}
			if (walkvec == 6) {
				DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[13], TRUE);
			}
			if (walkvec == 7) {
				DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[15], TRUE);
			}
			if (walkvec == 8) {
				DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[19], TRUE);
			}
			if (walkvec == 9) {
				DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[22], TRUE);
			}
			if (walkvec == 1) {
				DrawExtendGraph(x - width / 4, y - height / 4, x + width / 4, y + height / 4, gh[4], TRUE);
			}
		}
	}

}
void player::boost() {
	boostFlag = true;

	walkFlag = false;
	if (targetX == x && targetY == y) {//移動中でなければ
		if (CheckHitKey(KEY_INPUT_DOWN)) {
			walkFlag = true;
			walkvec = 2;
			targetY += CELL_HEIGHT * 3;//targetYを1マス分移動
		}
		else if (CheckHitKey(KEY_INPUT_LEFT)) {
			walkFlag = true;
			walkvec = 4;
			targetX -= CELL_WIDTH * 3;
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT)) {
			walkFlag = true;
			walkvec = 6;
			targetX += CELL_WIDTH * 3;
		}
		else if (CheckHitKey(KEY_INPUT_UP)) {
			walkFlag = true;
			walkvec = 8;
			targetY -= CELL_HEIGHT * 3;
		}
		else {
			animCount = 0;//キーが押されておらず、移動が完了していればanimCountをリセット
		}
	}
	else {
		walkFlag = true;
	}

	if (y < targetY)y += speed * 1;
	if (x > targetX)x -= speed * 1;
	if (x < targetX)x += speed * 1;
	if (y > targetY)y -= speed * 1;
	boost_Gage -= 0.01;
	if (boost_Gage <= 0.0) {
		boost_Gage = 0.0;
		OVERHEAT = true;
		OVERHEAT_P = 100;
	}
	if (boostFlag) {
		//HP+=250;
	}

}

void player::R_boost() {
	if(boost_Gage<=boost_Gage_Max)boost_Gage += 0.01;
	if (OVERHEAT&&boost_Gage>=5.0) {
		OVERHEAT = false;
	}
}

void player::FastMove(int Run_num) {
	for (int i = 0; i < Run_num; i++)Move();
}

void player::BoostGear(int Run_num) {
	for (int i = 0; i < Run_num; i++)boost();
}

void player::update() {
	if (OVERHEAT==false) {
		FastMove(4);
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			BoostGear(7);
		}
	}
	R_boost();
}