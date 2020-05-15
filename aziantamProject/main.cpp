#include "DxLib.h"
#include "main.h"

//変数
SCENE SceneID;
SCENE ScenePreID;	//過去のｼｰﾝ格納用
int SceneCounter;

//ｸﾗｽからｲﾝｽﾀﾝｽを生成


//Win関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	if (!SystemInit())
	{
		return -1;
	}
	//ｰｰｰｰｰｰｰｹﾞｰﾑﾙｰﾌﾟ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//ｼｰﾝｶｳﾝﾄﾘｾｯﾄ
		if (SceneID != ScenePreID)
		{
			ScenePreID = SceneID;
			SceneCounter = 0;
		}
		//ｰｰｰｰ画面描画処理
		ClsDrawScreen();	//画面消去
		//ｼｰﾝ選択
		switch (SceneID)
		{
		case SCENE_INIT:
			InitScene();
			break;
		case SCENE_TITLE:
			TitleScene();
			break;
		case SCENE_GAME:
			GameScene();
			break;
		case SCENE_GAMEOVER:
			GameOverScene();
			break;
		default:
			return -1;
			break;
		}
		SceneCounter++;
		ScreenFlip();		//　裏画面を表画面に瞬間ｺﾋﾟｰ
	}
	//ｲﾝｽﾀﾝｽの解放


	DxLib_End();			// DXﾗｲﾌﾞﾗﾘの終了処理
	return 0;				// このﾌﾟﾛｸﾞﾗﾑの終了

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
	
	//ｲﾝｽﾀﾝｽの生成

	//ｸﾞﾗﾌｨｯｸ登録

	//変数の初期化
	SceneCounter = 0;
	SceneID = SCENE_INIT;
	ScenePreID = SCENE_MAX;

	return true;
}
//初期化ｼｰﾝ
void InitScene(void)
{
	
}
//ﾀｲﾄﾙｼｰﾝ
void TitleScene(void)
{
	TitleDraw();
}
//ﾀｲﾄﾙの描画
void TitleDraw(void)
{

}

//ｹﾞｰﾑｼｰﾝ
void GameScene(void)
{
	GameDraw();
}
//ｹﾞｰﾑの描画
void GameDraw(void)
{

}
//ｹﾞｰﾑｵｰﾊﾞｰｼｰﾝ
void GameOverScene(void)
{
	GameOverDraw();
}
//ｹﾞｰﾑｵｰﾊﾞｰの描画
void GameOverDraw(void)
{

}
