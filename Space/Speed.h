#pragma once
class Speed : public Object
{
public:

	Sprite* m_Speed;

	Speed(float posx, float posy);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

