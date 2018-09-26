#pragma once
#include"DxLib.h"


namespace SHIK {


	inline int GraShikimi(int num) {
		int gra;
		switch (num)
		{
		case 0:
			gra = LoadGraph("img/shikimi/2_1.png");
			break;
		case 1:
			gra = LoadGraph("img/shikimi/2_2.png");
			break;

		case 2:
			gra = LoadGraph("img/shikimi/2_3.png");
			break;
		case 3:
			gra = LoadGraph("img/shikimi/1_1.png");
			break;
		case 4:
			gra = LoadGraph("img/shikimi/1_2.png");
			break;
		case 5:
			gra = LoadGraph("img/shikimi/1_3.png");
			break;
		case 6:
			gra = LoadGraph("img/shikimi/4_1.png");
			break;
		case 7:
			gra = LoadGraph("img/shikimi/4_2.png");
			break;
		case 8:
			gra = LoadGraph("img/shikimi/4_3.png");
			break;
		case 9:
			gra = LoadGraph("img/shikimi/3_1.png");
			break;
		case 10:
			gra = LoadGraph("img/shikimi/3_2.png");
			break;
		case 11:
			gra = LoadGraph("img/shikimi/3_3.png");
			break;
		case 12:
			gra = LoadGraph("img/shikimi/6_1.png");
			break;
		case 13:
			gra = LoadGraph("img/shikimi/6_2.png");
			break;
		case 14:
			gra = LoadGraph("img/shikimi/6_3.png");
			break;
		case 15:
			gra = LoadGraph("img/shikimi/7_1.png");
			break;
		case 16:
			gra = LoadGraph("img/shikimi/7_2.png");
			break;
		case 17:
			gra = LoadGraph("img/shikimi/7_3.png");
			break;
		case 18:
			gra = LoadGraph("img/shikimi/8_1.png");
			break;
		case 19:
			gra = LoadGraph("img/shikimi/8_2.png");
			break;
		case 20:
			gra = LoadGraph("img/shikimi/8_3.png");
			break;
		case 21:
			gra = LoadGraph("img/shikimi/9_1.png");
			break;
		case 22:
			gra = LoadGraph("img/shikimi/9_2.png");
			break;
		case 23:
			gra = LoadGraph("img/shikimi/9_3.png");
			break;
		case 24:
			gra = LoadGraph("img/shikimi/stan2.png");
			break;
		case 25:
			gra = LoadGraph("img/shikimi/stan1.png");
			break;
		case 26:
			gra = LoadGraph("img/shikimi/stan4.png");
			break;
		case 27:
			gra = LoadGraph("img/shikimi/stan3.png");
			break;
		case 28:
			gra = LoadGraph("img/shikimi/stan6.png");
			break;
		case 29:
			gra = LoadGraph("img/shikimi/stan7.png");
			break;
		case 30:
			gra = LoadGraph("img/shikimi/stan8.png");
			break;
		case 31:
			gra = LoadGraph("img/shikimi/stan9.png");
			break;
		case 32:
			gra = LoadGraph("img/shikimi/s3_2_1.png");
			break;
		case 33:
			gra = LoadGraph("img/shikimi/s3_2_2.png");
			break;
		case 34:
			gra = LoadGraph("img/shikimi/s3_2_3.png");
			break;
		case 35:
			gra = LoadGraph("img/shikimi/s3_1_1.png");
			break;
		case 36:
			gra = LoadGraph("img/shikimi/s3_1_2.png");
			break;
		case 37:
			gra = LoadGraph("img/shikimi/s3_1_3.png");
			break;
		case 38:
			gra = LoadGraph("img/shikimi/s3_4_1.png");
			break;
		case 39:
			gra = LoadGraph("img/shikimi/s3_4_2.png");
			break;
		case 40:
			gra = LoadGraph("img/shikimi/s3_4_3.png");
			break;
		case 41:
			gra = LoadGraph("img/shikimi/s3_3_1.png");
			break;
		case 42:
			gra = LoadGraph("img/shikimi/s3_3_2.png");
			break;
		case 43:
			gra = LoadGraph("img/shikimi/s3_3_3.png");
			break;
		case 44:
			gra = LoadGraph("img/shikimi/s3_6_1.png");
			break;
		case 45:
			gra = LoadGraph("img/shikimi/s3_6_2.png");
			break;
		case 46:
			gra = LoadGraph("img/shikimi/s3_6_3.png");
			break;
		case 47:
			gra = LoadGraph("img/shikimi/s3_7_1.png");
			break;
		case 48:
			gra = LoadGraph("img/shikimi/s3_7_2.png");
			break;
		case 49:
			gra = LoadGraph("img/shikimi/s3_7_3.png");
			break;
		case 50:
			gra = LoadGraph("img/shikimi/s3_8_1.png");
			break;
		case 51:
			gra = LoadGraph("img/shikimi/s3_8_2.png");
			break;
		case 52:
			gra = LoadGraph("img/shikimi/s3_8_3.png");
			break;
		case 53:
			gra = LoadGraph("img/shikimi/s3_9_1.png");
			break;
		case 54:
			gra = LoadGraph("img/shikimi/s3_9_2.png");
			break;
		case 55:
			gra = LoadGraph("img/shikimi/s3_9_3.png");
			break;
		default:
			gra = 1;
			break;
		}
		return gra;
	}

	inline int GraXor(int num) {
		int gra;
		switch (num)
		{
		case 0:
			gra = LoadGraph("img/xor/2_1.png");
			break;
		case 1:
			gra = LoadGraph("img/xor/2_2.png");
			break;

		case 2:
			gra = LoadGraph("img/xor/2_3.png");
			break;
		case 3:
			gra = LoadGraph("img/xor/1_1.png");
			break;
		case 4:
			gra = LoadGraph("img/xor/1_2.png");
			break;
		case 5:
			gra = LoadGraph("img/xor/1_3.png");
			break;
		case 6:
			gra = LoadGraph("img/xor/4_1.png");
			break;
		case 7:
			gra = LoadGraph("img/xor/4_2.png");
			break;
		case 8:
			gra = LoadGraph("img/xor/4_3.png");
			break;
		case 9:
			gra = LoadGraph("img/xor/3_1.png");
			break;
		case 10:
			gra = LoadGraph("img/xor/3_2.png");
			break;
		case 11:
			gra = LoadGraph("img/xor/3_3.png");
			break;
		case 12:
			gra = LoadGraph("img/xor/6_1.png");
			break;
		case 13:
			gra = LoadGraph("img/xor/6_2.png");
			break;
		case 14:
			gra = LoadGraph("img/xor/6_3.png");
			break;
		case 15:
			gra = LoadGraph("img/xor/7_1.png");
			break;
		case 16:
			gra = LoadGraph("img/xor/7_2.png");
			break;
		case 17:
			gra = LoadGraph("img/xor/7_3.png");
			break;
		case 18:
			gra = LoadGraph("img/xor/8_1.png");
			break;
		case 19:
			gra = LoadGraph("img/xor/8_2.png");
			break;
		case 20:
			gra = LoadGraph("img/xor/8_3.png");
			break;
		case 21:
			gra = LoadGraph("img/xor/9_1.png");
			break;
		case 22:
			gra = LoadGraph("img/xor/9_2.png");
			break;
		case 23:
			gra = LoadGraph("img/xor/9_3.png");
			break;
		default:
			gra = 0;
			break;
		}
		return gra;
	}
}
