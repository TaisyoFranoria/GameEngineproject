#pragma once
#include"io.h"

class player {
public:
	int i;
	int gh[32];
	int ghg[24];
	int width, height;
	int walkvec;
	int vec2;
	int animCount;
	int  skill1stan;
	int  skill2stan;
	int  skill3stan;
	bool walkFlag;
	bool OVERHEAT;
	bool walk_now;
	bool stan;
	bool ableWalk;
	bool boostFlag;
	bool skill3flag;

	int x, y;
	int speed;
	int targetX, targetY;
	float boost_Gage;
	float boost_Gage_Max;

	//デバッグ用変数
	int OVERHEAT_P;
	int Xcount;
	int tam[3];



	//ステータス

	int HP;
	int HP_MAX;
	int SP;
	int SP_MAX;
	int SPD;
	int DEF;


	
	player(int x,int y);
	~player();

	void AnimationView(int animState, int firstNum);
	void Move();
	void View();
	void boost();
	void R_boost();
	void FastMove(int Run_num);
	void BoostGear(int Run_num);
	void update();
};