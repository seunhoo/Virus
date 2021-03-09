#include "stdafx.h"
#include "Monster.h"

Monster::Monster(int Version)
	:m_BossCheck(false)
{
	m_Version = Version;
	if (Version == 1)
	{
		m_Monster = Sprite::Create(L"Painting/SpeedMonster.png");
		m_Monster->SetParent(this);

		int randomx = rand() % 1900 + 10;
		int randomy = rand() % 1070 + 10;

		SetPosition(randomx, randomy);

		m_BossCheck = false;
	}
	else if (Version == 2)
	{
		m_Monster = Sprite::Create(L"Painting/BigMonster.png");
		m_Monster->SetParent(this);

		int randomx = rand() % 1900 + 10;
		int randomy = rand() % 1070 + 10;

		SetPosition(randomx, randomy);

		m_BossCheck = false;
	}
	else if (Version == 3)
	{
		m_Monster = Sprite::Create(L"Painting/FlashMonster.png");
		m_Monster->SetParent(this);

		m_BossCheck = false;
	}
	else if (Version == 4)
	{
		m_BossCheck = true;
	}
	
}

void Monster::Update(float deltatime, float time)
{
	if (m_BossCheck == true)
	{
		Boss();
	}
	else
	{
		Move();
	}
}

void Monster::Boss()
{
	m_Speed = 30.f;
}

void Monster::Move()
{
	if (m_Version == 1)
	{
		m_Speed = 20.f;

		m_MoveCount += dt;

		if (m_MoveCount >= 1 )
		{
			int r = rand() % 2 + 1;
			if (r == 1)
			{
				int x = rand() % 2 + 1;

				if (x == 1)
				{
					m_Position.x += m_Speed;
					m_ResetCount += dt;
					if (m_ResetCount >= 2)
					{
						m_ResetCount = 0;
						m_MoveCount = 0;
					}
				}
				else
				{
					m_Position.x -= m_Speed;
					m_ResetCount += dt;
					if (m_ResetCount >= 2)
					{
						m_ResetCount = 0;
						m_MoveCount = 0;
					}

				}
			}
			else
			{
				int y = rand() % 2 + 1;

				if (y == 1)
				{
					m_Position.y += m_Speed;
					m_ResetCount += dt;
					if (m_ResetCount >= 2)
					{
						m_ResetCount = 0;
						m_MoveCount = 0;
					}

				}
				else
				{
					m_Position.y -= m_Speed;
					m_ResetCount += dt;
					if (m_ResetCount >= 2)
					{
						m_ResetCount = 0;
						m_MoveCount = 0;
					}

				}
			}

			
			
		}


	}
	else if (m_Version == 2)
	{
		m_Speed = 5.f;
	}
	else if (m_Version == 3)
	{
		m_Speed = 10.f;
	}
}

void Monster::Render()
{
	m_Monster->Render();
}

void Monster::OnCollision(Object* obj, std::string tag)
{
}
