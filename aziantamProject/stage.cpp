// 月夜
//stage.cpp
//2020.05.20

////////////////////////////////ｽﾃｰｼﾞずれてる
#include <DxLib.h>
#include "main.h"
#include "stage.h"

// 変数
int chipImage[81];
int map[MAP_Y][MAP_X];
int stageOffset;

// ﾏｯﾌﾟの配列
// ﾀﾞﾝｼﾞｮﾝ
// 村のﾏｯﾌﾟ
int stage[MAP_START_Y][MAP_START_X] = {
{ 7, 8, 7, 8, 7, 8, 7, 8,  7, 8, 7, 8, 7, 8, 7, 8,  7, 8, 7, 8, 7, 8, 7, 8,  7, 8, 7, 8, 7, 8, 7, 8,  7, 8, 7, 8, 7, 8, 7, 8},
{16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17},
{ 7, 8,75,75,60,61,26,60, 61,26,60,61,75,75, 6, 6,  6, 6, 6,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75, 7, 8},
{16,17,75,75,69,70,26,69, 70,26,69,70,75,75, 6, 6,  6, 6, 6,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,16,17},
{ 7, 8,75,75, 9,10,10,10, 10,10,10,10,10,10, 6, 6,  6, 6, 6,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75, 7, 8},

{16,17,75,75,60,61,26,60, 61,26,60,61,75,10, 6, 6,  6, 6, 6,75,75,75,75,75, 75,75,75, 6, 6, 6,75,75, 75,75,75,75,75,75,16,17},
{ 7, 8,75,75,69,70,26,69, 70,26,69,70,75,10, 6, 6,  6, 6, 6,75,75,75,75,75, 75,75,75, 6, 6, 6,75,75, 75,75,75,75,75,75, 7, 8},
{16,17,75,75,75,75,75,75, 75,75,75,75,75,10,10,10, 10,75,25,25,25,25,25,75, 75,75,75, 6, 6, 6,75,75, 75,75,75,75,75,75,16,17},
{ 7, 8,75,75,75,75,75,75, 75,75, 6, 6, 6,75,75,75, 10,75,26,60,61,62,26,75, 75,75,75,75,75,75,60,61, 75,75,75,75,75,75, 7, 8},
{16,17,75,75,75,75,75,75, 75,75, 6, 6, 6,75,75,75, 10,75,26,69,70,62,26,75, 75,75,75,75,75,75,69,70, 67,75,75,75,75,75,16,17},

{ 7, 8,75,75,75,75,75,75, 75,75, 6, 6, 6,75,75,75, 10,10,10,10,10,10,10,10, 10,10,10,10,10,75,75, 1, 75,75,75,75,75,75, 7, 8},
{16,17,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 10,75,75,75,75,75,75,75, 75,75,62,62,10,10,10,10, 75,75,75,75,75,75,16,17},
{ 7, 8,75,75,75,75,75,75, 75,75,75,75,75,10,10,10, 10,75,75,75,75,75,75,75, 75,75,75,75,10,75,75,75, 75,75,75,75,75,75, 7, 8},
{16,17,75,75,75,60,61,75, 75,75,75,75,75,10,75,15, 15,15,15,15,15,15,15,15, 75,75,75,75,10,75,60,61, 75,75,75,75,75,75,16,17},
{ 7, 8,75,75,75,69,70,10, 10,10,10,10,10,10,75,15, 15,15,15,15,15,15,15,15, 75,75,75,75,10,75,69,70, 67,75,75,75,75,75, 7, 8},

{16,17,75,75,75,75,75,10, 57,57,57,57,68,10,75,15, 15,15,15,15,15,15,15,15, 75,75,75,24,10,75,75, 1, 75,75,75,75,75,75,16,17},
{ 7, 8,75,75,75,75,77,10, 57,57,57,57,68,10,75,15, 15,15, 3, 4, 5,15,15,15, 75,75,75,24,10,10,10,10, 75,75, 6, 6, 6,75, 7, 8},
{16,17,75,10,10,10,10,10, 75,75,10,10,10,10,75,15, 15,15,12,13,14,15,15,15, 75,75,75,75,10,75,75,75, 75,75, 6, 6, 6,75,16,17},
{ 7, 8,75,10,75,77,75,75, 75,75,75,75,75,75,75,15, 15,15,21,22,23,15,15,15, 75,75,75,75,10,75,60,61, 75,75,75,75,75,75, 7, 8},
{16,17,75,10,75,75,75,75, 75,75,75,75,75,75,75,15, 15,15,75,10,75,15,15,15, 75,75,75,75,10,75,69,70, 67,75,75,75,75,75,16,17},

{ 7, 8,75,10,75,75, 6, 6,  6,75,75,75,75,75,75,75, 75,75,75,10,75,75,75,75, 75,75,75,75,10,75,75, 1, 75,75,75,75,75,75, 7, 8},
{16,17,75,10,75,75, 6, 6,  6,26,25,25,25,25,25,26,  9,10,10,10,10,10,10,10, 10,10,10,10,10,10,10,10, 75,75,75,75,75,75,16,17},
{ 7, 8,75,10,75,75, 6, 6,  6,26,68,60,61,62,77,26, 75,75,75,75,75,75,75,10, 24,24,75,75,10,75,75,75, 75,75,75,75,75,75, 7, 8},
{16,17,75,10,75,75,75,75, 75,26,68,69,70,77,77,26, 75,75,75,75,75,75,75,10, 75,75,75,75,10,75,60,61, 75,75,75,75,75,75,16,17},
{ 7, 8,75,10,75,75,75,75, 75,26,75,78,79,75,77,26, 75,75,75,75,75,75,75,10, 75,75,75,75,10,75,69,70, 67,75,75,75,75,75, 7, 8},

{16,17,75,10,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,19, 75,75,75,75,10,75,75, 1, 75,75,75,75,75,75,16,17},
{ 7, 8,75,10,10,10,10,10, 10,10,10,10,10,10,10,10, 11,75,75,75,75,60,61,75, 75,75,75,75,10,10,10,10, 75,75,75,75,75,75, 7, 8},
{16,17,75,10,77,77,75,75, 75,75,75,30,31,31,31,31, 31,32,75,75,75,69,70,75, 75,75,75,75,10,75,75,75, 75,75, 6, 6, 6,75,16,17},
{ 7, 8,75,10,75,75,75,75, 75,75,75,39,40,40,40,40, 40,41,75,75,75,75,75,10, 10,10,10,10,10,75,60,61, 75,75, 6, 6, 6,75, 7, 8},
{16,17,75,10,75,75,75,75, 75,75,75,48,49,49,49,49, 49,50,75,75,75,75,75,75, 75,75,75,75,10,75,69,70, 67,75, 6, 6, 6,75,16,17},

{ 7, 8,75,10,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,60, 61,75,75,75,10,75,75, 1, 75,75,75,75,75,75, 7, 8},
{16,17,75,10,75,75, 6, 6,  6, 6,75,75,75,75,75,75, 75,75,75,75,75,75,75,69, 70,18,10,10,10,10,10,10, 75,75,75,75,75,75,16,17},
{ 7, 8,75,10,75,75, 6, 6,  6, 6,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75, 7, 8},
{16,17,75,10,75,75, 6, 6,  6, 6,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,16,17},
{ 7, 8,75,10,11,75, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75, 7, 8},

{16,17,75, 6, 6, 6, 6,75, 66,75,75, 6, 6, 6, 6, 6,  6, 6, 6, 6,75,75,75,75, 75,75,75,75,75, 6, 6, 6, 75,75,75,75,75,75,16,17},
{ 7, 8,75, 6, 6, 6, 6,75, 75,75,75, 6, 6, 6, 6, 6,  6, 6, 6, 6,75,75,75,75, 75,75,75,75,75, 6, 6, 6, 75,75,75,75,75,75, 7, 8},
{16,17,75, 6, 6, 6, 6,75, 75,75,75, 6, 6, 6, 6, 6,  6, 6, 6, 6,75,75,75,75, 75,75,75,75,75, 6, 6, 6, 75,75,75,75,75,75,16,17},
{ 7, 8,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75, 7, 8},
{16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17},

};



