#pragma once
class Object
{
public:
	Object* m_Parent;
	Matrix m_wMat;
	Vec2 m_Position;
	Vec2 m_Scale;
	Vec2 m_Size;

	float m_Radius;
	float m_Rotation;

	bool m_Destroy;
	RECT m_Collision;

	bool m_Visible;

	int m_Layer;
	std::string m_Tag;

public:
	Object();
	~Object();


protected:
	Matrix GetMatrix();

public:
	virtual void Update(float deltaTime, float time);
	virtual void Render();
	virtual void OnCollision(Object* other,std::string tag);

public:
	void SetPosition(float x, float y);
	void SetDestroy(bool destroy) { m_Destroy = destroy; }
	void SetTag(const std::string tag);
	void SetParent(Object* obj);
	void SetPosition(Vec2 pos) { m_Position = pos; }
	void SetScale(float x, float y) { m_Scale.x = x; m_Scale.y = y; }
	void SetScale(Vec2 pos) { m_Scale = pos; }
public:
	bool GetDestroy() { return m_Destroy; }
};                                                                                                                                                                                         