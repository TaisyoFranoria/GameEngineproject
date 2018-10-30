#include"AnimationEngine2D.h"

//コンストラクタ…オブジェクトが作成される際の初期化処理（実際の処理はinit()で行っている）
AnimationEngine2D::AnimationEngine2D() {
	init();
}

//デストラクタ…オブジェクトが消滅する際の処理（上におなじく実際の処理はfinal()にて定義）
AnimationEngine2D::~AnimationEngine2D() {
	final();
}

//コンストラクタにおける処理　主にシーンクラスを生成する
void AnimationEngine2D::init(){
	alive = true;
	sc = new scene();
}

//デストラクタにおける実際の処理　シーンクラスオブジェクトを消滅させる（必須の動作）
void AnimationEngine2D::final(){
	delete sc;
}

//update関数は主に計算部分を担う関数（javaでいうメソッド）
void AnimationEngine2D::update(){

	if (CheckHitKey(KEY_INPUT_ESCAPE))alive=false;

	sc->update();
}

//draw関数は描画、可視化部分を担う関数
void AnimationEngine2D::draw(){
	sc->draw();
}

//後判定update関数。描画より後にする必要がある計算部分を担うためにある。
void AnimationEngine2D::update_late() {
	sc->update_late();
}

