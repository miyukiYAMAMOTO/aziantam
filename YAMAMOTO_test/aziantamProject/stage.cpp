// 月夜
//stage.cpp
//2020.05.20

////////////////////////////////ｽﾃｰｼﾞずれてる
#include <DxLib.h>
#include "main.h"
#include "stage.h"

// 変数
int chipImage[81];
int OnichipImage[88];
int map[MAP_Y][MAP_X];
int stageOffset;

int backImage;

// ﾏｯﾌﾟの配列
// ﾀﾞﾝｼﾞｮﾝ
// 村のﾏｯﾌﾟ
int stage[MAP_START_Y][MAP_START_X] = {
{ 7, 8, 7, 8, 7, 8, 7, 8,  7, 8, 7, 8, 7, 8, 7, 8,  7, 8, 7, 8, 7, 8, 7, 8,  7, 8, 7, 8, 7, 8, 7, 8,  7, 8, 7, 8, 7, 8, 7, 8},
{16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17},
{ 7, 8,75,75,60,61,26,60, 61,26,60,61,75,75, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6,75,75,71,75,75,  6, 6, 6, 6,75,75, 7, 8},
{16,17,75,75,69,70,26,69, 70,26,69,70,75,75, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6,75,75,80,75,75,  6, 6, 6, 6,75,75,16,17},
{ 7, 8,78,79, 9,10,10,10, 10,10,10,10,10,10, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6,75,75,75,75,75,  6, 6, 6, 6,75,75, 7, 8},

{16,17,75,75,60,61,26,60, 61,26,60,61,75,10, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6,75,75,16,17},
{ 7, 8,75,75,69,70,26,69, 70,26,69,70,75,10, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6,75,75, 7, 8},
{16,17,75,75,75,75,75,75, 75,75,75,75,75,10,10,10, 10,75,25,25,25,25,25,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,16,17},
{ 7, 8,75,75, 6, 6, 6, 6,  6, 6, 6, 6, 6,75,75,75, 10,75,26,60,61,62,26,75, 75,75,75,75,75,75,60,61, 75,75,75,75,75,75, 7, 8},
{16,17,75,75, 6, 6, 6, 6,  6, 6, 6, 6, 6,75,75,75, 10,75,26,69,70,62,26,75, 75,75,75,75,75,75,69,70, 67,75,75,75,75,75,16,17},

{ 7, 8,75,75, 6, 6, 6, 6,  6, 6, 6, 6, 6,75,75,75, 10,10,10,10,10,10,10,10, 10,10,10,10,10,78,79, 1, 75,75,75,75,75,75, 7, 8},
{16,17,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 10,75,75,75,75,75,75,75, 75,75,62,75,10,10,10,10, 75,75,75,75,75,75,16,17},
{ 7, 8,75,75,75,75,75,75, 75,75,75,75,75,10,10,10, 10,75,75,75,75,75,75,75, 75,75,75,75,10,25,25,25, 75,75,75,75,75,75, 7, 8},
{16,17,75,75,62,60,61,75, 75,75,75,75,75,10,15,15, 15,15,15,15,15,15,15,15, 75,75,75,75,10,75,60,61, 75,75,75,75,75,75,16,17},
{ 7, 8,75,75,75,69,70,10, 10,10,10,10,10,10,15,15, 15,15,15,15,15,15,15,15, 75,75,75,75,10,75,69,70, 67,75, 6, 6, 6, 6, 7, 8},

{16,17,75,75,75,75,75,10, 57,57,57,57,68,10,15,15, 15,15,15,15,15,15,15,15, 76,75,75,24,10,78,79, 1, 75,75, 6, 6, 6, 6,16,17},
{ 7, 8,75,75,75,75,77,10, 57,57,57,57,68,10,15,15, 15,15, 3, 4, 5,15,15,15, 75,75,75,24,10,10,10,10, 75,75, 6, 6, 6, 6, 7, 8},
{16,17,75,10,10,10,10,10, 75,75,10,10,10,10,15,15, 15,15,12,13,14,15,15,15, 75,75,75,75,10,25,25,25, 75,75, 6, 6, 6, 6,16,17},
{ 7, 8,75,10,75,77,75,75, 75,75,75,75,75,75,75,15, 15,15,21,22,23,15,15,15, 75,75,75,75,10,75,60,61, 75,75, 6, 6, 6, 6, 7, 8},
{16,17,75,10,75,75,75,75, 75,75,75,75,75,75,75,15, 15,15,75,10,75,15,15,15, 75,75,75,75,10,75,69,70, 67,75,75,75,75,75,16,17},

{ 7, 8,75,10,75,75, 6, 6,  6,75,75,75,75,75,75,75, 75,75,75,10,75,75,75,75, 75,75,75,75,10,78,79, 1, 75,75,75,75,75,75, 7, 8},
{16,17,75,10,75,75, 6, 6,  6,26,25,25,25,25,25,26,  9,10,10,10,10,10,10,10, 10,10,10,10,10,10,10,10, 75,75,75,75,75,75,16,17},
{ 7, 8,75,10,75,75, 6, 6,  6,26,68,60,61,62,77,26, 75,75,75,75,75,75,75,10, 24,24,75,24,10,25,25,25, 75,75,75,75,75,75, 7, 8},
{16,17,75,10,75,75,75,75, 75,26,68,69,70,77,77,26, 75, 6, 6, 6, 6,75,75,10, 24,24,75,24,10,75,60,61, 75,75,75,75,75,75,16,17},
{ 7, 8,75,10,75,75,75,75, 75,26,75,78,79,75,77,26, 75, 6, 6, 6, 6,75,75,10, 75,75,75,75,10,75,69,70, 67,75,75,75,75,75, 7, 8},

{16,17,75,10,75,75,75,75, 75,75,75,75,75,75,75,75, 75, 6, 6, 6, 6,75,75,19, 57,57,24,75,10,78,79, 1, 75,75,75,75,75,75,16,17},
{ 7, 8,75,10,10,10,10,10, 10,10,10,10,10,10,10,10, 11,76,75,75,75,60,61,62, 57,57,24,75,10,10,10,10, 75,75,75,75,75,75, 7, 8},
{16,17,75,10,54,55,55,55, 56, 7, 8,30,31,31,31,31, 31,32,75,75,75,69,70,62, 57,57,75,75,10,25,25,25, 75,75, 6, 6, 6, 6,16,17},
{ 7, 8,75,10,63,64,64,64, 65,16,17,39,40,40,40,40, 40,41,75,75,75,75, 9,10, 10,10,10,10,10,75,60,61, 75,75, 6, 6, 6, 6, 7, 8},
{16,17,75,10,63,64,64,64, 65, 7, 8,39,40,40,40,40, 40,41,75,75,75,75,24,75, 75,75,75,75,10,75,69,70, 67,75, 6, 6, 6, 6,16,17},

{ 7, 8,75,10,63,64,64,64, 65,16,17,39,40,40,40,40, 40,41,75,75,75,75,24,60, 61,75,75,24,10,78,79, 1, 75,75,75,75,75,75, 7, 8},
{16,17,75,10,72,73,73,73, 74, 7, 8,48,49,49,49,49, 49,50,75,75,75,75,75,69, 70,18,10,10,10,10,10,10, 75,76,24,24,24, 6,16,17},
{ 7, 8,75,10,68,68,68,68, 68,16,17,24,24,24,24,24, 24,24,75,75,75,75,75,75, 75,75,75,75,75,24,75,75, 75,75,30,31,32, 6, 7, 8},
{16,17,75,10,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,39,40,41, 6,16,17},
{ 7, 8,75,10,11, 6, 6, 6,  6, 6, 6, 6, 6,75,75,66, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,39,40,41, 6, 7, 8},

{16,17, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,48,49,50, 6,16,17},
{ 7, 8, 6, 6, 6, 6, 6,75, 75,71,75,75, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,24,24,24, 6, 7, 8},
{16,17, 6, 6, 6, 6, 6,75, 75,80,75,75, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,16,17},
{ 7, 8,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75, 7, 8},
{16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17, 16,17,16,17,16,17,16,17},

};

