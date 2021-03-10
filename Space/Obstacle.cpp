#include "stdafx.h"
#include "Obstacle.h"

Obstacle::Obstacle()
{
	int randomx = rand() % 12 + 1;
	int randomy = rand() %  9 + 1;

	m_Obstacle = Sprite::Create(L"Painting/Lung.png");
	m_Obstacle->SetParent(this);
	SetPosition(randomx * 120, randomy * 90);
}

void Obstacle::Update(float deltatime, float time)
{
	printf("%f %f \n", m_Position.x, m_Position.y);
}

void Obstacle::Render()
{
	m_Obstacle->Render();
}

void Obstacle::OnCollision(Object* obj, std::string tag)
{
}
