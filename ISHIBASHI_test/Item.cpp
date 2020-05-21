#include "DxLib.h"
#include "test.h"
#include "Item.h"
#include "Battle.h"

//-----外部変数宣言
//ｱｲﾃﾑ関連
//御札
CHARACTER itemF[ITEM_MAX];					//	ﾄﾞﾛｯﾌﾟｱｲﾃﾑ変数格納用
CHARACTER itemFmaster[ITEM_TYPE_F_MAX];
int itemFImage[ITEM_TYPE_F_MAX];			//	ﾄﾞﾛｯﾌﾟｱｲﾃﾑ用画像（F：札の頭文字
int itemFIImage[ITEM_TYPE_F_MAX];			//	ｲﾍﾞﾝﾄﾘ用画像（F：札の頭文字，I：ｲﾍﾞﾝﾄﾘの頭文字
int itemFBImage[ITEM_TYPE_F_MAX];			//	ﾎﾞｽﾊﾞﾄﾙ用画像（F：札の頭文字,　B：ﾊﾞﾄﾙの頭文字
bool itemFBFlag;							//	表示,非表示用
//三種の神器
CHARACTER itemB[ITEM_TYPE_B_MAX];
int itemBImage[ITEM_TYPE_B_MAX];			//	神器の画像（B：武器の頭文字



//-----ｱｲﾃﾑ情報の初期化
void ItemSystmeInit(void)
{
	//-----変数の初期化
	//御札（ﾄﾞﾛｯﾌﾟ用
	itemFmaster[ITEM_TYPE_HI].charType = ITEM_TYPE_HI;				//	御札の種類	：	火
	itemFmaster[ITEM_TYPE_MIZU].charType = ITEM_TYPE_MIZU;			//	御札の種類	：	水
	itemFmaster[ITEM_TYPE_KAZE].charType = ITEM_TYPE_KAZE;			//	御札の種類	：	風
	itemFmaster[ITEM_TYPE_KAIFUKU].charType = ITEM_TYPE_KAIFUKU;	//	御札の種類	：	回復
	//御札まとめて処理
	for (int i = 0; i < ITEM_TYPE_F_MAX; i++)
	{
		itemFmaster[i].pos = { 50,50 };																//　御札の地図上の座標
		itemFmaster[i].size = { 20,20 };															//	御札の画像ｻｲｽﾞ
		itemFmaster[i].offsetSize = { itemFmaster[i].size.x / 2,itemFmaster[i].size.y / 2 };		//　御札のｵﾌｾｯﾄ
		itemFmaster[i].point = 0;																	//	御札の枚数
		itemFmaster[i].lifeMax = 20;																//	御札の体力最大値（表示時間）
		itemFmaster[i].life = itemFmaster[i].lifeMax;												//	御札の体力
	}

	//御札（ﾎﾞｽﾊﾞﾄﾙ用
	itemFBFlag = false;												//	初期：非表示

	//三種の神器
	itemB[ITEM_TYPE_KEN].charType = ITEM_TYPE_KEN;					//	三種の神器　：　剣
	itemB[ITEM_TYPE_KAGAMI].charType = ITEM_TYPE_KAGAMI;			//	三種の神器　：　鏡
	itemB[ITEM_TYPE_MAGATAMA].charType = ITEM_TYPE_MAGATAMA;		//	三種の神器　：　勾玉
	//三種の神器まとめて処理
	for (int i = 0; i < ITEM_TYPE_B_MAX; i++)
	{
		itemB[i].size = { 20,20 };																	//	三種の神器の画像ｻｲｽﾞ
		itemB[i].offsetSize = { itemB[i].size.x / 2,itemB[i].size.y / 2 };							//　三種の神器のｵﾌｾｯﾄ
		
	}




	//-----ｸﾞﾗﾌｨｯｸの登録
	//御札(ﾄﾞﾛｯﾌﾟ用
	itemFImage[ITEM_TYPE_HI] = LoadGraph("aitem/R.png");			//	火の御札
	itemFImage[ITEM_TYPE_MIZU] = LoadGraph("aitem/B.png");			//	水の御札
	itemFImage[ITEM_TYPE_KAZE] = LoadGraph("aitem/G.png");			//	風の御札
	itemFImage[ITEM_TYPE_KAIFUKU] = LoadGraph("aitem/P.png");		//	回復の御札
	//御札（ｲﾍﾞﾝﾄﾘ用
	itemFIImage[ITEM_TYPE_HI] = LoadGraph("aitem/R_small.png");
	itemFIImage[ITEM_TYPE_MIZU] = LoadGraph("aitem/B_small.png");
	itemFIImage[ITEM_TYPE_KAZE] = LoadGraph("aitem/G_small.png");
	itemFIImage[ITEM_TYPE_KAIFUKU] = LoadGraph("aitem/P_small.png");
	//御札（ﾎﾞｽﾊﾞﾄﾙ用
	itemFBImage[ITEM_TYPE_HI] = LoadGraph("aitem/R_big.png");
	itemFBImage[ITEM_TYPE_MIZU] = LoadGraph("aitem/B_big.png");
	itemFBImage[ITEM_TYPE_KAZE] = LoadGraph("aitem/G_big.png");
	itemFBImage[ITEM_TYPE_KAIFUKU] = LoadGraph("aitem/P_big.png");
	//三種の神器
	itemBImage[ITEM_TYPE_KEN] = LoadGraph("aitem/剣20.png");		//	三種の神器　：　剣
	itemBImage[ITEM_TYPE_KAGAMI] = LoadGraph("aitem/鏡20.png");		//	三種の神器　：　鏡
	itemBImage[ITEM_TYPE_MAGATAMA] = LoadGraph("aitem/勾玉20.png");	//	三種の神器　：　勾玉
}

