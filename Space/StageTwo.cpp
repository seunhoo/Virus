#include"stdafx.h"
#include "StageTwo.h"
#include"HLine.h"
#include"VLine.h"
#include"Monster.h"
#include"Obstacle.h"
#include"Player.h"

StageTwo::StageTwo()
	:m_Check(false)
{
}

void StageTwo::Init()
{

}

void StageTwo::Release()
{
}

void StageTwo::Update(float deltatime, float time)
{
	if (m_Check == false)
	{
		printf("topw");
		for (int j = 0; j <= 1080; j += 60)
		{
			//ObjMgr->AddObject(new HLine(1920 / 2, j), "HLine");
		}
		for (int i = 0; i <= 1920; i += 120)
		{
			//ObjMgr->AddObject(new VLine(i, 1080 / 2), "VLine");

			if (i >= 1920)
			{
				ObjMgr->AddObject(new Monster(1), "SpeedMonster");
				ObjMgr->AddObject(new Monster(2), "BigMonster");
				ObjMgr->AddObject(new Monster(3), "FlashMonster");
				ObjMgr->AddObject(new Monster(4), "BossMonster");

				ObjMgr->AddObject(new Obstacle(), "Obstacle");

				ObjMgr->AddObject(new Player(), "Player");
				m_Check = true;
			}
		}
	}
}

void StageTwo::Render()
{
}
