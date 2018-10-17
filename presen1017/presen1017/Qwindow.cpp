#include"Qwindow.h"


Qwindow::Qwindow() {
	x = 1100;
	y = 100;
	gra.push_back(LoadGraph("img/1017/Qwindow1.png"));
	gra.push_back(LoadGraph("img/1017/Qwindow2.png"));
	gra.push_back(LoadGraph("img/1017/Qwindow3.png"));
	gra.push_back(LoadGraph("img/1017/Qwindow4.png"));
	cmt = LoadGraph("img/�V�L�~�̃R�����g.png");
	State = 0;
	A = false;

	//�e�X�g
	text.push_back("�E�ΏێҁF�O���t�B�b�N\n\n�E���F������f�ށi�A�j���[�V�����j��\n�m�F���������B\n�i�Q�[���Ƃ��ē������܂łǂ�ȃA�j���[�V����\n������̂��킩��Ȃ��j\n");
	text.push_back("�u�QD�A�j���[�V�����`�F�b�J�[�v\n\n�@�\�F�A�j���[�V�����f�ނ�\n�ǂݍ��݁A�������m�F����\n�Đ��E��~�E�Đ����x�̕ύX\n���ł���\n\n�Q�[������ɂ���������F\n�O���t�B�b�J�[�����g���쐬�����A�j���[�V������\n�����Ŋm�F����B\n");
	text.push_back("�e�X�g���@�F\n���ۂɃA�j���[�V����\n���܂މ摜��ǂݍ����\n�g���Ă݂��B\n\n\n\n\n              ����̐���ɂ��𗧂�����");
	text.push_back("�Q�[���G���W���ɑ������H�F\n�Q�[������ɖ𗧂��Ă�̂�\n�Q�[���G���W���ƌ�����B\n\n�Ӑ}�����ʂ��\n�������ʂ��������H�F�ʂ����Ă���B\n\n�g���₷���FGUI�ɂ�����������̂Ŏg���₷���Ƃ͎v���B\n\n���P�_�F�p�r���i�����̂Œǉ�����ׂ��@�\�͌�����B\n���Ƃ͎g���₷���悤�ɍH�v���邾��\n");
	
	//WritingText("Q/Questions.csv",text,Q1,Q2,Q3,Q4, sizeof items / sizeof items[0]);

	ac2d = {
		"2DAnimationChecker",
		"C:\\Users\\taisy\\Documents\\GameEngineproject\\presen1017\\presen1017\\�QD�A�j���[�V�����`�F�b�J�[�@ver_puroto\\AnimationCheck.exe",
		"C:\\Users\\taisy\\Documents\\GameEngineproject\\presen1017\\presen1017\\�QD�A�j���[�V�����`�F�b�J�[�@ver_puroto"
	};
		
	

	//if (Qs != Q1i1.size()) DebugBreak();
	s = 0;
	Current_Num = 0;
	Quest_Now = true;
	lunch = 0;
	
}

Qwindow::~Qwindow() {
	for (int i = 0; i < gra.size(); i++) {
		DeleteGraph(gra[i]);
	}
}

//���O�����ɕ���킵��������Ă��邪�A����͎���̏������ł͂Ȃ��B�E�C���h�E�̈ʒu���n�_�ɃZ�b�g������̂ł���B
void Qwindow::Qwindow_init() {
	x = 1200;
	y = 100;
	State = 1;
	A = false;
	Current_Num++;
	if (Current_Num >= text.size())Current_Num = 0;
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
	DrawExtendGraph(x, y, x + 700, y + 524, gra[Current_Num], TRUE);
	DrawFormatString(x+50,y+160,GetColor(255,255,255),"%s",text[Current_Num]);
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