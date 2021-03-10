#include "stdafx.h"
#include "Monster.h"

Monster::Monster(int Version)
	:m_BossCheck(false)
	,m_MoveCheck(false)
	,m_MoveCount(0)
	,x(0),y(0),t(0)
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

		int randomx = rand() % 1900 + 10;
		int randomy = rand() % 1070 + 10;

		SetPosition(randomx, randomy);

		m_BossCheck = false;
	}
	else if (Version == 4)
	{
		m_Monster = Sprite::Create(L"Painting/Boss.png");
		m_Monster->SetParent(this);

		int randomx = rand() % 1900 + 10;
		int randomy = rand() % 1070 + 10;

		SetPosition(randomx, randomy);
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
	m_Speed = 150.f;
}

void Monster::Move()
{
	if (m_Version == 1)
	{
		m_Speed = 10.f;

		if (m_MoveCheck == false)
		{
			m_MoveCount += dt;

			if (m_MoveCount >= 1)
			{
				t = rand() % 2 + 1;
				
				if (t == 1)
				{
					x = rand() % 2 + 1;
				}
				else if (t == 2)
				{
					y = rand() % 2 + 1;
				}
				m_MoveCheck = true;
			}
		}
		else if (m_MoveCheck == true)
		{
			m_ResetCount += dt;
			if (m_ResetCount >= 0.5)
			{
				t = 0;
				x = 0; 
				y = 0;
				m_MoveCount = 0;
				m_MoveCheck = false;
				m_ResetCount = 0;
			}
			if (x == 1)
			{
				if(m_Position.x > 70)
					m_Position.x -= m_Speed;
			}
			else if (x == 2)
			{
				if (m_Position.x < 1850)
					m_Position.x += m_Speed;
			}
			if (y == 1)
			{
				if (m_Position.y > 70)
					m_Position.y -= m_Speed;
			}
			else if (y == 2)
			{
				if (m_Position.y < 1010)
					m_Position.y += m_Speed;
			}
		
		}


	}
	else if (m_Version == 2)
	{
		m_Speed = 5.f;

		if (m_MoveCheck == false)
		{
			m_MoveCount += dt;

			if (m_MoveCount >= 1.5)
			{
				t = rand() % 2 + 1;

				if (t == 1)
				{
					x = rand() % 2 + 1;
				}
				else if (t == 2)
				{
					y = rand() % 2 + 1;
				}
				m_MoveCheck = true;
			}
		}
		else if (m_MoveCheck == true)
		{
			m_ResetCount += dt;
			if (m_ResetCount >= 0.7)
			{
				t = 0;
				x = 0;
				y = 0;
				m_MoveCount = 0;
				m_MoveCheck = false;
				m_ResetCount = 0;
			}
			if (x == 1)
			{
				if (m_Position.x > 70)
					m_Position.x -= m_Speed;
			}
			else if (x == 2)
			{
				if (m_Position.x < 1850)
					m_Position.x += m_Speed;
			}
			if (y == 1)
			{
				if (m_Position.y > 70)
					m_Position.y -= m_Speed;
			}
			else if (y == 2)
			{
				if (m_Position.y < 1010)
					m_Position.y += m_Speed;
			}

		}
	}
	else if (m_Version == 3)
	{
		m_Speed = 50.f;

		if (m_MoveCheck == false)
		{
			m_MoveCount += dt;

			if (m_MoveCount >= 3)
			{
				t = rand() % 2 + 1;

				if (t == 1)
				{
					x = rand() % 2 + 1;
				}
				else if (t == 2)
				{
					y = rand() % 2 + 1;
				}
				m_MoveCheck = true;
			}
		}
		else if (m_MoveCheck == true)
		{
			m_ResetCount += dt;
			if (m_ResetCount >= 0.066)
			{
				t = 0;
				x = 0;
				y = 0;
				m_MoveCount = 0;
				m_MoveCheck = false;
				m_ResetCount = 0;
			}
			if (x == 1)
			{
				if (m_Position.x > 100)
					m_Position.x -= m_Speed;
			}
			else if (x == 2)
			{
				if (m_Position.x < 18100)
					m_Position.x += m_Speed;
			}
			if (y == 1)
			{
				if (m_Position.y > 100)
					m_Position.y -= m_Speed;
			}
			else if (y == 2)
			{
				if (m_Position.y < 980)
					m_Position.y += m_Speed;
			}

		}
	}
}

void Monster::Render()
{
	m_Monster->Render();
}

void Monster::OnCollision(Object* obj, std::string tag)
{
}
