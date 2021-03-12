#pragma once

class StageTwo : public Scene
{
public:

	bool m_Check;

	StageTwo();

	void Init();
	void Release();
	void Update(float deltatime, float time);
	void Render();
};
