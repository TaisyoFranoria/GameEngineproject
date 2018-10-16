#include"io.h"
#include"AnimationEngine2D.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	SetMainWindowText("CheckAnimation");
	SetGraphMode(640, 480, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	AnimationEngine2D* ae2 = new AnimationEngine2D();

	while(ProcessMessage() != -1 && !ScreenFlip() && !ClearDrawScreen()){

		ae2->update();
		ae2->draw();
		if (!ae2->alive)break;
		ae2->update_late();
		
	}


	delete ae2;

	DxLib_End();

	return 0;
}
