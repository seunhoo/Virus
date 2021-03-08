#pragma once
class Heal  : public Object
{
public:

	Sprite* m_Heal;

	Heal(float posx, float posy);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

