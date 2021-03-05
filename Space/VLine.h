#pragma once
class VLine : public Object
{
public:
	Sprite* m_VLine;

	VLine(float posx, float posy);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

