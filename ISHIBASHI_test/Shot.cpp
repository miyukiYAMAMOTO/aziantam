#include "DxLib.h"
#include "test.h"
#include "KeyCheck.h"
#include "Item.h"
#include "Player.h"
#include "Shot.h"

#include "Stage.h"

//------外部変数定義
CHARACTER shot[SHOT_TYPE_MAX - 1];
int shotImage[SHOT_TYPE_MAX - 1][SHOT_ANI];
//int shotFlag[SHOT_TYPE_MAX - 1];


void ShotSystemInit(void)
{
	//-----変数の初期化
	shot[SHOT_TYPE_FIRE].charType = SHOT_TYPE_FIRE;
	shot[SHOT_TYPE_WATER].charType = SHOT_TYPE_WATER;
	shot[SHOT_TYPE_WIND].charType = SHOT_TYPE_WIND;
	for (int sh = 0; sh < SHOT_TYPE_MAX - 1; sh++)
	{
		shot[sh].moveDir = DIR_DOWN;							//	弾の向き
		shot[sh].size = { 40,40 };								//	弾の画像ｻｲｽﾞ
		shot[sh].offsetSize = { shot[sh].size.x / 2
			,shot[sh].size.y / 2 };			//　弾のｵﾌｾｯﾄ
		shot[sh].moveSpeed = 4;									//	弾の移動ｽﾋﾟｰﾄﾞ
		shot[sh].pos = { 0,0 };								//　弾の地図上の座標

	}

	
	//-----ｸﾞﾗﾌｨｯｸの登録
	//火
	LoadDivGraph("aitem/fire_soft.png", SHOT_ANI, 8, 8
		, shot[SHOT_TYPE_FIRE].size.x
		, shot[SHOT_TYPE_FIRE].size.y
		, shotImage[SHOT_TYPE_FIRE]);
	//水
	LoadDivGraph("aitem/water_soft.png", SHOT_ANI, 8, 8
		, shot[SHOT_TYPE_WATER].size.x
		, shot[SHOT_TYPE_WATER].size.y
		, shotImage[SHOT_TYPE_WATER]);
	//風
	LoadDivGraph("aitem/wind_soft.png", SHOT_ANI, 8, 8
		, shot[SHOT_TYPE_WIND].size.x
		, shot[SHOT_TYPE_WIND].size.y
		, shotImage[SHOT_TYPE_WIND]);

}

void ShotGameInit(void)
{
	

	for (int sh = 0; sh < SHOT_TYPE_MAX - 1; sh++)
	{
		shot[sh].lifeMax = SHOT_LIFE_MAX;						//	弾の体力最大値
		shot[sh].life = 0;						//	弾の体力
		shot[sh].animCnt = 0;									//	弾のｱﾆﾒｰｼｮﾝ
	}
}

void ShotControl(void)
{
	for (int sh = 0; sh < SHOT_TYPE_MAX - 1; sh++)
	{
		//撃っている弾を探す
		if (shot[sh].life > 0)
		{
			
			//弾を移動させる
			if (shot[sh].moveDir == DIR_RIGHT) shot[sh].pos.x += shot[sh].moveSpeed;
			if (shot[sh].moveDir == DIR_LEFT) shot[sh].pos.x -= shot[sh].moveSpeed;
			if (shot[sh].moveDir == DIR_DOWN) shot[sh].pos.y += shot[sh].moveSpeed;
			if (shot[sh].moveDir == DIR_UP) shot[sh].pos.y -= shot[sh].moveSpeed;
			//寿命を減らす（射程距離）
			shot[sh].life--;

		//			DeleteShot(sh);
		}
	}
}



//-----弾描画処理
void ShotGameDraw(void)
{
	//-----描画
	for (int sh = 0; sh < ITEM_TYPE_F_MAX - 1; sh++)
	{
		if (shot[sh].life > 0)
		{
			shot[sh].animCnt++;

			DrawGraph(shot[sh].pos.x - shot[sh].offsetSize.x + mapPos.x
				, shot[sh].pos.y - shot[sh].offsetSize.y + mapPos.y
				, shotImage[shot[sh].charType][shot[sh].animCnt]
				, true);
		}

		DrawBox(shot[sh].pos.x - shot[sh].offsetSize.x + mapPos.x
			, shot[sh].pos.y - shot[sh].offsetSize.y + mapPos.y
			, shot[sh].pos.x - shot[sh].offsetSize.x + shot[sh].size.x + mapPos.x
			, shot[sh].pos.y - shot[sh].offsetSize.y + shot[sh].size.y + mapPos.y
			, 0xFFFFFF, false);
		//-----情報処理
		DrawFormatString(0, 300, 0xFFFFFF, "shotAni:%d", shot[sh].animCnt);

	}


}


//-----弾を生成する
void CreateShot(XY pPos, DIR pDir, SHOT_TYPE ptype/*, ITEM_TYPE_F itype*/)
{

	//弾の数分撃っていない弾がないかをﾁｪｯｸし、
	//撃っていない弾があれば一発弾を作って発射する。
	for (int sh = 0; sh < SHOT_TYPE_MAX - 1; sh++)
	{
			//撃っていない弾を探す
			if (shot[sh].life <= 0)
			{
				//御札の数が0枚以上の場合のみ処理をする
			/*	if (itemF[itype].point > 0)
				{*/
					//撃っていない弾があったので発射
					shot[sh].charType = ptype;
					shot[sh].pos.x = pPos.x;				//	弾の場所
					shot[sh].pos.y = pPos.y;
					shot[sh].moveDir = pDir;				//	弾の進むべき方向
					shot[sh].life = shot[sh].lifeMax;		//	弾を撃ったことにする
					break;
			//	}
		}
	}
}

//-----弾を消滅させる
void DeleteShot(int index)
{
	if (shot[index].life < 0)
	{
		shot[index].life = 0;
	}

}

void ShotAniCnt(SHOT_TYPE type)
{
	if (shot[type].animCnt > SHOT_ANI)
	{
		shot[type].animCnt = 0;
	}
}