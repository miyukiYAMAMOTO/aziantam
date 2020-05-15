//月夜
//stage.cpp
//2020.05.13

#include "DxLib.h"
#include "main.h"
#include "stage.h"
#include "player.h"
#include "enemy.h"

//ダンジョン
//村のマップ
int stage[MAP_Y][MAP_X] = {
{ 2,2,2,2,2, 2,2,2,2,2, 2,2,2,2,2, 2,2,2,2,2, 2,2,2,2,2},
{ 2,14,14,14,14, 2,14,2,14,14, 2,14,14,14,14, 14,14,14,2,14, 14,14,14,14,2},
{ 2,14,14,2,14, 2,14,14,14,14, 2,14,2,2,2, 2,2,14,2,14, 2,2,2,2,2 },
{ 2,14,2,2,14, 2,14,2,14,14, 2,14,14,14,2, 14,2,14,2,14, 14,14,14,14,2 },
{ 2,14,14,2,14, 14,14,2,14,14, 2,14,14,2,14, 14,2,14,2,2, 2,2,2,14,2 },

{ 2,2,14,14,2, 2,2,2,2,14, 14,14,2,14,14, 2,2,14,14,14, 14,14,2,14,2 },
{ 2,2,14,14,14, 14,2,14,2,2, 2,2,14,14,2, 2,14,2,2,2, 14,14,14,14,2 },
{ 2,14,14,2,2, 14,14,14,14,14, 14,14,14,2,2, 14,14,14,14,2, 14,2,2,2,2 },
{ 2,14,2,2,14, 2,14,14,2,14, 14,14,14,2,14, 14,2,14,14,2, 14,14,14,14,2 },
{ 2,14,2,14,14, 2,14,2,14,14, 2,8,2,14,2, 2,14,14,2,2, 2,2,2,14,2 },

{ 2,14,14,2,14, 14,14,2,14,2, 14,14,2,14,14, 2,14,2,14,14, 14,14,2,14,2 },
{ 2,14,2,14,2, 14,2,14,14,2, 8,2,14,2,14, 2,14,14,8,2, 8,14,2,14,2 },
{ 2,14,2,14,14, 2,2,14,2,14, 14,14,2,14,14, 14,2,2,2,2, 2,14,2,14,2 },
{ 2,14,14,2,14, 2,14,14,2,14, 14,2,14,2,14, 14,14,14,14,14, 2,14,2,14,2 },
{ 2,14,8,14,2, 2,14,2,14,14, 14,14,2,14,14, 2,2,2,2,2, 2,14,2,14,2 },

{ 2,14,2,14,2, 14,2,2,14,2, 14,2,2,14,14, 14,14,14,2,14, 14,14,14,14,2 },
{ 2,14,2,14,2, 14,2,2,14,14, 2,14,2,2,2, 14,2,14,2,14, 2,2,2,2,2 },
{ 2,14,2,14,2, 14,14,14,14,14, 2,14,14,2,14, 8,2,14,2,14, 14,14,14,14,2 },
{ 2,14,2,2,14, 14,2,2,2,2, 2,2,14,2,14, 2,2,14,2,14, 2,2,2,14,2 },
{ 2,14,2,14,14, 14,2,14,14,14, 2,14,14,2,14, 14,2,14,14,14, 2,14,14,14,2 },

{ 2,2,2,2,14, 2,2,14,2,8, 2,14,2,2,2, 14,2,2,2,2, 2,14,2,14,2 },
{ 2,14,14,14,14, 14,14,14,2,14, 2,14,14,2,14, 14,14,14,14,14, 14,14,2,14,2 },
{ 2,14,8,2,2, 2,2,14,2,14, 2,14,14,14,2, 8,2,2,2,2, 2,2,2,14,2 },
{ 2,15,2,14,14, 14,14,8,2,14, 14,14,14,2,14, 14,14,14,14,14, 14,14,14,14,2 },
{ 2,2,2,2,2, 2,2,2,2,2, 2,2,2,2,2, 2,2,2,2,2, 2,2,2,2,2 },
};


