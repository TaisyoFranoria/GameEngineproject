#pragma once
#include "scene.h"
class Engine {
public:
	scene* sc;

	int state;
	int MAX_state;
	bool Engine_Alive;

	Engine();
	~Engine();
	void Init();
	void Final();
	void update();
	void view();
};
