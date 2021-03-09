#pragma once
class Player : public Object
{
public:

	Sprite* m_Player;
	TextMgr* m_Text;
public:

	int m_PlayerHp;

	bool m_UpCheck;
	bool m_RightCheck;
	bool m_LeftCheck;
	bool m_DownCheck;

	Player();

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

