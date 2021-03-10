#pragma once
class MainScene : public Scene
{
public:
	Sprite* m_Sprite;

	MainScene();
	~MainScene();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();

public:

	bool m_Check;

};