//MOB
int stageMob[MAP_M_Y][MAP_M_X] = {
{ 76,30,31,31,31,31,31,32,  6, 6, 6, 6, 6, 6, 6, 6, 30,31,31,31,31,31,31,76,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6 },
{ 76,39,40,40,40,40,40,41,  6, 6, 6, 6, 6, 6, 6, 6, 39,40,40,40,40,40,41,76,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6 },
{ 76,39,40,40,40,40,49,50,  6, 6, 6, 6, 6, 6, 6, 6, 39,40,40,40,40,40,41,76,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6 },
{ 76,39,40,40,40,41, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6,39,40,40,40,41,76,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6 },
{ 76,39,40,40,40,41, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6,39,40,40,40,41,76,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6 },

{ 6,39,40,40,40,41,75,75, 75,75,75,75,75,75,75,75, 75,75,39,40,40,40,41,76,  6,75,75,75,75,75,75,75, 75,75,75,75,75,75,66, 6 },
{ 6,39,40,40,40,41,75,75, 75,75,75,75,75,75,75,75, 75,75,39,40,40,40,41,76,  6,75,75,75,75,75,75,75, 75,54,55,55,55,56,75, 6 },
{ 6,39,40,40,40,41,75,75, 75,75,75,75,75,75,75,75, 75,75,39,40,40,40,41,76,  6,75,75,75,75,75,75,75, 75,63,64,64,64,65,75, 6 },
{ 6,39,40,40,40,41,75,75, 75,75,75,75,75,75,75,75, 75,75,39,40,40,40,41,76,  6,75,75,75,75,75,75,75, 75,72,64,64,64,65,75, 6 },
{ 6,39,40,40,40,41,75,75, 75,75,75,75,75,75,75,75, 75,75,39,40,40,40,41,76,  6, 6, 6, 6, 6, 6, 6, 6, 75,68,63,64,64,65,75, 6 },

{ 6,39,40,40,40,41,75,75, 75,75,75,75,75,75,75,75, 75,75,39,40,40,40,41,76,  6, 6, 6, 6, 6, 6, 6, 6, 75,68,63,64,64,65,75, 6 },
{ 6,39,40,40,40,41,75,75, 75,75,75,75,75,75,75,75, 75,75,39,40,40,40,41,76,  6, 6, 6, 6, 6, 6, 6, 6, 75,68,72,73,73,74,75, 6 },
{ 6,39,40,40,40,40,32,75, 75,75,75,75,75,75,75,75, 75,30,40,40,40,40,41,76,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75, 6 },
{ 6,39,40,40,40,40,40,31, 59,31,31,31,31,31,31,59, 31,40,40,40,40,40,41,76,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75, 6 },
{ 6,48,49,49,49,49,49,49, 59,49,49,49,49,49,49,59, 49,49,49,49,49,49,50,76, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75, 6 },

{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6,75, 54,55,55,55,55,55,55,56, 75, 6, 6, 6, 6, 6, 6, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6,75, 63,64,64,64,64,64,64,65, 75, 6, 6, 6, 6, 6, 6, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6,75, 63,64,64,64,64,64,64,65, 75, 6, 6, 6, 6, 6, 6, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6,75, 63,64,64,64,64,64,64,65, 75, 6, 6, 6, 6, 6, 6, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6,75, 72,73,73,73,73,73,73,74, 75, 6, 6, 6, 6, 6, 6, 6 },

{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6,25,25,25,25,25, 25,25,25,25,75,75,75, 6 },

{ 6,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,26,62,62,62,62, 62,62,62,26,78,79,75, 6 },
{ 6,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,54,55,55,55,55,55,55, 55,56,75,26,62,71,75,71, 75,71,62,26,75,75,75, 6 },
{ 6,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,63,64,64,64,64,64,64, 64,65,75,26,62,80,71,80, 71,80,62,26,75,75,75, 6 },
{ 6,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,63,64,64,64,64,64,64, 64,65,75,26,62,71,80,71, 80,71,62,26,75,75,75, 6 },
{ 6,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,63,64,64,64,64,64,64, 64,65,75,26,62,80,75,80, 75,80,62,26,75,75,75, 6 },

{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,63,64,64,64,64,64,64, 64,65,75,26,62,62,62,62, 62,62,62,26,75,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,63,64,64,64,64,64,64, 64,65,75,25,25,25,25,25, 25,25,25,25,75,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,72,73,73,73,73,73,73, 73,74,75,75,75,75,75,75, 75,75,75,75,75,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75, 6 },

{ 6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75,75,  6, 6, 6, 6, 6, 6, 6, 6, 75,75,75,75,75,75,75, 6 },
{ 6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6,  6, 6, 6, 6, 6, 6, 6, 6 },

};

