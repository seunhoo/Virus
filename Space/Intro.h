#pragma once
class Intro : public Scene , public Object
{
public:

	Sprite* m_Sprite;

	float m_NextTime;

	Intro();
	Intro(int v);

	int m_V;

	float m_Delay;

	void Init();
	void Update(float deltatime, float time);
	void Render();
	void Release();
};

