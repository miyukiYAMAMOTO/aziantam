//#pragma once

//-----定数定義
#define SHOT_ANI		46				//　弾のｱﾆﾒｰｼｮﾝ数
#define SHOT_LIFE_MAX	46
#define SHOT_MAX		20




//-----関数ﾌﾟﾛﾄﾀｲﾌﾟ宣言
void ShotSystemInit(void);					//　弾情報の初期化	
void ShotGameInit(void);
void ShotControl(XY pPos);					//	弾の操作
void ShotGameDraw(void);				//	弾の描画処理
void CreateShot(XY pPos, DIR pDir, MAGIC_TYPE ptype);
void DeleteShot(int index);

//-----ｸﾞﾛｰﾊﾞﾙ化
extern CHARACTER shot[];