int stageI[MAPI_Y][MAPI_X] =
{
{ 2,57,57,57,57,  57,57,62, 2, 2,   2, 2, 2, 2, 2,   2,67,11, 8, 9,  39,31,12, 9,10,  57,57,57,57, 2,   2, 2, 2, 2, 2,   2, 2, 2,57, 2 },
{59,12,13, 8, 9,  10,11,66,57,57,  57,57,57,57,57,  67,11,11, 8, 9,  39,31,12, 9,10,   8, 9, 9,10,66,  62, 2,63,57,57,   2, 2,59,11,58 },
{59,20,21,16,17,  18,19,12,13, 8,   9,10,11, 8, 9,  13,19,19,16,17,  39,31,20,17,18,  16,17,17,18,11,  58, 2,59, 8,10,  66,57,67,11,66 },
{59, 0, 0, 0, 0,   0, 0,16,21,16,  17,18,19,16,17,  21, 0, 0,87,47,  68,71,47,47,85,   0, 0, 0, 0,11,  58, 2,59,16,18,   8, 9,10,19, 8 },
{59, 0,36, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0,39, 3,   3, 3, 3, 3,71,  85, 0, 0, 0,19,  58, 2,59, 0, 0,   8, 9,10, 0,16 },

{59, 0, 0, 0, 0,   0,64,56,56,56,  65, 0, 0, 0, 0,   0, 0, 0,39, 3,   3, 3, 3, 3, 3,  31, 0, 0, 0, 0,   6, 6, 6, 0, 0,  16,17,18, 0,28 },
{59,27, 0, 0, 0,  64, 2, 2, 2, 2,  59, 0, 0, 0, 0,   0, 0,87, 3, 3,   3, 3, 3, 3, 3,  73,78,78,78,78,   2, 2,59, 0, 0,   0, 0, 0, 0,64 },
{59, 0, 0,26, 0,  66,57,57,57,57,   2,56,65, 0, 0,   0, 0,86,55,55,   3, 3, 3, 3, 3,  84,64,56,56,56,  58, 2,59, 0, 0,   0, 0,64,45,57 },
{59, 0, 0,34, 0,   8, 9,12,12,13,  66,57,67, 0, 0,   0,64,56,56,65,  86,55,55,55,84,  64,57,57,57,57,  58, 2,59, 0, 0,   0, 0,66, 9,10 },
{61,56,45,45,45,   8, 9,14,12,13,   8, 9,10, 0, 0,   0,58, 2, 2,61,  56,56,56,56,56,  67, 8, 9, 9,10,  58, 2,59, 0, 0,   0, 1, 8,17,18 },

{ 2,59, 0, 0, 0,  16,17,22,20,21,  16,17,18, 0, 0,   0,66,57,57, 2,   2, 2,63,57,57,  13,16,17,17,18,  58, 2,59, 0, 0,   0, 0,16,28,28 },
{ 2,59, 0, 0, 0,   0, 0, 0, 0 ,0,   0, 0, 1, 0, 0,   0, 8, 9,10,66,  57,57,67,11,12,  13, 0, 0, 0, 0,  58, 2,59, 0, 0,   0, 0, 0, 0,64 },
{ 2,59, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 8, 9,10, 8,   9,12,13,11,20,  21, 0,36, 0, 0,  58, 2,59, 0, 1,   0, 0, 0,64, 2 },
{63,67, 0, 0,80,  83, 0, 1, 0, 0,   0, 0, 0, 0, 0,   0, 8, 9,10, 8,   9,12,13,19, 0,   0, 0, 0,28, 0,  58, 2,59, 0, 0,   0, 0, 0,66,57 },
{59, 0, 0, 0,38,   5,46,83, 0, 0,   0, 0, 0, 0, 0,   0,16,17,18, 8,   9,12,13, 0, 0,   0, 0, 0, 0, 0,  58, 2,59, 0, 0,   0, 0, 0, 8, 9 },

{59, 0, 0, 0,38,   4, 5, 4,46,83,   0, 0, 0, 0, 0,   0, 0, 0, 0,16,  17,20,21, 0, 0,  28, 0, 0, 0, 0,  58, 2,59, 0, 0,   0, 0, 0,16,17 },
{59, 0, 0, 0,81,   4, 5, 4, 4,30,   0, 1, 0, 0, 0,   0, 0, 0, 0,28,   0, 0, 0, 0, 0,   0, 0, 0,28, 0,  58, 2,59, 0, 1,   0, 1, 0, 0,28 },
{ 2,65, 0, 1, 0,  81,54,54,54,82,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 1, 0, 0,  58, 2,59, 0, 0,   0, 0, 0,64,56 },
{ 2, 2,65, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 1,   0, 0, 0, 1, 0,   0, 0, 0,28, 0,   0, 0, 0, 0, 0,  58, 2,59, 0, 0,   0, 0, 0,66,62 },
{ 2, 2,59, 0, 0,   0, 0, 0, 0, 0,  64,56,56,65, 0,   0, 0, 0, 0, 0,  28, 0, 0, 0,36,  28, 0,28, 0, 0,  58, 2, 2,65, 0,   0, 0, 0, 0,58 },

{ 2, 2,59, 0, 0,   0, 0, 0, 0,64,  60,57,57,67, 0,   0, 0, 0, 0, 0,   0,28, 0,28, 0,   0, 1, 0, 0, 0,  58, 2, 2, 2,56,  56,65, 0,64, 2 },
{63,57,67, 0, 0,  64,56,45,45,66,  67,12,13,11, 0,   0, 0,28, 0, 0,   0, 0, 0, 0, 0,  28, 0, 0,36, 0,  58, 2, 2, 2, 2,   2,59, 0,58, 2 },
{59, 0, 0, 0, 0,  66,67,12,13, 8,   9,12,13,11, 0,   0, 0, 0, 1,28,   0, 0,28, 0,28,   0, 0, 0, 0, 0,  58, 2, 2, 2, 2,   2,59, 0,58, 2 },
{59, 0, 0, 0, 0,   8, 9,12,13,16,  17,20,21,19, 0,   0, 0,28, 0, 0,   0, 0,28,28, 0,   0, 0,28, 0, 0,  58, 2, 2, 2, 2,   2,59, 0,58, 2 },
{ 2,65, 0, 0, 0,  16,17,20,21, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 1,  58, 2,63,57,57,  57,67, 0,58, 2 },

{ 2,59, 0, 0, 0,   0, 0, 0, 0, 0,  64,56,56,56,56,  56,56,56,56,65,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0,  58, 2,59, 0, 0,   0, 0, 0,58, 2 },
{ 2,59, 0, 0, 0,  64,56,56,56,56,  60,63,57,57,57,  57,57,57, 2,61,  56,65, 0, 0, 0,   0, 1, 0, 0, 0,  58, 2,59, 0,64,  56,56,56, 2, 2 },
{ 2,59, 0, 0,64,  60,63,57,57,57,  57,67,42,43,44,   0, 0, 0,66,57,   2,59, 0, 0, 0,   0, 0, 0, 0, 0,  58, 2,59, 0,58,   2, 2, 2, 2, 2 },
{ 2,59, 0,64,60,  57,67, 0, 0, 0,   0, 0,50,51,52,   0,26, 0, 0, 0,  58,59, 0, 0, 0,   0, 0, 0, 0, 0,  58, 2,59, 0,58,   2, 2, 2, 2, 2 },
{ 2,67, 0,58,67,   0, 0, 0, 0, 0,   0, 0, 0,33, 0,   0,34, 0, 0, 0,  58,59, 0, 0, 0,   0, 0, 0, 0, 0,  66,57,67, 0,66,  57,57,57,57,57 },

{59, 0, 0,37, 0,   0,87,85, 0,27,   0,42,43,43,43,  44, 0, 0,27, 0,  58,59, 0, 0,36,   0, 0, 0, 0, 0,   8,13,11, 0, 8,   9, 8,12,13, 8 },
{59, 0, 0,37, 0,   0,39,31, 0, 0,   0,50,51,51,51,  52, 0, 0, 0 ,0,  58,59, 0, 0, 0,   0, 0, 0, 0, 0,   8,13,19, 0, 8,   9,16,20,21,16 },
{59, 0, 0,37, 0,   0,39,31,35, 0,   0,50,51,51,51,  52, 0, 0, 0, 0,  58,59, 0, 0, 1,   0, 0,36, 0, 0,  16,21, 0, 0,16,  17, 0, 0, 0,58 },
{59, 0, 0,58,65,   0,39,71,47,85,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0,  58,59, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0,64, 2 },
{61,56,56,58,59,   0,86,55,55,84,   0, 1, 0, 0, 0,   0, 0,35, 0, 0,  58,59, 0, 0, 0,   0, 0,64,56,56,  56,56,65, 0, 0,   0, 0, 0,58, 2 },

{57, 2, 2,58,59,   0, 0, 0, 0, 0,   0, 0, 1, 0, 0,   0, 0, 0, 0, 0,  58,59, 0,64,56,  56,56, 2,63,57,   2, 2, 2,56,56,  56,65, 0,58, 2 },
{10,66, 2,58, 2,  65, 0, 0, 0,24,   0, 0, 0, 0, 0,   0, 0, 0, 0,64,   2,59,45,57,57,   2, 2, 2,67,13,  66, 2, 2, 2,63,  57,61,56,60, 2 },
{10, 9,58,66,57,  57,45,45,45,45,  45,45,45,45,45,  45,45,45,45,57,  57,67, 8, 9,10,  66,57,57,12,13,   8,66,57,57,67,  13,66,57,57,62 },
{10, 9,66,11, 9,  10, 8, 9,10,11,   8,10, 8, 9,12,  13,11,12,13, 8,   9,10, 8, 9,10,  11, 8, 9,12,13,   8, 9,10,11,12,  13, 8, 9, 9,66 },
{10, 9, 8,11, 9,  10, 8, 9,10,11,   8,10, 8, 9,12,  13,11,12,13, 8,   9,10, 8, 9,10,  11, 8, 9,12,13,   8, 9,10,11,12,  13, 8, 9, 9,11 },
};

