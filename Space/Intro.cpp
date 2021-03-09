#include "stdafx.h"
#include "Intro.h"
#include"MainScene.h"
#include"MenuSelect.h"
#include"MenuScene.h"
Intro::Intro()
{
}

Intro::Intro(int v)
{
	m_V = v;
}

void Intro::Init()
{
	if (m_V == 1)
	{
		m_Sprite = Sprite::Create(L"Painting/ExplainScene.png");
		m_Sprite->SetParent(this);

		SetPosition(1920 / 2, 1080 / 2);
	}
	else
	{
	m_Sprite = Sprite::Create(L"Painting/Intro.png");
	m_Sprite->SetParent(this);

	SetPosition(1920 / 2, 1080 / 2);
	}
}

void Intro::Update(float deltatime, float time)
{
	m_Delay += dt;

	if (m_V == 1)
	{
		
		if ((CollisionMgr::GetInst()->MouseWithBoxSize(this) && INPUT->GetButtonDown() == true) && m_Delay >= 1)
		{
			ObjMgr->Release();
			SceneDirector::GetInst()->ChangeScene(new MenuScene());
		}
	}
	else
	{
		m_NextTime += dt;
		m_Rotation += 30;

		if (m_NextTime >= 3)
		{
			ObjMgr->RemoveObject(this);
			SceneDirector::GetInst()->ChangeScene(new MenuScene());
		}
	}



}

void Intro::Render()
{
	m_Sprite->Render();
}

void Intro::Release()
{
}
