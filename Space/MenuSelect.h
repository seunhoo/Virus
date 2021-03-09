#pragma once
class MenuSelect : public Object
{
public:

	Sprite* m_Select;


	int m_V;

	MenuSelect(int v);

	int m_Delay;


	void Update(float deltatime, float time);
	void Render();
	void Release();
	void OnCollision(Object* obj, std::string tag);
};

