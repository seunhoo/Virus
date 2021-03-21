#pragma once
class Ranking : public Scene
{
	Sprite* m_BG;
	Sprite* m_Rank;
	Sprite* m_Back;

	TextMgr* m_First;
	TextMgr* m_Secend;
	TextMgr* m_Third;
public:
	Ranking();
	~Ranking();

	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
};

