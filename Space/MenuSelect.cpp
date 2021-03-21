#include "stdafx.h"
#include "MenuSelect.h"
#include"MainScene.h"
#include"Intro.h"
#include"Ranking.h"

MenuSelect::MenuSelect(int v)
{
	m_V = v;
	if (v == 1)
	{
		m_Select = Sprite::Create(L"Painting/GameStart.png");
		m_Select->SetParent(this);
		SetPosition(300, 100);
	}
	else if (v == 2)
	{
		m_Select = Sprite::Create(L"Painting/IntroDuce.png");
		m_Select->SetParent(this);
		SetPosition(300, 300);
	}
	else if (v == 3)
	{
		m_Select = Sprite::Create(L"Painting/Explain.png");
		m_Select->SetParent(this);
		SetPosition(300, 500);
	}
	else if (v == 4)
	{
		m_Select = Sprite::Create(L"Painting/Ranking.png");
		m_Select->SetParent(this);
		SetPosition(300, 700);
	}
	else if (v == 5)
	{
		m_Select = Sprite::Create(L"Painting/Back.png");
		m_Select->SetParent(this);
		SetPosition(1920/2, 1080/2);
	}
}



void MenuSelect::Update(float deltatime, float time)
{
	if (m_V == 1 && CollisionMgr::GetInst()->MouseWithBoxSize(this) && INPUT->GetButtonDown())
	{
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new MainScene());
	}
	else if (m_V == 2 && CollisionMgr::GetInst()->MouseWithBoxSize(this) && INPUT->GetButtonDown() == true)
	{
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new Intro());
	}
	else if (m_V == 3 && CollisionMgr::GetInst()->MouseWithBoxSize(this) && INPUT->GetButtonDown() == true)
	{
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new Intro(1));
	}
	else if (m_V == 4 && CollisionMgr::GetInst()->MouseWithBoxSize(this) && INPUT->GetButtonDown() == true)
	{
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new Ranking());
	}
}

void MenuSelect::Render()
{
	m_Select->Render();
}

void MenuSelect::Release()
{
}

void MenuSelect::OnCollision(Object* obj, std::string tag)
{
}