//河童のﾏｯﾌﾟ
int stageA[MAPA_Y][MAPA_X] = {
{24,24,24,24,24,24,24,24, 24,24,24,24,24,24,24,24, 24,24,24,24,24,24,24,24, 24,24,24,24,24,24,24,24, 24,24,24,24,24,24,24,24},
{24,30,31,31,31,31,31,31, 31,31,31,31,31,31,31,31, 31,31,31,31,31,31,31,31, 31,31,31,31,31,31,31,31, 31,31,31,31,31,31,32,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},

{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},

{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,48,49,49,49,49,49,49, 49,49,49,49,49,49,49,49, 49,49,49,40,49,49,49,49, 49,49,49,49,49,49,49,49, 49,49,49,49,49,49,50,24},

{24,24,24,24,24,24,24,24, 24,24,24,24,24,24,24,24, 24,24,24,40,24,24,24,24, 24,24,24,24,24,24,24,24, 24,24,24,24,24,24,24,24},
{24,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,75, 75,75,75,75,75,75,75,24},
{24,24,24,24,24,24,24,24, 24,24,24,75, 0, 1, 1, 1,  2,15,15,15,15,15, 0, 1,  1, 1, 1, 2,75,24,24,24, 24,24,24,24,24,24,24,24},
{24,30,31,31,31,31,31,31, 31,32,24,75, 9,10,10,10, 11,15, 3, 4, 5,15, 9,10, 10,10,10,11,75,24,30,31, 31,31,31,31,31,31,32,24},
{24,39,40,40,40,40,40,40, 40,41,24,75, 9,10,10,10, 11,15,12,13,14,15, 9,10, 10,10,10,11,75,24,39,40, 40,40,40,40,40,40,41,24},

{24,39,40,40,40,40,40,40, 40,41,24,75, 9,10,10,10, 11,15,21,22,23,15, 9,10, 10,10,10,11,75,24,39,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,41,24,75, 9,10,10,10, 11,15,75, 1,75,15, 9,10, 10,10,10,11,75,24,39,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,41,24,75,18,19,19,19, 19,19,19,10,19,19,19,19, 19,19,19,20,75,24,39,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,41,24,75,75,75,75,75, 75,75,75,19,75,75,75,75, 75,75,75,75,75,24,39,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,41,24,24,24,24,24,24, 24,24,24,40,24,24,24,24, 24,24,24,24,24,24,39,40, 40,40,40,40,40,40,41,24},

{24,39,40,40,40,40,40,40, 40,40,31,31,31,31,31,31, 31,31,31,40,31,31,31,31, 31,31,31,31,31,31,40,49, 49,49,49,49,49,49,50,24},
{24,24,24,24,24,24,24,24, 24,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24, 24,24,24,24,24,24,24,24},
{24,24,24,24,24,24,24,24, 24,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24, 24,24,24,24,24,24,24,24},
{24,24,24,24,25,25,25,24, 24,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24, 24,24,25,25,25,24,24,24},
{24,24,24,24,26,71,26,24, 24,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24, 24,24,26,71,26,24,24,24},

{24,24,24,24,26,80,26,24, 24,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24, 24,24,26,80,26,24,24,24},
{24,24,24,24,25,25,25,24, 24,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24, 24,24,25,25,25,24,24,24},
{24,24,24,24,24,24,24,24, 24,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24, 24,24,24,24,24,24,24,24},
{24,24,24,24,24,24,24,24, 24,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24, 24,24,24,24,24,24,24,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,31, 31,31,31,31,31,31,32,24},

{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,66,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,39,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,41,24},
{24,48,49,49,49,49,49,49, 49,49,49,49,49,49,49,49, 49,49,49,49,49,49,49,49, 49,49,49,49,49,49,49,49, 49,49,49,49,49,49,50,24},
{24,24,24,24,24,24,24,24, 24,24,24,24,24,24,24,24, 24,24,24,24,24,24,24,24, 24,24,24,24,24,24,24,24, 24,24,24,24,24,24,24,24},

};

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
	//---鬼
	LoadDivGraph("char/onimap.png", 88, 8, 11
		, CHIP_SIZE_X
		, CHIP_SIZE_Y
		, OnichipImage);
	backImage = LoadGraph("char/blok.png");

	mapPos.x = 0;
	mapPos.y = 0;
	//mapSize = { 0,0 };
	stageOffset = 0;

	// ﾏｯﾌﾟ作成ﾃﾞｰﾀ
	stageID = STAGE_ID_START;
	SetMapData(stageID);
}

