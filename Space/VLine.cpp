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

	}
}
