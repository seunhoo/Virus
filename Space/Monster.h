#pragma once
class Monster : public Object
{
public:

	Sprite* m_Monster;

	Monster(int version);
	int m_Version;
	
	float m_Speed;
	float m_MoveCount;
	float m_ResetCount;

	bool m_MoveCheck;
	bool m_BossCheck;

	void Update(float deltatime, float time);
	void Boss();
	void Move();
	void Render();
	
	void OnCollision(Object* obj, std::string tag);
};

