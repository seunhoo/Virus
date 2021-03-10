#pragma once
class GameMgr : public Singleton<GameMgr>
{
public:

	float m_Pos;

	GameMgr();

	void Update(float deltatime, float time);

	void GetFirstPos(float posx, float posy);
	void GetPosition(float pos);
	void MakeSquare();
	void Render();

};

