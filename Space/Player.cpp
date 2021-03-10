#include "stdafx.h"
#include "Player.h"
#include"Line.h"
Player::Player()
	:m_UpCheck(true)
	,m_RightCheck(true)
	,m_LeftCheck(true)
	,m_DownCheck(true)
	,m_PlayerHp(5)
{

	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);
	int randomx = rand() % 2 + 1;
	int randomy = rand() % 2 + 1;
	int randomX, randomY;
	if (randomx == 1)
	{
		 randomX = rand() % 1920 + 0;
		 randomY = 0;

		 if (randomX % 10 != 0)
		 {
			 for (; randomX % 10 != 0;)
			 {
				 randomX--;
			 }
		 }
	}
	else
	{
		randomX = rand() % 1920 + 0;
		randomY = 1080;

		if (randomX % 10 != 0)
		{
			for (; randomX % 10 != 0;)
			{
				randomX--;
			}
		}
	}
	if (randomy == 1)
	{
		randomX = 0;
		randomY = rand() % 1080 + 0;

		if (randomY % 10 != 0)
		{
			for (; randomY % 10 != 0;)
			{
				randomY--;
			}
		}
	}
	else
	{
		randomX = 1920;
		randomY = rand() % 1080 + 0;

		if (randomY % 10 != 0) 
		{
			for (; randomY % 10 != 0;)
			{
				randomY--;
			}
		}


	}
	m_Layer = 100;
	SetPosition(randomX, randomY);

	m_Text = new TextMgr();
	m_Text->Init(45,"±¼¸²Ã¼");
	m_Text->SetColor(255, 255, 0, 0);
}

void Player::Update(float deltatime, float time)
{
	if ((int)m_Position.x % 120 == 60)
	{
		ObjMgr->AddObject(new Line(1, m_Position.x, m_Position.y), "Line");
	}
	else if ((int)m_Position.y % 90 == 40)
	{
		ObjMgr->AddObject(new Line(0, m_Position.x, m_Position.y+5), "Line");
	}


	ObjMgr->CollisionCheak(this, "VLine");
	ObjMgr->CollisionCheak(this, "HLine");

	if (INPUT->GetKey(VK_UP) == KeyState::PRESS && m_UpCheck == true && (int)m_Position.x % 120 == 0)
	{
		if (m_Position.y >= 10)
		{
			//ObjMgr->AddObject(new Line(0,m_Position.x,m_Position.y), "Line");
 			m_Position.y -= 10;
		}
	}

	if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS && m_DownCheck == true && (int)m_Position.x % 120 == 0)
	{
		if (m_Position.y <= 1070)
		{
			//ObjMgr->AddObject(new Line(0, m_Position.x, m_Position.y), "Line");
			m_Position.y += 10;
		}
	}

	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS && m_LeftCheck == true && (int)m_Position.y % 90 == 0)
	{
		if (m_Position.x >= 9)
		{
			//ObjMgr->AddObject(new Line(1, m_Position.x, m_Position.y), "Line");
			m_Position.x -= 10;
		}
	}

	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS && m_RightCheck == true && (int)m_Position.y % 90 == 0)
	{
		if (m_Position.x <= 1910)
		{
			//ObjMgr->AddObject(new Line(1, m_Position.x , m_Position.y), "Line");
			m_Position.x += 10;
		}

	}
}

void Player::Render()
{
	m_Player->Render();

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("HP : " + std::to_string(m_PlayerHp), 1700, 30);
	m_Text->print("Score : " + std::to_string(ScoreMgr::GetInst()->GetScore()), 1920 / 2 - 100, 30);
	Renderer::GetInst()->GetSprite()->End();
}

void Player::OnCollision(Object* obj, std::string tag)
{
	
}
