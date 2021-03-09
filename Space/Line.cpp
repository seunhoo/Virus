#include "stdafx.h"
#include "Line.h"

Line::Line(bool vh, float posx,float posy)
{
	if (vh == true)
		m_Line = Sprite::Create(L"Painting/line.png");
	else
		m_Line = Sprite::Create(L"Painting/line2.png");

	m_Line->SetParent(this);

	
	SetPosition(posx, posy);

	m_Line->m_Layer = 0;

}

void Line::Update(float deltatime, float time)
{
	printf("%d \n", m_Line->m_Layer);
}

void Line::Render()
{
	m_Line->Render();
}

void Line::OnCollision(Object* obj, std::string tag)
{
}