int stageMob[MAP_M_Y][MAP_M_X] =
{
{  6, 7, 7, 8,58, 58,58,58, 0, 0, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,25,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15, 7,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },

{ 15,16,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,25,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,25, 7,26,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15, 7,16, 8,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },

{ 15,16,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,16,26,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,25,16, 8,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15, 7,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,25,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },

{ 15,16, 7,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,25,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16, 7,26,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,16, 8,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },

{ 15,16,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,25,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16, 7,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,25,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15, 7,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8 ,8, 58,58,58,58,58 },

{ 15,16,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,16,17,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58,58,58, 58,58,58, 8, 8, 58,58,58,58,58 },
{ 15,16,16,17, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7,16, 8, 58,58,58,58,58 },
{ 15,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,17, 58,58,58,58,58 },
{ 24,25,25,25,25, 25,25,25,25,25, 25,25,25,25,25, 25,25,25,25,25, 25,25,25,25,26, 58,58,58,58,58 },
};



// 河童のﾏｯﾌﾟ
/*int stageA[MAPA_Y][MAPA_X] = {
{ 6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6},
{30,31,31,31,31,31,31,31, 31,31,31,31,31,31,31,31, 31,31,31,31,31,31,31,31, 31,31,31,31,31,31,31,31, 31,31,31,31,31,31,31,32},
{39,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41},
{39,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41},
{39,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 49,49,49,49,49,49,49,50},

{39,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,24,24,24,24,24,24,24},
{48,49,49,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,75,75,75,75,75,75,75},
{24,24,39,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,75,75,75,75,75,75,75},
{75,24,39,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,75,75,75,75,75,75,75},
{75,24,48,49,49,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,75,75,75,75,75,75,75},

{75,75,24,24,39,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75},
{75,75,75,24,39,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75},
{75,75,75,24,48,49,49,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75},
{75,75,75,75,24,24,39,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75},
{75,75,75,75,75,24,39,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,75,75,75,66,75,75,75, 75,75,75,75,75,75,75,75},

{75,75,75,75,75,24,48,49, 49,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6},
{75,75,75,75,75,75,24,24, 39,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,41, 24,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6},
{75,75,75,75,75,75,75,24, 48,49,49,49,49,49,49,49, 49,49,49,49,49,49,49,50, 24,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6},
{75,75,75,75,75,75,75,75, 24,24,24,24,24,24,24,24, 24,24,24,24,24,24,24,24, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6},
{75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6},

{75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6},
{75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6},
{75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6},
{75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75},
{75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75},

{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75},
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75},
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75, 0, 1, 1,  1, 1, 1, 1, 2,75,75,75, 75,75,75,75,75,75,75,75},
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75, 9,10,10, 10,10,10,10,11,75,75,75, 75,75,75,75,75,75,75,75},
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75, 9,10,10, 10,10,10,10,11,75,75,75, 75,75,75,75,75,75,75,75},

{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75, 9,10,10, 10,10,10,10,11,75,75,75, 75,75,75,75,75,75,75,75},
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75, 9,10,10, 10,10,10,10,11,75,75,75, 75,75,75,75,75,75,75,75},
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75, 9,10,10, 10,10,10,10,11,75,75,75, 75,75,75,75,75,75,75,75},
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75, 9,10,10, 10,10,10,10,11,75,75,75, 75,75,75,75,75,75,75,75},
{75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75, 9,10,10, 10,10,10,10,11,75,75,75, 75,75,75,75,75,75,75,75},

{75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75, 9,10,10, 10,10,10,10,11,75,75,75, 75,75,75,75,75,75,75,75},
{75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75, 9,10,10, 10,10,10,10,11,75,75,75, 75,75,75,75,75,75,75,75},
{75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75, 9,10,10, 10,10,10,10,11,75,75,75, 75,75,75,75,75,75,75,75},
{75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,18,19,19, 19,19,19,19,20,75,75,75, 75,75,75,75,75,75,75,75},
{ 6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6},

};*/