void ItemGameInit(void)
{
	//御札（ﾄﾞﾛｯﾌﾟ用
	for (int i = 0; i < ITEM_MAX; i++)
	{
		itemF[i] = itemFmaster[GetRand(ITEM_TYPE_F_MAX - 1)];
		itemF[i].pos.x = GetRand(SCREEN_SIZE_X - 1);
		itemF[i].pos.y = GetRand(SCREEN_SIZE_Y - 1);
	//	itemF[i].point = 0;																//	御札の枚数
	//	itemF[i].lifeMax = 20;															//	御札の体力最大値（表示時間）
	//	itemF[i].life = itemF[i].lifeMax;												//	御札の体力

	}
	//三種の神器
	for (int i = 0; i < ITEM_TYPE_B_MAX; i++)
	{
		itemB[i].pos = { 50,120 };									//　三種の神器の地図上の座標
		itemB[i].lifeMax = 20;										//	三種の神器の体力最大値（表示時間）
		itemB[i].life = itemB[i].lifeMax;							//	三種の神器の体力
	}

	

}

void ItemControl(void)
{
}

void ItemGameDraw(void)
{
	//-----描画処理
	//御札（ﾄﾞﾛｯﾌﾟ用
	for (int i = 0; i < ITEM_MAX; i++)
	{
		//生きてる御札のみ表示
		if (itemF[i].life > 0)
		{
			//-----画像描画
			DrawGraph(itemF[i].pos.x - itemF[i].offsetSize.x
				, itemF[i].pos.y - itemF[i].offsetSize.y
				, itemFImage[itemF[i].charType]
				, true);

			DrawBox(itemF[i].pos.x - itemF[i].offsetSize.x
				, itemF[i].pos.y - itemF[i].offsetSize.y
				, itemF[i].pos.x - itemF[i].offsetSize.x + itemF[i].size.x
				, itemF[i].pos.y - itemF[i].offsetSize.y + itemF[i].size.y
				, 0xFF00FF, false);
		}
	}
	//三種の神器
	for (int i = 0; i < ITEM_TYPE_B_MAX; i++)
	{
		if (itemB[i].life > 0)
		{
			DrawGraph((itemB[i].pos.x   - itemB[i].offsetSize.x )*i
				, itemB[i].pos.y - itemB[i].offsetSize.y
				, itemBImage[itemB[i].charType]
				, true);

			DrawBox((itemB[i].pos.x - itemB[i].offsetSize.x)*i
				, itemB[i].pos.y - itemB[i].offsetSize.y
				, (itemB[i].pos.x - itemB[i].offsetSize.x) *i+ itemB[i].size.x
				, itemB[i].pos.y - itemB[i].offsetSize.y + itemB[i].size.y
				, 0xFF00FF, false);

		}
	}
}
//-----ｲﾍﾞﾝﾄﾘ用描画
void ItemI_Draw(void)
{
	//火の御札
	DrawGraph(350, 250, itemFIImage[ITEM_TYPE_HI], true);
	DrawFormatString(380, 254, 0xFF22FF, "＠", true);
	DrawFormatString(410, 253, 0xFF22FF, "%d", itemF[ITEM_TYPE_HI].point);
	//水の御札
	DrawGraph(350, 300, itemFIImage[ITEM_TYPE_MIZU], true);
	DrawFormatString(380, 304, 0xFF22FF, "＠", true);
	DrawFormatString(410, 303, 0xFF22FF, "%d", itemF[ITEM_TYPE_MIZU].point);
	//風の御札
	DrawGraph(350, 350, itemFIImage[ITEM_TYPE_KAZE], true);
	DrawFormatString(380, 354, 0xFF22FF, "＠", true);
	DrawFormatString(410, 353, 0xFF22FF, "%d", itemF[ITEM_TYPE_KAZE].point);
	//回復の御札
	DrawGraph(350, 400, itemFIImage[ITEM_TYPE_KAIFUKU], true);
	DrawFormatString(380, 404, 0xFF22FF, "＠", true);
	DrawFormatString(410, 403, 0xFF22FF, "%d", itemF[ITEM_TYPE_KAIFUKU].point);

}

