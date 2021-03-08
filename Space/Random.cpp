#include "stdafx.h"
#include "Random.h"

Random::Random(float posx, float posy)
{
	m_Random = Sprite::Create(L"Painting/Random.png");
	m_Random->SetParent(this);
	SetPosition(posx, posy);
}

void Random::Update(float deltatime, float time)
{
}

void Random::Render()
{
	m_Random->Render();
}

void Random::OnCollision(Object* obj, std::string tag)
{
}
