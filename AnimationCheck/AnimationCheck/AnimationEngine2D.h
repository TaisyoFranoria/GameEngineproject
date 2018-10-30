#pragma once
#include"io.h"
#include"scene.h"
//AnimationEngine2Dクラスは”アニメーションチェッカーそのもの”のクラス
//動作内容である”シーン”クラスを管理する。


class AnimationEngine2D{
public:
	bool alive;
	scene* sc;
	
	AnimationEngine2D();
	~AnimationEngine2D();
	void init();
	void final();
	void update();
	void draw();
	void update_late();
};