XY mapPos;					// ﾏｯﾌﾟのｵﾌｾｯﾄ
XY mapSize;					// ﾏｯﾌﾟのｻｲｽﾞ
STAGE_ID stageID;			// ｽﾃｰｼﾞID

// ｽﾃｰｼﾞ情報の初期化
void StageSystemInit(void)
{
	// グラフィックの登録
	// ﾏｯﾌﾟﾁｯﾌﾟの画像を読み込む
	LoadDivGraph("char/map.png"
		, MAP_CHIP_X*MAP_CHIP_Y, MAP_CHIP_X, MAP_CHIP_Y
		, CHIP_SIZE_X, CHIP_SIZE_Y
		, chipImage);

	mapPos.x = 0;
	mapPos.y = 0;
	//mapSize = { 0,0 };
	stageOffset = 0;

	// ﾏｯﾌﾟ作成ﾃﾞｰﾀ
	stageID = STAGE_ID_START;
	//SetMapData(stageID);
	SetMapData(STAGE_ID_START);
}

// ｽﾃｰｼﾞ情報のｹﾞｰﾑ初期化
void StageGameInit(void)
{
	mapPos.x = 0;
	mapPos.y = 0;
	
	stageOffset = 0;

	// ﾏｯﾌﾟ作成ﾃﾞｰﾀ
	stageID = STAGE_ID_START;
	SetMapData(STAGE_ID_START);
}

