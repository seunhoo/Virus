#pragma once
class Obstacle : public Object
{
public:

	Sprite* m_Obstacle;

	Obstacle();

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

