#pragma once
#include"io.h"


class Map {
public:
	int hantei[15][20];
	int mapgraph;

	Map(int num);
	~Map();
	void View();
	void All();
};