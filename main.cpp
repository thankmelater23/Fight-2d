#include "DarkGDK.h"

void DarkGDK(void)
{
	int const BACKGROUND_IMG =		1;
	int const BACKGROUND_SPRITE =	1;
	int const HERO_IMG =			2;
	int const HERO_SPRITE =			2;
	int const HEALTH_BAR_IMG =		3;
	int const HEALTH_BAR_SPRITE =	3;
	int const GROUND1_IMG =			4;
	int const GROUND1_SPRITE =		4;
	int const GROUND2_IMG =			5;
	int const GROUND2_SPRITE =		5;

	int const HERO_STRT_X =			200;
	int const HERO_STRT_Y =			250;
	int const HEALTH_BAR_STRT_X =	0;
	int const HEALTH_BAR_STRT_Y =	0;
	int const GROUND1_STRT_X =		0;
	int const GROUND1_STRT_Y =		350;
	int const GROUND2_STRT_X =		0;
	int const GROUND2_STRT_Y =		390;
	int const BACKGROUND_STRT_X =	0;
	int const BACKGROUND_STRT_Y =	40;

	int const RGT_LFT_SPD =			9;
	int const DWN_SPD =				20;
	int const UP_SPD =				150;


	int HeroX = dbSpriteX(HERO_SPRITE);
	int Heroy = dbSpriteY(HERO_SPRITE);

	int const SYNC = 25;

	DWORD const GREEN = dbRGB(0, 255, 0);
	DWORD const RED = dbRGB(255, 0, 0);
	DWORD const BLUE = dbRGB(0, 0, 255);

	dbSetWindowTitle("Fight");
	dbSyncOn();
	dbSyncRate(SYNC);
	dbDisableEscapeKey();
	dbSetImageColorKey(0, 255, 0);
	dbLoadImage("backgroundG.bmp", BACKGROUND_IMG);
	dbSprite(BACKGROUND_SPRITE, BACKGROUND_STRT_X, BACKGROUND_STRT_Y, BACKGROUND_IMG);
	dbLoadImage("HealthBar.bmp", HEALTH_BAR_IMG);
	dbSprite(HEALTH_BAR_SPRITE, HEALTH_BAR_STRT_X, HEALTH_BAR_STRT_Y, HEALTH_BAR_IMG);
	dbLoadImage("ground12.bmp", GROUND1_IMG);
	dbSprite(GROUND1_SPRITE, GROUND1_STRT_X, GROUND1_STRT_Y, GROUND1_IMG);
	dbLoadImage("grounded.bmp", GROUND2_IMG);
	dbSprite(GROUND2_SPRITE,GROUND2_STRT_X, GROUND2_STRT_Y, GROUND2_IMG);
	dbLoadImage("player.bmp", HERO_IMG);
	dbSprite(HERO_SPRITE, HERO_STRT_X,HERO_STRT_Y, HERO_IMG);
	dbSetSpritePriority(HERO_SPRITE, 1);
	dbWaitKey();
	



	while(LoopGDK())
	{

		
			if(dbSpriteCollision(HERO_SPRITE, GROUND2_SPRITE) != 1)
		{
			dbRotateSprite(HERO_SPRITE,180);
			dbMoveSprite(HERO_SPRITE,8);
			dbRotateSprite(HERO_SPRITE,0);
		}

			


		if(dbUpKey() == 1)
		{
			if(dbSpriteCollision(HERO_SPRITE, GROUND2_SPRITE) == 1)
			{

			dbMoveSprite(HERO_SPRITE, UP_SPD);
			}
		}     



		if(dbLeftKey() == 1)
		{

			dbRotateSprite(HERO_SPRITE,270);
			dbMoveSprite(HERO_SPRITE,RGT_LFT_SPD);
			dbRotateSprite(HERO_SPRITE, 0);

		}



		if(dbRightKey() == 1)
		{
			dbRotateSprite(HERO_SPRITE,90);
			dbMoveSprite(HERO_SPRITE,RGT_LFT_SPD);
			dbRotateSprite(HERO_SPRITE, 0);

		}



		if(dbDownKey() == 1)
			{
			
			if(dbSpriteCollision(HERO_SPRITE, GROUND2_SPRITE) != 1)
			{
			dbRotateSprite(HERO_SPRITE,180);
			dbMoveSprite(HERO_SPRITE, 1);
			dbRotateSprite(HERO_SPRITE, 0);
			}
			}



		if(dbEscapeKey() == 1)
		{
			break;
		}

		dbSync();
	}

	for(int i = 1; i > 10; i++)
	{
	dbDeleteImage(i);
	dbDeleteSprite(i);
	}
	return;
}