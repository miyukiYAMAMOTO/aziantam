

//-----θθ`
#define ENEMY_MAX 20		//	GΜ


//-----ρ^
//u
enum ENEMY_MOB
{
	ENEMY_I_MOB,	//Ξ΄S
	ENEMY_Y_MOB,	//R{S
	ENEMY_A_MOB,	//rΨS
	ENEMY_M_MAX
};
//{X
enum ENEMY_BOSS
{
	ENEMY_ONI,		//S
	ENEMY_TENG,		//Vη
	ENEMY_KAPPA,	//ΝΆ
	ENEMY_NUE,		//κK
	ENEMY_B_MAX
};

//-----ΦΜίΫΔΐ²ΜίιΎ
void EnemySystemInit(void);					//΄ΘΠ°ξρΜϊ»
void EnemyGameInit(void);					//	
void EnemyControl(XY pPos);					//΄ΘΠ°Μμ
void EnemyGameDraw(void);					//΄ΘΠ°Μ`ζ

bool EnemyHitCheck(XY sPos, int sSize);		//΄ΘΠ°ΖeΜ½θ»θ