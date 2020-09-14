

//-----�萔��`
#define ENEMY	  3	  
#define ENEMY_MAX ENEMY * 3		//	�G�̐�

#define DAMAGE_NORMAL	2		//��������Ұ�ޗ�
#define DAMAGE_HIGH		3		//�L��������Ұ�ޗ�
#define DAMAGE_LOW		1		//�s��������Ұ�ޗ�



//-----�񋓌^
//���u
enum ENEMY_MOB
{
	ENEMY_I_MOB,	//�΋��S��
	ENEMY_Y_MOB,	//�R�{�S��
	ENEMY_A_MOB,	//�r�ؒS��
	ENEMY_M_MAX
};

//-----�֐��������ߐ錾
//��{����
void EnemySystemInit(void);					//��а���̏�����
void EnemyGameInit(STAGE_ID stageID);
void EnemyControl(XY pPos);					//��а�̑���
void EnemyGameDraw(void);					//��а�̕`�揈��
int MoveEnemyX(CHARACTER* enemy, XY playerPos); //���@��X���W�ɒ��߂���悤�ɓ������@�߂�l�F�ړ�������
int MoveEnemyY(CHARACTER* enemy, XY playerPos); //���@��Y���W�ɒ��߂���悤�ɓ������@�߂�l�F�ړ�������
int MoveEnemyXY(CHARACTER* enemy, XY playerPos); //���@��X��Y�̉����ق�������W�𒲐߂���悤�ɓ������@�߂�l�F�ړ�������

//�����蔻��
bool EnemyHitCheck(XY sPos, int sSize, CHARACTER* shot);		//��а�ƒe�̓����蔻��
bool PlayerHitCheck(XY sPos, int sSize);

bool SetEnemyMoment(void);				//
bool EFlagInit(void);						//�G���X�e�[�W���ƂőS�ł��������f�p�t���O��p�̏�����


extern bool eFlag_mob;
extern bool eFlag_oni;
extern bool eFlag_kappa;