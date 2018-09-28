#include"GameEngine.h"

Engine::Engine() {
	
	Init();
}

Engine::~Engine(){
	Final();
}

void Engine::Init() {
	state = 0;
	MAX_state = state;
	Engine_Alive = true;
	sc = new scene();
}

void Engine::Final() {
	delete sc;
	sc = nullptr;
	if (sc != nullptr) {
		DebugBreak();
	}
}

void Engine::update() {
	sc->update();
	if (CheckHitKey(KEY_INPUT_ESCAPE))Engine_Alive = false;
}

void Engine::view() {
	sc->draw();
}