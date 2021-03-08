#include "stdafx.h"
#include "Defence.h"

Defence::Defence(float posx, float posy)
{
	m_Defence = Sprite::Create(L"Painting/Defence.png");
	m_Defence->SetParent(this);
	SetPosition(posx, posy);
}

void Defence::Update(float deltatime, float time)
{
}

void Defence::Render()
{
	m_Defence->Render();
}

void Defence::OnCollision(Object* obj, std::string tag)
{
}
