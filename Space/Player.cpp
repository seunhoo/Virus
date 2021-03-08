#include "stdafx.h"
#include "Player.h"

Player::Player()
	:m_UpCheck(true)
	,m_RightCheck(true)
	,m_LeftCheck(true)
	,m_DownCheck(true)
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
	SetPosition(randomX, randomY);
}

void Player::Update(float deltatime, float time)
{
	ObjMgr->CollisionCheak(this, "VLine");
	ObjMgr->CollisionCheak(this, "HLine");
	if (INPUT->GetKey(VK_UP) == KeyState::PRESS && m_UpCheck == true && (int)m_Position.x % 120 == 0)
	{
		if(m_Position.y >=10)
 			m_Position.y -= 10;
	}

	if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS && m_DownCheck == true && (int)m_Position.x % 120 == 0)
	{
		if (m_Position.y <= 1070)
			m_Position.y += 10;
	}

	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS && m_LeftCheck == true && (int)m_Position.y % 90 == 0)
	{
		if (m_Position.x >= 10)
			m_Position.x -= 10;
	}

	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS && m_RightCheck == true && (int)m_Position.y % 90 == 0)
	{
		if (m_Position.x <= 1910)
			m_Position.x += 10;
	}


	//if ((m_Position.x / 50) * 50 < 0 && (m_Position.y / 50) * 50 < 0)
	//{
	//	SetPosition((int)(m_Position.x / 50) * 50 - 50, (int)(m_Position.y / 50) * 50 - 50);
	//}
	//else if ((m_Position.x / 50) * 50 < 0)
	//{
	//	SetPosition((int)(m_Position.x / 50) * 50 - 50, (int)(m_Position.y / 50) * 50);
	//}
	//else if ((m_Position.y / 50) * 50 < 0)
	//{
	//	SetPosition((int)(m_Position.x / 50) * 50, (int)(m_Position.y / 50) * 50 - 50);
	//}
	//else
	//{
	//	SetPosition((int)(m_Position.x / 50) * 50, (int)(m_Position.y / 50) * 50);
	//}

}

void Player::Render()
{
	m_Player->Render();
}

void Player::OnCollision(Object* obj, std::string tag)
{
	//if (tag == "VLine")
	//{
	//	m_UpCheck = true;
	//	m_DownCheck = true;
	//}
	//else
	//{
	//	m_UpCheck = false;
	//	m_DownCheck = false;
	//}
	//if (tag == "HLine")
	//{
	//	m_RightCheck = true;
	//	m_LeftCheck = true;
	//}
	//else
	//{
	//	m_RightCheck = false;
	//	m_LeftCheck = false;
	//}
}
