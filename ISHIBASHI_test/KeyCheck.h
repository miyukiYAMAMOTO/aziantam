//#pragma once


//-----ρ^
enum KEY_ID
{
	KEY_ID_SPACE,					//	½Νί°½·°
	KEY_ID_PAUSE,					//	P
	KEY_ID_IVENT,					//	I
	KEY_ID_UP,						//	ͺ
	KEY_ID_RIGHT,					//@¨
	KEY_ID_DOWN,					//	«
	KEY_ID_LEFT,					//@©
	KEY_ID_SHOT,					//	ΆCtrl
	KEY_ID_FIRE,					//	UFΞ
	KEY_ID_WATER,					//	UF
	KEY_ID_WIND,					//@UF
	KEY_ID_HEAL,					//	ρ
	KEY_ID_MAX
};


//-----ΦΜίΫΔΐ²ΜίιΎ
void KeyInit(void);										//	όΝξρϊ»
void KeyCheck(void);									//	όΝξρΜmF


//-----O[o»
extern bool keyOld[KEY_ID_MAX];							//	1ΜΪ°ΡOΜόΝσΤ
extern bool keyNew[KEY_ID_MAX];							//	»έΜόΝσΤ
extern bool keyDownTrigger[KEY_ID_MAX];					//	ΐή³έΜΔΨΆή°
extern bool keyUpTrigger[KEY_ID_MAX];					//	±―ΜίΜΔΨΆή°


