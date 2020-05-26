#include "DxLib.h"
#include "test.h"
#include "KeyCheck.h"
#include "Item.h"
#include "Battle.h"

int testbkImage;		//ﾃｽﾄ用背景

CHARACTER boss;
int tBossImage[8];		//ぴえん鬼通常時
int tBossDImage[2];		//ぴえん鬼ﾀﾞﾒｰｼﾞ時
int BossImage;


void BattleSystmeInit(void)
{
	//-----初期化
	boss.size = { 400,500 };							//	ｷｬﾗｸﾀの画像ｻｲｽﾞ
	boss.offsetSize = { boss.size.x / 2,boss.size.y / 2 };		//　ｷｬﾗｸﾀのｵﾌｾｯﾄ
	boss.hitFlag = false;			//攻撃を受けているかどうか
	
	//-----ｸﾞﾗﾌｨｯｸの登録
	testbkImage = LoadGraph("aitem/bg.jpg");
	LoadDivGraph("aitem/boss.png", 8, 4, 2, boss.size.x, boss.size.y, tBossImage);
	LoadDivGraph("aitem/bs_D.png", 2, 2, 1, boss.size.x, boss.size.y, tBossDImage);

	BossImage = LoadGraph("aitem/boss2.png");

}

void BattleGameInit(void)
{
	boss.pos = { (SCREEN_SIZE_X - boss.size.x) / 2,(BOX_Y - boss.size.y) / 2 };				//　ｷｬﾗｸﾀの地図上の座標
	boss.lifeMax = 500;												//	ｷｬﾗｸﾀの体力最大値
	boss.life = boss.lifeMax;										//	ｷｬﾗｸﾀの体力
	boss.animCnt = 0;													//	ｷｬﾗｸﾀのｱﾆﾒｰｼｮﾝ

}


void BattleScene(void)
{

	if (keyDownTrigger[KEY_ID_SPACE])
	{
		sceneID = SCENE_ID_INIT;
	}
	ItemControl();
	BattleControl();
	//描画処理
	BattleGameDraw();
}


void BattleControl(void)
{

	for (int type = 0; type < ITEM_TYPE_F_MAX; type++)
	{
		if (itemF[type].point--)
		{
			boss.hitFlag = true;
		}
	}



}



void BattleGameDraw(void)
{
	//-----描画処理
	//背景
	DrawGraph(0, 0, testbkImage, true);
	//敵
	if (boss.life > 0)
	{
		boss.animCnt++;
		if (!boss.hitFlag)
		{
			DrawGraph(boss.pos.x, boss.pos.y, tBossImage[(boss.animCnt / 16) % 8], true);
		}
		else if(boss.hitFlag)
		{
			DrawGraph(boss.pos.x, boss.pos.y, tBossDImage[(boss.animCnt / 10) % 2], true);
		}
		//	DrawGraph((SCREEN_SIZE_X - 400) / 2, 0, BossImage, true);
	}
	//-----情報処理
	DrawFormatString(0, 0, 0xFFFFFF, "Battle : %d", SceneCounter);

	SetDrawBright(200, 200, 200);
	DrawBox(BOX_X, BOX_Y, BOX_END_X, BOX_END_Y, 0xFFFFFF, true);
	SetDrawBright(255, 255, 255);
	DrawBox(BOX_X, BOX_Y, BOX_END_X, BOX_END_Y, 0xFF22FF, false);


	//ｱｲﾃﾑ
	ItemB_Draw();

}
