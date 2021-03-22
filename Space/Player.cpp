#include "stdafx.h"
#include "Player.h"
#include"Line.h"
#include"MenuSelect.h"
#include"MainScene.h"
#include"MenuScene.h"
#include"StageTwo.h"
#include"Item.h"
#include"LineMgr.h"
#include"Square.h"
Player::Player()
	:m_PlayerHp(5)
	,m_PlayerSpeed(10)
{
	srand(time(NULL));
	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);
	int randomx = (rand() % 2) + 1;
	int randomy = (rand() % 2) + 1;
	int randomX = 0, randomY = 0;

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
	else if (randomx == 2)
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
	else if (randomy == 2)
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
	printf("%d %d %d %d \n", randomx, randomy, randomX, randomY);
	m_Layer = 100;

	SetPosition(randomX,randomY);

	m_Line = new LineMgr();
	m_Line->Init(3, 1);
	m_Line->SetColor(D3DCOLOR_ARGB(255, 255, 0, 0));
	memset(m_PlayerPos, 0, sizeof(m_PlayerPos));
	m_PlayerPos[0].x = randomX;
	m_PlayerPos[0].y = randomY;

	m_Length++;

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



	ObjMgr->CollisionCheak(this, "VLine");
	ObjMgr->CollisionCheak(this, "HLine");

	if (INPUT->GetKey(VK_UP) == KeyState::PRESS)
	{
		m_PlayerPos[i] = m_Position;
		if (m_State != MoveState::UP && m_State != MoveState::DOWN)
		{
			m_PlayerPos[i] = m_Position;
			m_Length++;
			m_Move = 1;
			m_State = MoveState::UP;
			i++;
		}
		if (m_Position.y >= 10)
		{
			m_Position.y -= 10;

		}
	}

	else if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS)
	{
		m_PlayerPos[i] = m_Position;
		if (m_State != MoveState::UP && m_State != MoveState::DOWN)
		{
			m_PlayerPos[i] = m_Position;
			m_Length++;
			m_Move = 2;

			m_State = MoveState::DOWN;
			i++;
		}

		if (m_Position.y <= 1070)
		{
			m_Position.y += 10;

		}
	}

	else if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS)
	{
		m_PlayerPos[i] = m_Position;
		if (m_State != MoveState::RIGHT && m_State != MoveState::LEFT)
		{
			m_PlayerPos[i] = m_Position;
			m_Length++;
			m_Move = 3;

			m_State = MoveState::LEFT;
			i++;
		}
		if (m_Position.x >= 9)
		{
			m_Position.x -= 10;

		}
	}

	else if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS)
	{
		m_PlayerPos[i] = m_Position;
		if (m_State != MoveState::RIGHT && m_State != MoveState::LEFT)
		{
			m_PlayerPos[i] = m_Position;
			m_Length++;
			m_Move = 4;

			m_State = MoveState::RIGHT;
			i++;
		}
		if (m_Position.x <= 1910)
		{
			m_Position.x += 10;

		}

	}

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

	if (i >= 4 && m_Length >= 5 && (
		(dist == 0 && disk == 0) ||
		(dist == 0 && disc == 0) ||
		(dist == 0 && didr == 0) ||
		(disc == 0 && didr == 0) ||
		(disc == 0 && disk == 0) ||
		(disk == 0 && didr == 0)))
	{
		int x1 = m_PlayerPos[0].x < m_PlayerPos[1].x ? m_PlayerPos[0].x : m_PlayerPos[1].x;
		int y1 = m_PlayerPos[0].y < m_PlayerPos[1].y ? m_PlayerPos[0].y : m_PlayerPos[1].y;
		int x2 = m_PlayerPos[0].x > m_PlayerPos[1].x ? m_PlayerPos[0].x : m_PlayerPos[1].x;
		int y2 = m_PlayerPos[0].y > m_PlayerPos[1].y ? m_PlayerPos[0].y : m_PlayerPos[1].y;

		int x3 = m_PlayerPos[1].x < m_PlayerPos[2].x ? m_PlayerPos[1].x : m_PlayerPos[2].x;
		int y3 = m_PlayerPos[1].y < m_PlayerPos[2].y ? m_PlayerPos[1].y : m_PlayerPos[2].y;
		int x4 = m_PlayerPos[1].x > m_PlayerPos[2].x ? m_PlayerPos[1].x : m_PlayerPos[2].x;
		int y4 = m_PlayerPos[1].y > m_PlayerPos[2].y ? m_PlayerPos[1].y : m_PlayerPos[2].y;

		int x5 = m_PlayerPos[2].x < m_PlayerPos[3].x ? m_PlayerPos[2].x : m_PlayerPos[3].x;
		int y5 = m_PlayerPos[2].y < m_PlayerPos[3].y ? m_PlayerPos[2].y : m_PlayerPos[3].y;
		int x6 = m_PlayerPos[2].x > m_PlayerPos[3].x ? m_PlayerPos[2].x : m_PlayerPos[3].x;
		int y6 = m_PlayerPos[2].y > m_PlayerPos[3].y ? m_PlayerPos[2].y : m_PlayerPos[3].y;

		int x7 = m_PlayerPos[3].x < m_PlayerPos[4].x ? m_PlayerPos[3].x : m_PlayerPos[4].x;
		int y7 = m_PlayerPos[3].y < m_PlayerPos[4].y ? m_PlayerPos[3].y : m_PlayerPos[4].y;
		int x8 = m_PlayerPos[3].x > m_PlayerPos[4].x ? m_PlayerPos[3].x : m_PlayerPos[4].x;
		int y8 = m_PlayerPos[3].y > m_PlayerPos[4].y ? m_PlayerPos[3].y : m_PlayerPos[4].y;

		if (dist < 10 && m_Position.x >= x1 - 10 && m_Position.x <= x2 + 10 && m_Position.y >= y1 - 10 && m_Position.y <= y2 + 10)
		{
			m_PlayerPos[0] = m_PlayerPos[4];
			m_Square = true;
		}
		else if (disc < 5 && m_Position.x >= x3 - 5 && m_Position.x <= x4 + 5 && m_Position.y >= y3 - 5 && m_Position.y <= y4 + 5)
		{
			m_PlayerPos[0] = m_PlayerPos[4];
			m_Square = true;
		}
		else if (disk < 5 && m_Position.x >= x5 - 5 && m_Position.x <= x6 + 5 && m_Position.y >= y5 - 5 && m_Position.y <= y6 + 5)
		{
			m_PlayerPos[0] = m_PlayerPos[4];
			m_Square = true;
		}
		else if (didr < 5 && m_Position.x >= x7 - 5 && m_Position.x <= x8 + 5 && m_Position.y >= y7 - 5 && m_Position.y <= y8 + 5)
		{
			m_PlayerPos[0] = m_PlayerPos[4];
			m_Square = true;
		}
		else
		{
			m_Square = false;
		}
	}


	a = m_PlayerPos[0].y - m_PlayerPos[1].y;
	b = m_PlayerPos[1].x - m_PlayerPos[0].x;
	c = m_PlayerPos[0].x * m_PlayerPos[1].y - m_PlayerPos[1].x * m_PlayerPos[0].y;
	dist = (float)std::abs(a * m_Position.x + b * m_Position.y + c) / (float)std::sqrt(a * a + b * b);

	d = m_PlayerPos[1].y - m_PlayerPos[2].y;
	e = m_PlayerPos[2].x - m_PlayerPos[1].x;
	f = m_PlayerPos[1].x * m_PlayerPos[2].y - m_PlayerPos[2].x * m_PlayerPos[1].y;
	disk = (float)std::abs(d * m_Position.x + e * m_Position.y + f) / (float)std::sqrt(d * d + e * e);

	g = m_PlayerPos[2].y - m_PlayerPos[3].y;
	h = m_PlayerPos[3].x - m_PlayerPos[2].x;
	j = m_PlayerPos[2].x * m_PlayerPos[3].y - m_PlayerPos[3].x * m_PlayerPos[2].y;
	disc = (float)std::abs(g * m_Position.x + h * m_Position.y + j) / (float)std::sqrt(g * g + h * h);

	k = m_PlayerPos[3].y - m_PlayerPos[4].y;
	l = m_PlayerPos[4].x - m_PlayerPos[3].x;
	m = m_PlayerPos[3].x * m_PlayerPos[4].y - m_PlayerPos[4].x * m_PlayerPos[3].y;
	didr = (float)std::abs(k * m_Position.x + l * m_Position.y + m) / (float)std::sqrt(k * k + l * l);
}

void Player::Render()
{

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("HP : " + std::to_string(m_PlayerHp), 1700, 30);
	m_Text->print("Score : " + std::to_string(ScoreMgr::GetInst()->GetScore()), 1920 / 2 - 100, 30);
	Renderer::GetInst()->GetSprite()->End();
	m_Player->Render();

	m_Player->Render();
	m_Line->DrawLine(m_PlayerPos, m_Length);

	if (m_Square == true)
	{
		float posx = (m_PlayerPos[0].x + m_PlayerPos[2].x) / 2;
		float posy = (m_PlayerPos[0].y + m_PlayerPos[2].y) / 2;
		float scalex = (m_PlayerPos[2].x - m_PlayerPos[0].x) / 10;
		float scaley = (m_PlayerPos[2].y - m_PlayerPos[0].y) / 10;
		ObjMgr->AddObject(new Square(Vec2(posx, posy), Vec2(scalex, scaley)), "Square");

		i = 0;
		m_Length = 1;
		m_Square = false;
	}

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
