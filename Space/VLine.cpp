#include "stdafx.h"
#include "VLine.h"

VLine::VLine(float posx, float posy)
{
	m_VLine = Sprite::Create(L"Painting/VLine1.png");
	m_VLine->SetParent(this);
	SetPosition(posx, posy);
}

void VLine::Update(float deltatime, float time)
{
	//printf("%f %f \n", m_Position.x, m_Position.y);
	ObjMgr->CollisionCheak(this, "Player");
}

void VLine::Render()
{
	m_VLine->Render();
}

void VLine::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
		m_VLine->A--;
		m_VLine->R = 0;
		m_VLine->G = 0;
		m_VLine->B = 0;
	}
}
