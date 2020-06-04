#include "DxLib.h"
#include "test.h"
#include "KeyCheck.h"
#include "Item.h"
#include "Player.h"
#include "Shot.h"
#include "Stage.h"

//------外部変数定義
CHARACTER shotMaster[SHOT_TYPE_MAX];
CHARACTER shot[SHOT_MAX];
int shotImage[SHOT_TYPE_MAX][SHOT_ANI];


void ShotSystemInit(void)
{
	//-----変数の初期化
	shotMaster[SHOT_TYPE_FIRE].charType = SHOT_TYPE_FIRE;
	shotMaster[SHOT_TYPE_WATER].charType = SHOT_TYPE_WATER;
	shotMaster[SHOT_TYPE_WIND].charType = SHOT_TYPE_WIND;
	shotMaster[SHOT_TYPE_HEAL].charType = SHOT_TYPE_HEAL;
	for (int type = 0; type < SHOT_TYPE_MAX; type++)
	{
		shotMaster[type].moveDir = DIR_DOWN;						//	弾の向き
		shotMaster[type].size = { 40,40 };							//	弾の画像ｻｲｽﾞ
		shotMaster[type].offsetSize = { shotMaster[type].size.x / 2
			,shotMaster[type].size.y / 2 };							//　弾のｵﾌｾｯﾄ
		shotMaster[type].moveSpeed = 4;								//	弾の移動ｽﾋﾟｰﾄﾞ
		shotMaster[type].pos = { 0,0 };								//　弾の地図上の座標
		shotMaster[type].lifeMax = SHOT_LIFE_MAX;						//	弾の体力最大値
		shotMaster[type].life = 0;									//	弾の体力
		shotMaster[type].animCnt = 0;								//	弾のｱﾆﾒｰｼｮﾝ


		for (int sh = 0; sh < SHOT_MAX; sh++)
		{
			shot[sh] = shotMaster[type];
			shot[sh].pos = {0,0};
			shot[type].lifeMax = SHOT_LIFE_MAX;						//	弾の体力最大値
			shot[type].life = 0;									//	弾の体力
			shot[type].animCnt = 0;								//	弾のｱﾆﾒｰｼｮﾝ

		}
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
	//回復
	LoadDivGraph("aitem/life.png", SHOT_ANI, 8, 8
		, shot[SHOT_TYPE_HEAL].size.x
		, shot[SHOT_TYPE_HEAL].size.y
		, shotImage[SHOT_TYPE_HEAL]);

}

void ShotGameInit(void)
{
	
}

void ShotControl(XY pPos)
{
	for (int sh = 0; sh < SHOT_MAX; sh++)
	{
		shot[sh].animCnt++;
		//撃っている弾を探す
		if (shot[sh].life > 0)
		{

			//弾を移動させる
			if (shot[sh].moveDir == DIR_RIGHT) shot[sh].pos.x += shot[sh].moveSpeed;
			if (shot[sh].moveDir == DIR_LEFT) shot[sh].pos.x -= shot[sh].moveSpeed;
			if (shot[sh].moveDir == DIR_DOWN) shot[sh].pos.y += shot[sh].moveSpeed;
			if (shot[sh].moveDir == DIR_UP) shot[sh].pos.y -= shot[sh].moveSpeed;
			
			if (shot[sh].charType == SHOT_TYPE_HEAL)
			{
				if (shot[sh].moveDir == DIR_RIGHT) shot[sh].pos.x = pPos.x;
				if (shot[sh].moveDir == DIR_LEFT) shot[sh].pos.x = pPos.x;
				if (shot[sh].moveDir == DIR_DOWN) shot[sh].pos.y = pPos.y;
				if (shot[sh].moveDir == DIR_UP) shot[sh].pos.y = pPos.y;
			}

			//寿命を減らす（射程距離）
			shot[sh].life--;
			if (shot[sh].animCnt > SHOT_ANI)
			{
				shot[sh].animCnt = 0;
			}

		}
	}
}



//-----弾描画処理
void ShotGameDraw(void)
{
	//-----描画
	for (int sh = 0; sh < SHOT_MAX; sh++)
	{
		if (shot[sh].life > 0)
		{
			shot[sh].animCnt++;

			DrawGraph(shot[sh].pos.x - shot[sh].offsetSize.x + mapPos.x
				, shot[sh].pos.y - shot[sh].offsetSize.y + mapPos.y
				, shotImage[shot[sh].charType][shot[sh].animCnt]
				, true);


			DrawBox(shot[sh].pos.x - shot[sh].offsetSize.x + mapPos.x
				, shot[sh].pos.y - shot[sh].offsetSize.y + mapPos.y
				, shot[sh].pos.x - shot[sh].offsetSize.x + shot[sh].size.x + mapPos.x
				, shot[sh].pos.y - shot[sh].offsetSize.y + shot[sh].size.y + mapPos.y
				, 0xFFFFFF, false);
		}
		//-----情報処理
		DrawFormatString(0, 100, 0xFFFFFF, "shotPos : %d,%d", shot[sh].pos.x, shot[sh].pos.y);
		DrawFormatString(0, 120, 0xFFFFFF, "shotAni : %d", shot[sh].animCnt);

	}


}


//-----弾を生成する
void CreateShot(XY pPos, DIR pDir, SHOT_TYPE ptype/*, ITEM_TYPE_F itype*/)
{

	//弾の数分撃っていない弾がないかをﾁｪｯｸし、
	//撃っていない弾があれば一発弾を作って発射する。
	for (int sh = 0; sh < SHOT_MAX; sh++)
	{
	//	if (shot[sh].charType == shot[ptype].charType)
	//	{

		//撃っていない弾を探す
		if (shot[sh].life <= 0)
		{
		
				//御札の数が0枚以上の場合のみ処理をする
			//	if (itemF[itype].point > 0)
			//	{
				//撃っていない弾があったので発射
			shot[sh].charType = ptype;
				shot[sh].pos.x = pPos.x;				//	弾の場所
				shot[sh].pos.y = pPos.y;
				shot[sh].moveDir = pDir;				//	弾の進むべき方向
				shot[sh].life = shot[sh].lifeMax;		//	弾を撃ったことにする
				break;
				//	}
	//		}
		}
	}
}

//-----弾を消滅させる
void DeleteShot(int index)
{
	shot[index].life = 0;
//	shot[index].animCnt = 0;
}