void ItemB_Draw(void)
{
	//攻撃時表示用
	if (!itemFBFlag)
	{
		for (int type = 0; type < ITEM_TYPE_F_MAX; type++)
		{
			DrawGraph((SCREEN_SIZE_X - ITEM_B_SIZE) / 2, (BOX_Y - ITEM_B_SIZE) / 2, itemFBImage[type], true);
		}
	}
	//所持ｱｲﾃﾑ残量表示用
	//火の御札
	DrawGraph(350, BOX_Y +120, itemFIImage[ITEM_TYPE_HI], true);
	DrawFormatString(352, BOX_Y + 150, 0xFF22FF, "×", true);
	DrawFormatString(380, BOX_Y + 150, 0xFF22FF, "%d", itemF[ITEM_TYPE_HI].point);
	//水の御札
	DrawGraph(450, BOX_Y + 120, itemFIImage[ITEM_TYPE_MIZU], true);
	DrawFormatString(452, BOX_Y + 150, 0xFF22FF, "×", true);
	DrawFormatString(480, BOX_Y + 150, 0xFF22FF, "%d", itemF[ITEM_TYPE_MIZU].point);
	//風の御札
	DrawGraph(550, BOX_Y + 120, itemFIImage[ITEM_TYPE_KAZE], true);
	DrawFormatString(552, BOX_Y + 150, 0xFF22FF, "×", true);
	DrawFormatString(580, BOX_Y + 150, 0xFF22FF, "%d", itemF[ITEM_TYPE_KAZE].point);
	//回復の御札
	DrawGraph(650, BOX_Y + 120, itemFIImage[ITEM_TYPE_KAIFUKU], true);
	DrawFormatString(652, BOX_Y + 150, 0xFF22FF, "×", true);
	DrawFormatString(680, BOX_Y + 150, 0xFF22FF, "%d", itemF[ITEM_TYPE_KAIFUKU].point);

}

//-----弾と敵の当たり判定　(true : あたり, false : はずれ)
bool ItemHitCheck(XY sPos, int sSize)
{
	//全ての敵に当たり判定を実施する
	for (int i = 0; i < ITEM_MAX; i++)
	{
		if (itemF[i].life > 0)
		{
			if (((itemF[i].pos.x - itemF[i].size.x / 2) < (sPos.x + sSize / 2))
				&& ((itemF[i].pos.x + itemF[i].size.x / 2) > (sPos.x - sSize / 2))
				&& ((itemF[i].pos.y - itemF[i].size.y / 2) < (sPos.y + sSize / 2))
				&& ((itemF[i].pos.y + itemF[i].size.y / 2) > (sPos.y - sSize / 2)))
			{
				//当たった時、ｴﾈﾐｰの体力を減らす
				itemF[i].life = 0;
				//ｴﾈﾐｰを倒した時だけﾎﾟｲﾝﾄ加算
				//御札に触れたら加算
				if (itemF[i].charType == ITEM_TYPE_HI)
				{
					itemF[ITEM_TYPE_HI].point++;
					//hiCnt++;
				}
				if (itemF[i].charType == ITEM_TYPE_MIZU)
				{
					itemF[ITEM_TYPE_MIZU].point++;
					//mizuCnt++;
				}
				if (itemF[i].charType == ITEM_TYPE_KAZE)
				{
					itemF[ITEM_TYPE_KAZE].point++;
					//kazeCnt++;
				}
				if (itemF[i].charType == ITEM_TYPE_KAIFUKU)
				{
					itemF[ITEM_TYPE_KAIFUKU].point++;
					//kaifukuCnt++;
				}
				return true;
			}
		}
	}
	//弾が外れた時
	return false;
}

//-----弾を消滅させる
void DeleteItem(int index)
{
	itemF[index].life = 0;
	
};