#pragma once
#include"io.h"
#include"TEXTtoSTR.h"
#include<vector>


#define INPUT1 KEY_INPUT_1
#define INPUT2 KEY_INPUT_2
#define INPUT3 KEY_INPUT_3
#define INPUT4 KEY_INPUT_4

typedef struct Games {
	const char* name;
	const char* exePATH;
	const char* directPATH;
}Games;


class Qwindow {
public:
	std::vector<int> gra;
	int cmt;
	int x;
	int y;
	int State;
	bool A;
	int Qs;
	int s;
	int Current_Num;
	int Quest_Now;
	int lunch;
	Games ac2d;

	TEXTtoSTR* plan_txt;
	std::vector<TEXTtoSTR*> text;
	std::vector<const char*> Q1;
	

	Qwindow();
	~Qwindow();

	void Qwindow_init();
	void fmove();
	void emove();
	void Q(int i);
	void update();
	void view();

	void all();

	void Writing(const char* filename, std::vector<int> &items1);
	void WritingText(const char*filename, std::vector<const char*> &Text);
	void Lunch(Games);
};