// ﾋﾟｸｾﾙ座標系ｶﾗﾏｯﾌﾟ配列座標系ﾆ変換する
XY Pos2Index(XY pos)
{
	XY tmp;

	tmp.x = pos.x / CHIP_SIZE_X;		// posのx座標を変換;
	tmp.y = pos.y / CHIP_SIZE_Y;		// posのy座標を変換;

	//変換した値を返す
	return tmp;
}

//指定した座標が通過可能かを返す true:通過可能
bool IsPass(XY pos)
{
	XY indexPos;
	indexPos = Pos2Index(pos);

	switch (map[indexPos.y][indexPos.x])
	{

		// ﾓﾘ
	case 6:
	case 7:
	case 8:
	case 15:
	case 16:
	case 17:
	case 24:

	case 25:
	case 26:
		// ｲｴ
	case 60:
	case 61:
	case 69:
	case 70:
		// ｻｲﾀﾞﾝ
	case 71:
	case 80:
		// ｸｻ
	case 68:
		// ｲﾜ
	case 76:
	
		// ｶﾜ
	case 30:
	case 31:
	case 32:
	case 39:
	case 41:
	case 48:
	case 49:
	case 50:

	case 57:
	case 58:
	case 62:
	case 67:
	case 77:
		return false;
		break;

	default:
	
		break;

	}
	return true;
}

