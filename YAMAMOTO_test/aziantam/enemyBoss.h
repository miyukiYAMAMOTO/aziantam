#pragma once



//-----ρ^
//{X
enum ENEMY_BOSS
{
	ENEMY_ONI,		//S
	ENEMY_TENG,		//Vη
	ENEMY_KAPPA,	//ΝΆ
	ENEMY_B_MAX
};

//-----ΦΜίΫΔΐ²ΜίιΎ
//ξ{
void EnemyBossSystemInit(void);					//΄ΘΠ°ξρΜϊ»
void EnemyBossGameInit(void);					//	
void EnemyBossControl(XY pPos);					//΄ΘΠ°Μμ
void EnemyBossGameDraw(void);					//΄ΘΠ°Μ`ζ

int MoveBossX(CHARACTER* enemy, XY playerPos);
int MoveBossY(CHARACTER* enemy, XY playerPos);
//½θ»θ
bool EnemyBossHitCheck(XY sPos, int sSize, CHARACTER* shot);		//΄ΘΠ°ΖeΜ½θ»θ
bool Player_BHitCheck(XY sPos, int sSize);


//-----externιΎ
extern bool drawFlag[ENEMY_B_MAX];