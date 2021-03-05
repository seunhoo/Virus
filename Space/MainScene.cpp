#include "stdafx.h"
#include "MainScene.h"
#include"asd.h"
#include"VLine.h"
#include"HLine.h"
#include"Player.h"

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
			ObjMgr->AddObject(new HLine(1920/2, j), "HLine");
		}
		for (int i = 0; i <= 1920; i += 120)
		{
			printf("%d \n", i);
			ObjMgr->AddObject(new VLine(i, 1080 / 2), "VLine");

			if (i >= 1920)
			{
				ObjMgr->AddObject(new Player(), "Player");
				m_Check = true;
			}



		}
		


	}

}

void MainScene::Render()
{
}
