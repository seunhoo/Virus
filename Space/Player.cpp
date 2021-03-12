#include "stdafx.h"
#include "Player.h"
#include"Line.h"
#include"MenuSelect.h"
#include"MainScene.h"
#include"MenuScene.h"
#include"StageTwo.h"
#include"Item.h"
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
	ObjMgr->CollisionCheak(this, "Random");
	ObjMgr->CollisionCheak(this, "Speed");
	ObjMgr->CollisionCheak(this, "Heal");
	ObjMgr->CollisionCheak(this, "Invincible");
	ObjMgr->CollisionCheak(this, "Defence");
	if (m_Invincible == false)
	{
		ObjMgr->CollisionCheak(this, "Monster");
		ObjMgr->CollisionCheak(this, "Boss");
	}

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
	Key();
	UseItem();
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN)
	{
		if (m_Invincible == true)
		{
			m_Invincible = false;
		}
		else if (m_Invincible == false)
		{
			m_Invincible = true;
		}
	}
	else if (INPUT->GetKey(VK_F2) == KeyState::DOWN)
	{
		int random = rand() % 5 + 1;
		if(random ==1)
			ObjMgr->AddObject(new Item(1,m_Position.x,m_Position.y), "Speed");
		else if(random == 2)
			ObjMgr->AddObject(new Item(2, m_Position.x, m_Position.y), "Heal");
		else if(random == 3)
			ObjMgr->AddObject(new Item(3, m_Position.x, m_Position.y), "Invincible");
		else if(random == 4)
			ObjMgr->AddObject(new Item(4, m_Position.x, m_Position.y), "Defence");
		else if(random == 5)
			ObjMgr->AddObject(new Item(5, m_Position.x, m_Position.y), "Random");
	}
	else if (INPUT->GetKey(VK_F3) == KeyState::DOWN)
	{
		m_PlayerHp += 1;
	}
	else if (INPUT->GetKey(VK_F4) == KeyState::DOWN)
	{
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new MenuScene());
	}
	else if (INPUT->GetKey(VK_F5) == KeyState::DOWN)
	{
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new MainScene());
	}
	else if (INPUT->GetKey(VK_F6) == KeyState::DOWN)
	{
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new StageTwo());
	}
}

void Player::Render()
{

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("HP : " + std::to_string(m_PlayerHp), 1700, 30);
	m_Text->print("Score : " + std::to_string(ScoreMgr::GetInst()->GetScore()), 1920 / 2 - 100, 30);
	Renderer::GetInst()->GetSprite()->End();
	m_Player->Render();
}

void Player::UseItem()
{
	
}

void Player::Key()
{
	
}

void Player::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Heal")
	{
		m_PlayerHp += 1;

		if (m_PlayerHp >=5)
		{
			m_PlayerHp = 5;
			ScoreMgr::GetInst()->AddScore(100);
		}
	}
	if (tag == "Random")
	{

	}
	if (tag == "Defence")
	{

	}
	if (tag == "Speed")
	{

	}
}
