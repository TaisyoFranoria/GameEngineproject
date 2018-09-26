#include"Map.h"


//csv�t�@�C���ɋL�q����Ă��锻��A�摜�t�@�C������̃}�b�v�̌����ځA���̓�̗v�f���`����Map�N���X�i�錾�̓w�b��Map.h�ɂĂ��łɍs���Ă���j

Map::Map(int num) {


	//�ȉ�fclose()���Ăяo�����܂�csv����f�[�^��ǂݍ��݁A������`���鏈���i�����͕ǂȂ̂��A�n�ʂȂ̂��A�o���Ȃ̂��j
	FILE* fp;
	switch (num)
	{
	case 100:
		fp = fopen("map_col/testart.csv", "r");
		mapgraph = LoadGraph("img/Start_p.png");
		break;
	case 99:
		fp = fopen("map_col/test2.csv", "r");
		mapgraph = LoadGraph("img/End_p.png");
		break;
	case 1:
		fp = fopen("map_col/test1.csv", "r");
		mapgraph = LoadGraph("img/1.png");
		break;
	default:
		fp = fopen("map_col/test2.csv", "r");
		mapgraph = LoadGraph("img/sroom.png");
		break;
	}

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
			else {
				//int num = atoi(buf);
				hantei[gyou][retu] = atoi(buf);
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

//���O�̒ʂ茩�����ɂ������֐��@
void Map::View() {
	DrawGraph(0, 0, mapgraph, TRUE);
}

//Map�I�u�W�F�N�g���I�u�W�F�N�g�Ƃ��ċ@�\�����邽�߂̏���
void Map::All() {
	View();
}