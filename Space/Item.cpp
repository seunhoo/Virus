#include "stdafx.h"
#include "Item.h"


Item::Item(int v)
{
	m_V = v;

	if (m_V == 1)
	{
		m_Item = Sprite::Create(L"Painting/Speed.png");
		m_Item->SetParent(this);
		SetPosition(1700, 150);
	}
	else if (m_V == 2)
	{
		m_Item = Sprite::Create(L"Painting/Heal.png");
		m_Item->SetParent(this);
		SetPosition(1700, 150);
	}
	else if (m_V == 3)
	{
		m_Item = Sprite::Create(L"Painting/Invincible.png");
		m_Item->SetParent(this);
		SetPosition(1700, 150);
	}
	else if (m_V == 4)
	{
		m_Item = Sprite::Create(L"Painting/Defence.png");
		m_Item->SetParent(this);
		SetPosition(1700, 150);
	}
	else if (m_V == 5)
	{
		m_Item = Sprite::Create(L"Painting/Random.png");
		m_Item->SetParent(this);
		SetPosition(1700, 150);
	}
}

void Item::Update(float deltatime, float time)
{
	if (m_V == 1)
	{

	}
	else if (m_V == 2)
	{

	}
	else if (m_V == 3)
	{
	
	}
	else if (m_V == 4)
	{

	}
	else if (m_V == 5)
	{

	}
}

void Item::Render()
{
	m_Item->Render();
}

void Item::OnCollision(Object* obj, std::string tag)
{
}
