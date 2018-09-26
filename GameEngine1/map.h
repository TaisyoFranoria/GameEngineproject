#pragma once
#include"io.h"


class Map {
public:
	int hantei[15][20];
	int mapgraph;

	Map(int num);
	void View();
	void All();
};