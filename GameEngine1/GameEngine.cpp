#include"GameEngine.h"

Engine::Engine() {
	
	Init();
}

Engine::~Engine(){
	Final();
}

void Engine::Init() {
	sc = new scene();
}

void Engine::Final() {
	delete sc;
}

void Engine::update() {
	sc->update();
	sc->update();
	sc->update();
}

void Engine::view() {
	sc->draw();
}