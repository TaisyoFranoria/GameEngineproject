#include"io.h"
#include"AnimationEngine2D.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	SetMainWindowText("プレゼン");
	SetGraphMode(1280,720,32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	AnimationEngine2D* ae2 = new AnimationEngine2D(); 
	

	//以下背景３Dモデルの処理
	int MH;
	int back;
	int AI;
	float PT;
	float TT;

	float camX = 0;
	float camY = 17;
	float camZ = -20;

	float sX = 0;
	float sY = -10;
	float sZ = -50;
	//モデルの読み込み

	bool reset = false;

	MH = MV1LoadModel("3D/cyber/shikimi_MMD.pmd");
	back = MV1LoadModel("3D/cyber/cyberzone.pmd");

	//カメラの描画範囲
	SetCameraNearFar(0.1f, 1000.0f);

	//カメラの位置（何処からどこを見るか）
	SetCameraPositionAndTarget_UpVecY(VGet(camX, camY, camZ), VGet(0.0f, 10.0f, 0.0f));

	//一番最初のアニメーションをアタッチする
	AI = MV1AttachAnim(MH, 1, -1, FALSE);

	//アニメーションの総合時間を取得
	TT = MV1GetAnimTotalTime(MH, AI);

	//アニメーション開始時間を初期化
	PT = 0.0f;




	while(ProcessMessage() != -1 && !ScreenFlip() && !ClearDrawScreen()){
		//背景3D

		//再生時間を進める
		PT += 0.2f;

		//再生時間がアニメーションの最大時間になったらPTをリセット
		if (PT >= TT) {
			PT = 0.0f;
		}


		SetCameraPositionAndTarget_UpVecY(VGet(camX, camY, camZ), VGet(0.0f, 10.0f, -5000.0f));

		MV1SetAttachAnimTime(MH, AI, PT);
		MV1SetPosition(MH, VGet(camX + sX, camY + sY, camZ + sZ));

		MV1DrawModel(back);
		//MV1DrawModel(MH);

		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			if (camX > -20)camX--;
		}
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			if (camX < 20)camX++;
		}
		if (CheckHitKey(KEY_INPUT_ESCAPE))break;
		camZ -= 6;
		if (camZ <= -200)camZ = 1100;


		//
		ae2->update();
		ae2->draw();
		if (!ae2->alive)break;
		ae2->update_late();
		
	}


	delete ae2;

	DxLib_End();

	return 0;
}
