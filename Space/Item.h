#pragma once
class Item : public Object
{
public:

	Sprite* m_Item;

	int m_V;

	Item(int v,float posx, float posy);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

