#pragma once
class Random : public Object
{
public:

	Sprite* m_Random;

	Random(float posx, float posy);

	void Update(float deltatime, float time);
	void Render();

	void OnCollision(Object* obj, std::string tag);
};

