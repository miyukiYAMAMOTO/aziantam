#include "DxLib.h"
#include "main.h"
#include "keycheck.h"
#include "effect.h"
#include "stage.h"
#include "player.h"
#include "enemy.h"
#include "shot.h"
#include "item.h"


//-----変数
//ｼｰﾝ関連
SCENE SceneID;
SCENE ScenePreID;	//過去のｼｰﾝ格納用
int SceneCounter;

//ｲﾝﾍﾞﾝﾄﾘ関連
bool iventFlag;

//PAUSE関連
bool paseFlag;
int keyImage;

//Win関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	if (!SystemInit())return -1;

	//-----ｹﾞｰﾑﾙｰﾌﾟ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//keyの情報取得
		KeyCheck();
		//ｼｰﾝｶｳﾝﾄﾘｾｯﾄ
		if (SceneID != ScenePreID)
		{
			ScenePreID = SceneID;
			SceneCounter = 0;
		}
		//-----画面描画処理
		ClsDrawScreen();	//画面消去
		//ｼｰﾝ選択
		switch (SceneID)
		{
		case SCENE_INIT:
			InitScene();
			break;
		//ﾀｲﾄﾙｼｰﾝ
		case SCENE_TITLE:
			TitleScene();
			break;
		//ｹﾞｰﾑｼｰﾝ
		case SCENE_GAME:
			GameScene();
			break;
		//ｹﾞｰﾑｵｰﾊﾞｰｼｰﾝ
		case SCENE_GAMEOVER:
			GameOverScene();
			break;
		default:
			return -1;
			break;
		}
		SceneCounter++;		
		ScreenFlip();		//裏画面を表画面に瞬間ｺﾋﾟｰ
	}
	
	DxLib_End();			//DXﾗｲﾌﾞﾗﾘの終了処理
	return 0;				//このﾌﾟﾛｸﾞﾗﾑの終了

}
//ｼｽﾃﾑの初期化
bool SystemInit(void)
{
	//--------ｼｽﾃﾑ処理
	SetWindowText("月夜〜三つの神宝〜");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)return false;
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----key情報の初期化
	KeyInit();

	//-----各ﾓｼﾞｭｰﾙの初期化
	StageSystemInit();			//ｽﾃｰｼﾞ
	PlayerSystemInit();			//ﾌﾟﾚｲﾔｰ
	EnemySystemInit();			//敵mob
	ItemSystmeInit();			//ｱｲﾃﾑ

	//-----ｸﾞﾗﾌｨｯｸ登録
	keyImage = LoadGraph("item/操作説明.png");

	//-----変数の初期化
	//ｼｰﾝ関連
	SceneCounter = 0;
	SceneID = SCENE_INIT;
	ScenePreID = SCENE_MAX;
	//PAUSE
	pauseFlag = false;
	//ｲﾝﾍﾞﾝﾄリ
	iventFlag = false;
	
	
	return true;
}
//初期化ｼｰﾝ
void InitScene(void)
{
	//-----各ｵﾌﾞｼﾞｪｸﾄ処理
	StageGameInit();				//ｽﾃｰｼﾞ
	PlayerGameInit();				//ﾌﾟﾚｲﾔｰ
	EnemyGameInit();				//敵
	ItemGameInit();					//ｱｲﾃﾑ
	
	//-----ｼｰﾝ遷移
	SceneID = SCENE_TITLE;
}




/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
//ﾀｲﾄﾙｼｰﾝ
void TitleScene(void)
{
	//-----ｼｰﾝ遷移
	if (KeyDownTrigger[KEY_ID_SPACE]) SceneID = SCENE_GAME;

	//-----描画
	TitleDraw();
}
//ﾀｲﾄﾙの描画
void TitleDraw(void)
{
	//-----描画処理

	//-----情報処理
	DrawFormatString(0, 0, 0xFFFFFF, "Title:%d", SceneCounter);

}



///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//ｹﾞｰﾑｼｰﾝ
void GameScene(void)
{
	XY playerPos;		//ﾌﾟﾚｲﾔｰの座標格納領域


	//ｼｰﾝ遷移
	if (KeyDownTrigger[KEY_ID_SPACE]) SceneID = SCENE_GAMEOVER;



	//-----ｲﾍﾞﾝﾄﾘ機能
	//ｷｰ処理
	if (KeyDownTrigger[KEY_ID_IVENT]) iventFlag = !iventFlag;
	//ﾌﾗｸﾞ処理
	if (iventFlag)
	{
		SetDrawBright(128, 128, 128);
		pauseFlag = false;
	}

	//-----PAUSE機能
	if (KeyDownTrigger[KEY_ID_PAUSE]) pauseFlag = !pauseFlag;
	if (pauseFlag)
	{
		SetDrawBright(128, 128, 128);
		iventFlag = false;
	}

	//通常時操作
	if(!iventFlag && !pauseFlag)
	{
		//各種機能
		//-----各ｵﾌﾞｼﾞｪｸﾄ操作
		playerPos = PlayerControl();		//　ﾌﾟﾚｲﾔｰ
		EnemyControl(playerPos);			//	敵
		ItemControl();			//	ｱｲﾃﾑ
		}

	
	//-----描画
	GameDraw(); 
}


//ｹﾞｰﾑの描画
void GameDraw(void)
{

	//-----各ｵﾌﾞｼﾞｪｸﾄ描画処理
	StageGameDraw();			//ｽﾃｰｼﾞ
	PlayerGameDraw();			//ﾌﾟﾚｲﾔｰ
	EnemyGameDraw();			//敵
	ItemGameDraw();				//ｱｲﾃﾑ
	//-----ｲﾝﾍﾞﾝﾄﾘ関連
	if (iventFlag)
	{
		SetDrawBright(255, 255, 255);
		DrawBox(100, 100, 700, 600, 0xFFFFFF, true);
		//御札
		ItemI_Draw();

	}
	//----PAUSE関連
	if (pauseFlag)
	{
		SetDrawBright(255, 255, 255);									//	暗くする
		DrawBox(50, 50, 750, 600, 0x222222, true);						//	枠
		DrawGraph((SCREEN_SIZE_X - 650) / 2, 180, keyImage, true);		//	ｲﾗｽﾄ
		DrawString(100, 100, "KEY操作説明", 0xFFFFFF, true);			//	ｺﾒﾝﾄ
		DrawString(99, 110, "------------", 0xFFFFFF, true);			//	ｺﾒﾝﾄ下線

		DrawString(150, 430, "Z : 火の攻撃", 0xFFFFFF, true);
		DrawString(150, 460, "X : 水の攻撃", 0xFFFFFF, true);
		DrawString(150, 490, "C : 風の攻撃", 0xFFFFFF, true);
		DrawString(150, 520, "V : 回復", 0xFFFFFF, true);
		DrawString(400, 430, "M : メニュー画面", 0xFFFFFF, true);
		DrawString(400, 460, "I : アイテムメニュー", 0xFFFFFF, true);

	}
	
	//-----情報処理
	DrawFormatString(0, 0, 0xFFFFFF, "Game:%d", SceneCounter);

}





//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//ｹﾞｰﾑｵｰﾊﾞｰｼｰﾝ
void GameOverScene(void)
{
	if (KeyDownTrigger[KEY_ID_SPACE]) SceneID = SCENE_INIT;


	GameOverDraw();
}


//ｹﾞｰﾑｵｰﾊﾞｰの描画
void GameOverDraw(void)
{
	//-----描画処理

	//-----情報処理
	DrawFormatString(0, 0, 0xFFFFFF, "GameOver:%d", SceneCounter);


}
