#include "DxLib.h"
#include "test.h"
#include "KeyCheck.h"
#include "Item.h"
#include "Battle.h"

int testbkImage;
int tBossImage[8];
int BossImage;
int bossCnt;

void BattleSystmeInit(void)
{
	//-----ΈήΧΜ¨―ΈΜo^
	testbkImage = LoadGraph("aitem/bg.jpg");
	LoadDivGraph("aitem/boss.png", 8, 4, 2, 400, 500, tBossImage);
	BossImage = LoadGraph("aitem/boss2.png");
	//-----ϊ»
	bossCnt = 0;
}

void BattleGameInit(void)
{
}


void BattleScene(void)
{

	if (keyDownTrigger[KEY_ID_SPACE])
	{
		sceneID = SCENE_ID_INIT;
	}
	ItemControl();
	BattleControl();
	//`ζ
	BattleGameDraw();
}


void BattleControl(void)
{





}



void BattleGameDraw(void)
{
	//-----`ζ
	//wi
	DrawGraph(0, 0, testbkImage, true);
	//G
	bossCnt++;
//	DrawGraph((SCREEN_SIZE_X - 400) / 2, (BOX_Y - 500) / 2, tBossImage[(bossCnt / 16) % 8], true);
	DrawGraph((SCREEN_SIZE_X - 400) / 2, 0, BossImage, true);
	//-----ξρ
	DrawFormatString(0, 0, 0xFFFFFF, "Battle : %d", SceneCounter);

	SetDrawBright(200, 200, 200);
	DrawBox(BOX_X, BOX_Y, BOX_END_X, BOX_END_Y, 0xFFFFFF, true);
	SetDrawBright(255, 255, 255);
	DrawBox(BOX_X, BOX_Y, BOX_END_X, BOX_END_Y, 0xFF22FF, false);


	//±²ΓΡ
	ItemB_Draw();

}
