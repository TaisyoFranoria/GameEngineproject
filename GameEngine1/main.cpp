#include"io.h"
#include"GameEngine.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetMainWindowText("GAmens");
	SetGraphMode(640, 480, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	Engine* engine = new Engine();
	if (engine == nullptr) DebugBreak();

	while (ProcessMessage() != -1 && !ScreenFlip() && !ClearDrawScreen()) {
		engine->update();
		engine->view();
		if (engine->Engine_Alive == false)break;
	}

	delete engine;
	engine = nullptr;
	if (engine != nullptr)DebugBreak();


	InitSoundMem();
	InitGraph();
	DxLib_End();

	return 0;
}

//‰´‚Í‘¾ŒÛ‚Ì’Bl