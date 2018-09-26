#include"io.h"
#include"GameEngine.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetMainWindowText("GAmens");
	SetGraphMode(640, 480, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	Engine* engine = new Engine();

	while (ProcessMessage() != -1 && !ScreenFlip() && !ClearDrawScreen()) {
		engine->update();
		engine->view();
	}

	delete engine;


	DxLib_End();

}