#include "DxLib.h"
#include "main.h"
#include "item.h"



//-----ｺﾝｽﾄﾗｸﾀ
Item::Item(ITEM no, int posX, int posY, const char filename[],int max, int MaxX, int MaxY, int sizeX, int sizeY)
{
	//-----変数初期化
	LoadDivGraph(filename, max, MaxX, MaxY, sizeX, sizeY, itemImage);

	itemNo = no;
	itemPos = { 0,0 };
	itemFlag = true;
	itemCount = 0;
	itemHert = 10;

}


//-----
Item::~Item()
{
	DeleteGraph(itemImage[0], true);
}

//-----初期化
void Item::SystemInit(void)
{
}


//-----ゲーム内初期化
void Item::GameInit(void)
{

}

//-----操作処理
void Item::Control(void)
{
}

//-----描画処理
void Item::GameDraw(ITEM no)
{
	if (itemHert > 0)
	{
		DrawGraph(itemPos.x, itemPos.y, itemImage[no], true);
	}

}
