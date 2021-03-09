#pragma once
class Line : public Object
{
public:

	Sprite* m_Line;

	Line(bool vh,float posx, float posy);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);

};