// ｽﾃｰｼﾞ情報のｹﾞｰﾑ初期化
void StageGameInit(void)
{
	mapPos.x = 0;
	mapPos.y = 0;
	
	stageOffset = 0;

	// ﾏｯﾌﾟ作成ﾃﾞｰﾀ
	stageID = STAGE_ID_START;
	SetMapData(stageID);
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

	if ((stageID == STAGE_ID_START)
		|| (stageID == STAGE_ID_MOB)
		|| (stageID == STAGE_ID_KAPPA))
	{
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

		case 58:
		case 62:
		case 67:
		case 77:
			return false;
			break;

		default:

			break;
		}
	}
	else if (stageID == STAGE_ID_ONI)
	{
		switch (map[indexPos.y][indexPos.x])
		{
			//壁
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 23:
			//障害物
		case 28:
		case 33:
		case 35:
			//外周
		case 2:
		case 37:
		case 45:
		case 53:
		case 56:
		case 57:
		case 58:
		case 59:
		case 60:
		case 61:
		case 62:
		case 63:
		case 64:
		case 65:
		case 66:
		case 67:
			return false;
			break;
		default:
			break;
		}
	}

	return true;
}

// 指定した座標が特別にｲﾍﾞﾝﾄを起こすかを確認する 戻り値:ｲﾍﾞﾝﾄID
EVENT_ID GetEvent(XY pos)
{
	XY indexPos;
	indexPos = Pos2Index(pos);

	
	if ((stageID == STAGE_ID_START)
		|| (stageID == STAGE_ID_MOB)
		|| (stageID == STAGE_ID_KAPPA))
	{
		switch (map[indexPos.y][indexPos.x])
		{
		case 66:
			return EVENT_ID_KAIDAN;
			break;

			// 毒沼
		case 54:
		case 55:
		case 56:
		case 63:
		case 64:
		case 65:
		case 72:
		case 73:
		case 78:
		case 79:
			// ｲﾍﾞﾝﾄの発生場所
			return EVENT_ID_DOKU;
			break;

		default:
			break;
		}
		
	}
	else if (stageID == STAGE_ID_ONI)
	{
	
		switch (map[indexPos.y][indexPos.x])
		{
			//階段①
		case 24:
		case 49:
			//ｲﾍﾞﾝﾄの発生場所
			return EVENT_ID_KAIDAN;
			break;
		
			//洞窟
		case 14:
		case 22:
			return EVENT_ID_DOKUTU;
			break;
			//マグマ
		case 3:
		case 31:
		case 39:
		case 47:
		case 55:
		case 68:
		case 69:
		case 70:
		case 71:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
		case 79:
		case 84:
		case 85:
		case 86:
		case 87:
			//ｲﾍﾞﾝﾄの発生場所
			return EVENT_ID_DAMAGE;
			//穴
		case 36:
			return EVENT_ID_STOP;
			//川
		case 4:
		case 5:
		case 25:
		case 30:
		case 38:
		case 46:
		case 54:
		case 72:
		case 80:
		case 81:
		case 82:
		case 83:
			//ｲﾍﾞﾝﾄの発生場所
			return EVENT_ID_SPEEDDOWN;
			break;
		default:
			break;
		}
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
		stageID = stage_ID;
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
		stageID = stage_ID;
	}
	else if (stage_ID == STAGE_ID_ONI)
	{
		mapSize = { MAPI_X,MAPI_Y };

		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				map[y][x] = stageI[y][x];
			}
		}
		stageID = stage_ID;
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
		stageID = stage_ID;
	}
}

