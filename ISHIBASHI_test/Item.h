//#pragma once


//-----θθ`
#define ITEM_MAX 50

//-----ρ^
enum ITEM_TYPE_F
{
	ITEM_TYPE_HI,				//	ΞΜδD
	ITEM_TYPE_MIZU,				//	ΜδD
	ITEM_TYPE_KAZE,				//	ΜδD
	ITEM_TYPE_KAIFUKU,			//	ρΜδD
	ITEM_TYPE_F_MAX
};
enum ITEM_TYPE_B
{
	ITEM_TYPE_KEN,				//	OνΜ_νE
	ITEM_TYPE_KAGAMI,			//	OνΜ_νEΎ
	ITEM_TYPE_MAGATAMA,			//	OνΜ_νEωΚ
	ITEM_TYPE_B_MAX
};


//-----ΦΜίΫΔΐ²ΜίιΎ
void ItemSystmeInit(void);		//@±²ΓΡξρΜϊ»	
void ItemGameInit(void);		//						
void ItemControl(void);			//	±²ΓΡΜμ
void ItemGameDraw(void);		//@±²ΓΡ`ζ
void Item_IDraw(void);			//	²ΝήέΔΨpΜ±²ΓΡζ`ζ
bool ItemHitCheck(XY sPos, int sSize);
void DeleteItem(int index);

//-----ΈήΫ°ΚήΩ»
extern CHARACTER itemF[];
