#pragma once
class Defence : public Object
{
public:

	Sprite* m_Defence;

	Defence(float posx,float posy);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

