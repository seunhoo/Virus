#include "stdafx.h"
#include "MainScene.h"
#include"asd.h"
#include"VLine.h"
#include"HLine.h"

MainScene::MainScene()
	:m_Check(false)
{
}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
	ObjMgr->AddObject(new asd(), "123");
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	if (m_Check == false)
	{
		for (int i = 0; i <= 1920; i += 192)
		{
			printf("%d \n", i);
			ObjMgr->AddObject(new VLine(i, 1080 / 2), "VLine");
			ObjMgr->AddObject(new HLine(i, 1080 / 2), "HLine");

			if (i >= 1920)
			{
				m_Check = true;
			}
		}

	}

}

void MainScene::Render()
{
}
