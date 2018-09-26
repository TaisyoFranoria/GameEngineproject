#include"Map.h"


//csvファイルに記述されている判定、画像ファイルからのマップの見た目、この二つの要素を定義したMapクラス（宣言はヘッだMap.hにてすでに行っている）

Map::Map(int num) {


	//以下fclose()が呼び出されるまでcsvからデータを読み込み、判定を定義する処理（そこは壁なのか、地面なのか、出口なのか）
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

//名前の通り見かけにかかわる関数　
void Map::View() {
	DrawGraph(0, 0, mapgraph, TRUE);
}

//Mapオブジェクトをオブジェクトとして機能させるための処理
void Map::All() {
	View();
}