// 指定した座標が特別にｲﾍﾞﾝﾄを起こすかを確認する 戻り値:ｲﾍﾞﾝﾄID
EVENT_ID GetEvent(XY pos)
{
	XY indexPos;
	indexPos = Pos2Index(pos);

	switch (map[indexPos.y][indexPos.x])
	{
	/*case 66:
		if (stageID == STAGE_ID_START)
		{
			stageID = STAGE_ID_MOB;
			SetMapData(STAGE_ID_MOB);
		}
		else if (stageID == STAGE_ID_MOB)
		{
			stageID = STAGE_ID_ONI;
			SetMapData(STAGE_ID_ONI);
		}
		else if (stageID == STAGE_ID_ONI)
		{
			stageID = STAGE_ID_TENGU;
			SetMapData(STAGE_ID_TENGU);
		}
		else if (stageID == STAGE_ID_TENGU)
		{
			stageID = STAGE_ID_KAPPA;
			SetMapData(STAGE_ID_KAPPA);
		}
		/*else if (stageID == STAGE_ID_KAPPA)
		{
			stageID = STAGE_ID_BOSS;
			SetMapData(STAGE_ID_BOSS);
		}
		else if (stageID == STAGE_ID_BOSS)
		{
			StageGameDraw();
		}
		
		return EVENT_ID_KAIDAN;
		break;*/
		// 火
	case 27:
	case 28:
	case 29:
	case 36:
	case 37:
	case 38:
	case 45:
	case 46:
	case 47:
		// ｲﾍﾞﾝﾄの発生場所
		return EVENT_ID_HONO;
		break;

		// 水
	case 30:
	case 31:
	case 32:
	case 39:
	case 40:
	case 41:
	case 48:
	case 49:
	case 50:
		// ｲﾍﾞﾝﾄの発生場所
		return EVENT_ID_MIZU;
		break;
	
	default:
		break;
	}
	// ｲﾍﾞﾝﾄなし
	return EVENT_ID_NON;

}

// ｽﾃｰｼﾞﾃﾞｰﾀﾞをﾏｯﾌﾟ配列にｺﾋﾟｰする
void SetMapData(STAGE_ID stage_ID)
{
	// ﾏｯﾌﾟ配列の初期化
	for (int y = 0; y < MAP_Y; y++)
	{
		for (int x = 0; x < MAP_X; x++)
		{
			map[y][x] = 0;
		}
	}

	if (stage_ID == STAGE_ID_START)
	{
		mapSize.x = MAP_START_X;
		mapSize.y = MAP_START_Y;

		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				map[y][x] = stage[y][x];
			}
		}
	}
	else if (stage_ID == STAGE_ID_MOB)
	{
		mapSize.x = MAP_M_X;
		mapSize.y = MAP_M_Y;

		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				map[y][x] = stageMob[y][x];
			}
		}
	}
	/*else if (stage_ID == STAGE_ID_ONI)
	{
		mapSize.x = MAPI_X;
		mapSize.y = MAPI_Y;

		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				map[y][x] = stageI[y][x];
			}
		}
	}
	else if (stage_ID == STAGE_ID_TENGU)
	{
		mapSize.x = MAPY_X;
		mapSize.y = MAPY_Y;

		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				map[y][x] = stageY[y][x];
			}
		}
	}
	else if (stageID == STAGE_ID_KAPPA)
	{
		mapSize.x = MAPA_X;
		mapSize.y = MAPA_Y;

		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				map[y][x] = stageA[y][x];
			}
		}
	}
	else if (stageID == STAGE_ID_BOSS)
	{
		mapSize.x = MAPB_X;
		mapSize.y = MAPB_Y;

		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				map[y][x] = stageB[y][x];
			}
		}
	}*/
}

// ｹﾞｰﾑ画面の表示処理
void StageGameDraw(void)
{
	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			DrawGraph(x*CHIP_SIZE_X  + mapPos.x
				, y*CHIP_SIZE_Y  + mapPos.y
				, chipImage[map[y][x]], true);
		}
	}
}


//ｽｸﾛｰﾙ制限
void MapRange()
{
	//-----ﾏｯﾌﾟの制限	
	if (mapPos.x > 0) mapPos.x = 0;
	if (mapPos.x < -CHIP_SIZE_X * mapSize.x + SCREEN_SIZE_X) mapPos.x = -CHIP_SIZE_X * mapSize.x + SCREEN_SIZE_X;
	if (mapPos.y > 0) mapPos.y = 0;
	if (mapPos.y < -CHIP_SIZE_Y * mapSize.y + SCREEN_SIZE_Y) mapPos.y = -CHIP_SIZE_Y * mapSize.y + SCREEN_SIZE_Y;

}
