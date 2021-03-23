#include "stdafx.h"
#include "Monster.h"
#include"Player.h"
Monster::Monster(int Version)
	:m_BossCheck(false)
	,m_MoveCheck(false)
	,m_MoveCount(0)
	,x(0),y(0),t(0)
	,m_CollideCheck(false)
	,m_CollideTime(0)
	,dist(30)
	,disk(30)
	,disc(30)
	,didr(30)
{
	srand(time(NULL));
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

	m_bPlayer = new Player();
	
	
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

	if (m_CollideCheck == true)
	{
		m_CollideTime += dt;

		if (m_CollideTime >= 3)
		{
			m_CollideTime = 0;
			m_CollideCheck = false;
		}
	}



	if (m_bPlayer->i >=1 && m_bPlayer->m_Length >=2 && (
		(dist == 0 && disk == 0) ||
		(dist == 0 && disc == 0) ||
		(dist == 0 && didr == 0) ||
		(disc == 0 && didr == 0) ||
		(disc == 0 && disk == 0) ||
		(disk == 0 && didr == 0)))
	{
		int x1 = m_bPlayer->m_PlayerPos[0].x < m_bPlayer->m_PlayerPos[1].x ? m_bPlayer->m_PlayerPos[0].x : m_bPlayer->m_PlayerPos[1].x;
		int y1 = m_bPlayer->m_PlayerPos[0].y < m_bPlayer->m_PlayerPos[1].y ? m_bPlayer->m_PlayerPos[0].y : m_bPlayer->m_PlayerPos[1].y;
		int x2 = m_bPlayer->m_PlayerPos[0].x > m_bPlayer->m_PlayerPos[1].x ? m_bPlayer->m_PlayerPos[0].x : m_bPlayer->m_PlayerPos[1].x;
		int y2 = m_bPlayer->m_PlayerPos[0].y > m_bPlayer->m_PlayerPos[1].y ? m_bPlayer->m_PlayerPos[0].y : m_bPlayer->m_PlayerPos[1].y;

		int x3 = m_bPlayer->m_PlayerPos[1].x < m_bPlayer->m_PlayerPos[2].x ? m_bPlayer->m_PlayerPos[1].x : m_bPlayer->m_PlayerPos[2].x;
		int y3 = m_bPlayer->m_PlayerPos[1].y < m_bPlayer->m_PlayerPos[2].y ? m_bPlayer->m_PlayerPos[1].y : m_bPlayer->m_PlayerPos[2].y;
		int x4 = m_bPlayer->m_PlayerPos[1].x > m_bPlayer->m_PlayerPos[2].x ? m_bPlayer->m_PlayerPos[1].x : m_bPlayer->m_PlayerPos[2].x;
		int y4 = m_bPlayer->m_PlayerPos[1].y > m_bPlayer->m_PlayerPos[2].y ? m_bPlayer->m_PlayerPos[1].y : m_bPlayer->m_PlayerPos[2].y;

		int x5 = m_bPlayer->m_PlayerPos[2].x < m_bPlayer->m_PlayerPos[3].x ? m_bPlayer->m_PlayerPos[2].x : m_bPlayer->m_PlayerPos[3].x;
		int y5 = m_bPlayer->m_PlayerPos[2].y < m_bPlayer->m_PlayerPos[3].y ? m_bPlayer->m_PlayerPos[2].y : m_bPlayer->m_PlayerPos[3].y;
		int x6 = m_bPlayer->m_PlayerPos[2].x > m_bPlayer->m_PlayerPos[3].x ? m_bPlayer->m_PlayerPos[2].x : m_bPlayer->m_PlayerPos[3].x;
		int y6 = m_bPlayer->m_PlayerPos[2].y > m_bPlayer->m_PlayerPos[3].y ? m_bPlayer->m_PlayerPos[2].y : m_bPlayer->m_PlayerPos[3].y;

		int x7 = m_bPlayer->m_PlayerPos[3].x < m_bPlayer->m_PlayerPos[4].x ? m_bPlayer->m_PlayerPos[3].x : m_bPlayer->m_PlayerPos[4].x;
		int y7 = m_bPlayer->m_PlayerPos[3].y < m_bPlayer->m_PlayerPos[4].y ? m_bPlayer->m_PlayerPos[3].y : m_bPlayer->m_PlayerPos[4].y;
		int x8 = m_bPlayer->m_PlayerPos[3].x > m_bPlayer->m_PlayerPos[4].x ? m_bPlayer->m_PlayerPos[3].x : m_bPlayer->m_PlayerPos[4].x;
		int y8 = m_bPlayer->m_PlayerPos[3].y > m_bPlayer->m_PlayerPos[4].y ? m_bPlayer->m_PlayerPos[3].y : m_bPlayer->m_PlayerPos[4].y;

		if (dist < 10 && m_Position.x >= x1 - 10 && m_Position.x <= x2 + 10 && m_Position.y >= y1 - 10 && m_Position.y <= y2 + 10)
		{
			if (m_CollideCheck == false)
			{
				m_bPlayer->m_PlayerHp -= 1;
			}
			m_CollideCheck = true;
		}
		else if (disc < 10 && m_Position.x >= x3 - 10 && m_Position.x <= x4 + 01 && m_Position.y >= y3 -10 && m_Position.y <= y4 + 9)
		{
			if (m_CollideCheck == false)
			{
				m_bPlayer->m_PlayerHp -= 1;
			}
			m_CollideCheck = true;
		}
		else if (disk < 10 && m_Position.x >= x5 - 10 && m_Position.x <= x6 + 10 && m_Position.y >= y5 - 10 && m_Position.y <= y6 + 9)
		{
			if (m_CollideCheck == false)
			{
				m_bPlayer->m_PlayerHp -= 1;
			}
			m_CollideCheck = true;
		}
		else if (didr < 10 && m_Position.x >= x7 - 10 && m_Position.x <= x8 + 10 && m_Position.y >= y7 - 10 && m_Position.y <= y8 + 9)
		{
			if (m_CollideCheck == false)
			{
				m_bPlayer->m_PlayerHp -= 1;
			}
			m_CollideCheck = true;
		}
		else
		{
			m_CollideCheck = false;
		}
	}
	a = m_bPlayer->m_PlayerPos[0].y - m_bPlayer->m_PlayerPos[1].y;
	b = m_bPlayer->m_PlayerPos[1].x - m_bPlayer->m_PlayerPos[0].x;
	c = m_bPlayer->m_PlayerPos[0].x * m_bPlayer->m_PlayerPos[1].y - m_bPlayer->m_PlayerPos[1].x * m_bPlayer->m_PlayerPos[0].y;
	dist = (float)std::abs(a * m_Position.x + b * m_Position.y + c) / (float)std::sqrt(a * a + b * b);

	d = m_bPlayer->m_PlayerPos[1].y - m_bPlayer->m_PlayerPos[2].y;
	e = m_bPlayer->m_PlayerPos[2].x - m_bPlayer->m_PlayerPos[1].x;
	f = m_bPlayer->m_PlayerPos[1].x * m_bPlayer->m_PlayerPos[2].y - m_bPlayer->m_PlayerPos[2].x * m_bPlayer->m_PlayerPos[1].y;
	disk = (float)std::abs(d * m_Position.x + e * m_Position.y + f) / (float)std::sqrt(d * d + e * e);

	g = m_bPlayer->m_PlayerPos[2].y - m_bPlayer->m_PlayerPos[3].y;
	h = m_bPlayer->m_PlayerPos[3].x - m_bPlayer->m_PlayerPos[2].x;
	j = m_bPlayer->m_PlayerPos[2].x * m_bPlayer->m_PlayerPos[3].y - m_bPlayer->m_PlayerPos[3].x * m_bPlayer->m_PlayerPos[2].y;
	disc = (float)std::abs(g * m_Position.x + h * m_Position.y + j) / (float)std::sqrt(g * g + h * h);

	k = m_bPlayer->m_PlayerPos[3].y - m_bPlayer->m_PlayerPos[4].y;
	l = m_bPlayer->m_PlayerPos[4].x - m_bPlayer->m_PlayerPos[3].x;
	m = m_bPlayer->m_PlayerPos[3].x * m_bPlayer->m_PlayerPos[4].y - m_bPlayer->m_PlayerPos[4].x * m_bPlayer->m_PlayerPos[3].y;
	didr = (float)std::abs(k * m_Position.x + l * m_Position.y + m) / (float)std::sqrt(k * k + l * l);


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
