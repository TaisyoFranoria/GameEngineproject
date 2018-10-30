#include"io.h"
#include"TOOL.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	SetMainWindowText("ゼミプロジェクトメンバー用_グラフィックメーカー");
	SetGraphMode(640, 480, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	Tool* map_tool = new Tool();


	while (ProcessMessage() != -1 && !ScreenFlip() && !ClearDrawScreen()) {
		map_tool->all();
		if (!map_tool->alive)break;
	}

	delete map_tool;

	
	DxLib_End();	
	return 0;
}