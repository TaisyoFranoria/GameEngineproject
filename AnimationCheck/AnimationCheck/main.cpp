#include"io.h"

int WINAPI WinMain() {

	AnimationEngine2D* ae2 = new AnimationEngine2D();

	while(){

		ae2->update();
		ae2->draw();
		
	}


	delete ae2;

	Dxlib_End();

	return 0;
}
