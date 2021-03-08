#include "stdafx.h"
#include "Heal.h"

Heal::Heal(float posx, float posy)
{
	m_Heal = Sprite::Create(L"Painting/Heal.png");
	m_Heal->SetParent(this);

	SetPosition(posx, posy);
}

void Heal::Update(float deltatime, float time)
{
}

void Heal::Render()
{
	m_Heal->Render();
}

void Heal::OnCollision(Object* obj, std::string tag)
{
}
