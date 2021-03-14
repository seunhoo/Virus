#pragma once
class Item : public Object
{
public:

	Sprite* m_Item;

	int m_V;

	int m_HealCount;
	int m_RandomCount;
	int m_InvCount;
	int m_DefCount;
	int m_SpeedCount;

	Item(int v,float posx, float posy);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

