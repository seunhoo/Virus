#include "stdafx.h"
#include "Square.h"

Square::Square(Vec2 pos, Vec2 scale)
{
	m_pScale = scale;

	m_Square = Sprite::Create(L"Painting/square.png");
	m_Square->SetParent(this);
	SetPosition(pos);
	SetScale(scale.x, scale.y);

	float m_cScale = (std::abs(m_pScale.x) * std::abs(m_pScale.y));
	float m_pPercent = (std::abs(m_cScale) / (1920 * 1080)) * 100;
	printf("%f %f \n", m_pScale.x, m_pScale.y);
	printf("%f \n", m_cScale);
	printf("%f \n", m_pPercent);
}

void Square::Update(float deltatime, float time)
{
}

void Square::Render()
{
	m_Square->Render();

}
