#include "stdafx.h"
#include "MainScene.h"
#include"asd.h"
#include"VLine.h"
#include"HLine.h"
#include"Player.h"
#include"Monster.h"
#include"Obstacle.h"

MainScene::MainScene()
	:m_Check(false)
{
}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
	//ObjMgr->AddObject(new asd(), "123");
	m_Sprite = Sprite::Create(L"Painting/BG2.png");
	m_Sprite->SetPosition(1920 / 2, 1080 / 2);

}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	if (m_Check == false)
	{
		for (int j = 0; j <= 1080; j += 90)
		{
			//ObjMgr->AddObject(new HLine(1920/2, j), "HLine");
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

void MainScene::Render()
{
}