// ｹﾞｰﾑ画面の表示処理
void StageGameDraw(void)
{
	if (stageID == STAGE_ID_ONI)
	{
		DrawGraph(0 + mapPos.x, 0 + mapPos.y, backImage, true);
		DrawGraph(SCREEN_SIZE_X + mapPos.x, 0 + mapPos.y, backImage, true);
		DrawGraph(SCREEN_SIZE_X + mapPos.x, SCREEN_SIZE_Y + mapPos.y, backImage, true);
		DrawGraph(0 + mapPos.x, SCREEN_SIZE_Y + mapPos.y, backImage, true);

	}

	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			if ((stageID == STAGE_ID_START) 
				|| (stageID == STAGE_ID_MOB)
				|| (stageID == STAGE_ID_KAPPA))
			{
				DrawGraph(x * CHIP_SIZE_X + mapPos.x
					, y * CHIP_SIZE_Y + mapPos.y
					, chipImage[map[y][x]], true);
			}
			else if (stageID == STAGE_ID_ONI)
			{
				DrawGraph(x * CHIP_SIZE_X + mapPos.x
					, y * CHIP_SIZE_Y + mapPos.y
					, OnichipImage[map[y][x]], true);
			}

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

STAGE_ID GetMapDate(void)
{
	return stageID;
}
