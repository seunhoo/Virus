#pragma once
class HLine : public Object
{
public:
	Sprite* m_HLine;

	HLine(float posx, float posy);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

