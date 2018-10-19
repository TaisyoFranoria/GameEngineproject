#include"Qwindow.h"



Qwindow::Qwindow() {
	x = 1100;
	y = 100;

	gra.push_back(LoadGraph("img/1017/Qwindow1.png"));
	gra.push_back(LoadGraph("img/1017/Qwindow2.png"));
	gra.push_back(LoadGraph("img/1017/Qwindow3.png"));
	gra.push_back(LoadGraph("img/1017/Qwindow4.png"));

	cmt = LoadGraph("img/シキミのコメント.png");
	State = 0;
	A = false;

	plan_txt = new TEXTtoSTR("plan.txt");

	text.push_back(new TEXTtoSTR("test.txt"));
	text.push_back(new TEXTtoSTR("text.txt"));
	text.push_back(new TEXTtoSTR("test.txt"));
	text.push_back(new TEXTtoSTR("text.txt"));

	//テスト
	//ここにいろいろ
	
	//WritingText("Q/Questions.csv",text,Q1,Q2,Q3,Q4, sizeof items / sizeof items[0]);

	ac2d = {
		"2DAnimationChecker",
		"C:\\Users\\taisy\\Documents\\GameEngineproject\\presen1017\\presen1017\\２Dアニメーションチェッカー　ver_puroto\\AnimationCheck.exe",
		"C:\\Users\\taisy\\Documents\\GameEngineproject\\presen1017\\presen1017\\２Dアニメーションチェッカー　ver_puroto"
	};
		
	

	//if (Qs != Q1i1.size()) DebugBreak();
	s = 0;
	Current_Num = 0;
	Quest_Now = true;
	lunch = 0;
	
}

Qwindow::~Qwindow() {

	for (int i = 0, n = (signed)gra.size(); i < n; i++) {
		DeleteGraph(gra[i]);
	}

	for (int i = 0, n = (signed)text.size(); i < n; i++) {
		delete text[i];
	}
}

//名前が非常に紛らわしく後悔しているが、これは質問の初期化ではない。ウインドウの位置を始点にセットするものである。
void Qwindow::Qwindow_init() {
	x = 1200;
	y = 100;
	State = 1;
	A = false;
	Current_Num++;
	if (Current_Num >= (signed)text.size())Current_Num = 0;
}

void Qwindow::fmove() {

	x -= 60;
}

void Qwindow::emove() {

	x -= 60;

}

void Qwindow::Q(int i) {

	if (Qs >= i) {
		s = i;
	}

	
	if(CheckHitKey(KEY_INPUT_1)) A = true;

	
}
void Qwindow::update() {

	if (x >= 330) fmove();
	else {
		if (A == false) {
			Q(Current_Num);
		}
		else if (A == true) {
			emove();
		}
	}
	
	if (Current_Num == 1)lunch++;

	if (x < -500)Qwindow_init();
	if (Current_Num >= Qs)Quest_Now = false;
}

void Qwindow::view() {
	DrawExtendGraph(x, y, x + 700, y + 524, gra[stoi(plan_txt->texts[Current_Num])], TRUE);
	for (int i = 0, n = (signed)text[Current_Num]->texts.size(),kai = 0; i < n; i++) {
		DrawString(x+50,y+160+kai, text[Current_Num]->texts[i].c_str(), 0x3DFFFF);
		kai += 32;
	}
	//行数確認用
	//DrawString(x + 50, y + 500, std::to_string((signed)text[Current_Num]->texts.size()).c_str(), 0xFFFFFF);
	if (Current_Num == 3)DrawGraph(850,0,cmt,TRUE);
}


void Qwindow::all() {

	view();


	if (x >= 330) fmove();
	else {
		if (A == false) {
			Q(Current_Num);
		}
		else if(A == true){
			emove();
		}
	}

	if (x < -500)Qwindow_init();
	if (Current_Num >= Qs)Quest_Now++;
}

void Qwindow::Writing(const char* filename, std::vector<int> &items1){

	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL)DebugBreak();
	int c;
	int retu = 0;
	int gyou = 0;
	char buf[10];
	memset(buf, 0, sizeof(buf));
	bool eofFlag = false;
	for (int i = 0; i < 1000; i++) {
		while (1) {
			c = fgetc(fp);
			if (c == EOF) {
				eofFlag = true;
				break;
			}
			if (c != ',' && c != '\n') {
				strcat(buf, (const char*)&c);

			}
			else if (retu == 0) {
				items1.push_back(atoi(buf));
				memset(buf, 0, sizeof(buf));
				break;
			}
			else {
				memset(buf, 0, sizeof(buf));
				break;
			}
		}

		if (eofFlag)break;
		if (c == ',')retu++;
		if (c == '\n') {
			gyou++;
			retu = 0;
		}
	}
	fclose(fp);

	
}

void Qwindow::WritingText(const char*filename, std::vector<const char*> &Text){

	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL)DebugBreak();
	int c;
	int retu = 0;
	int gyou = 0;
	char buf[64];
	const char* c_buf;
	memset(buf, 0, sizeof(buf));
	bool eofFlag = false;
	for (int i = 0; i < 1000; i++) {
		while (1) {
			c = fgetc(fp);
			if (c == EOF) {
				eofFlag = true;
				break;
			}
			if (c != ',' && c != '\n') {
				strcat(buf, (const char*)&c);
				c_buf = (const char*)buf;
			}
			else if (retu == 0) {
				Text.push_back(buf);
				memset(buf, 0, sizeof(buf));
				break;
			}
			else {
				memset(buf, 0, sizeof(buf));
				break;
			}
		}

		if (eofFlag)break;
		if (c == ',')retu++;
		if (c == '\n') {
			gyou++;
			retu = 0;
		}
	}
	fclose(fp);

}

void Qwindow::Lunch(Games game) {

	PROCESS_INFORMATION p;
	STARTUPINFO s;
	ZeroMemory(&s, sizeof(s));
	s.cb = sizeof(s);

	int ret = CreateProcess(
		NULL,
		//(LPSTR)"C:\\Windows\\System32\\notepad.exe",
		(LPSTR)game.exePATH,
		NULL,
		NULL,
		FALSE,
		NORMAL_PRIORITY_CLASS,
		NULL,
		(LPSTR)game.directPATH,
		&s,
		&p
	);
	if (!ret) {
		DebugBreak();
	}
	else {

		CloseHandle(p.hThread);

		WaitForSingleObject(p.hProcess, INFINITE);
		CloseHandle(p.hProcess);

	}
}