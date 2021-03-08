#include "stdafx.h"
#include "Speed.h"

Speed::Speed(float posx, float posy)
{
	m_Speed = Sprite::Create(L"Painting/Speed.png");
	m_Speed->SetParent(this);

	SetPosition(posx, posy);
}

void Speed::Update(float deltatime, float time)
{
}

void Speed::Render()
{
	m_Speed->Render();
}

void Speed::OnCollision(Object* obj, std::string tag)
{
}
