#include "stdafx.h"
#include "Item.h"
#include"Player.h"

Item::Item(int v, float posx, float posy)
	:m_SpeedCount(3)
	,m_DefCount(3)
	,m_InvCount(1)
	,m_HealCount(2)
	,m_RandomCount(5)
{
	m_V = v;

	if (m_V == 1)
	{
		m_Item = Sprite::Create(L"Painting/Speed.png");
		m_Item->SetParent(this);
		SetPosition(posx, posy);
	}
	else if (m_V == 2)
	{
		m_Item = Sprite::Create(L"Painting/Heal.png");
		m_Item->SetParent(this);
		SetPosition(posx, posy);
	}
	else if (m_V == 3)
	{
		m_Item = Sprite::Create(L"Painting/Invincible.png");
		m_Item->SetParent(this);
		SetPosition(posx, posy);
	}
	else if (m_V == 4)
	{
		m_Item = Sprite::Create(L"Painting/Defence.png");
		m_Item->SetParent(this);
		SetPosition(posx, posy);
	}
	else if (m_V == 5)
	{
		m_Item = Sprite::Create(L"Painting/Random.png");
		m_Item->SetParent(this);
		SetPosition(posx, posy);
	}
}

void Item::Update(float deltatime, float time)
{
	if (m_V == 1 && m_SpeedCount > 0)
	{
		m_SpeedCount--;
		
		Player::GetInst()->m_PlayerSpeed += 10;
	}
	else if (m_V == 2 && m_HealCount >0)
	{
		m_HealCount--;
	}
	else if (m_V == 3 && m_InvCount >0)
	{
		m_InvCount--;
	}
	else if (m_V == 4 && m_DefCount >0)
	{
		m_DefCount--;
	}
	else if (m_V == 5 && m_RandomCount >0)
	{
		m_RandomCount--;
	}
}

void Item::Render()
{
	m_Item->Render();
}

void Item::OnCollision(Object* obj, std::string tag)
{
	ObjMgr->RemoveObject(this);
}
