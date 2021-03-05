#include "stdafx.h"
#include "HLine.h"

HLine::HLine(float posx, float posy)
{
	m_HLine = Sprite::Create(L"Painting/HLine1.png");
	m_HLine->SetParent(this);

	SetPosition(posx, posy);
}

void HLine::Update(float deltatime, float time)
{
}

void HLine::Render()
{
	m_HLine->Render();
}

void HLine::OnCollision(Object* obj, std::string tag)
{
}
