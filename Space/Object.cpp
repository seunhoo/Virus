
#include "stdafx.h"
#include "Object.h"


Object::Object() :
	 m_Position(0.f, 0.f)
	, m_Rotation(0.f)
	, m_Scale(1.f, 1.f)
	, m_Destroy(0)
	, m_Visible(true)
	, m_Layer(0)
	, m_Tag("UnNamed")
	, m_Parent(nullptr)
{
	D3DXMatrixIdentity(&m_wMat);
}


Object::~Object()
{
}

Matrix Object::GetMatrix()
{

	D3DXMatrixTransformation2D(&m_wMat, 0, 0, &m_Scale, 0, m_Rotation, &m_Position);

	if (m_Parent)
		m_wMat *= m_Parent->GetMatrix();

	return m_wMat;
}

void Object::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Object::SetTag(const std::string tag)
{
	m_Tag = tag;
}

void Object::SetParent(Object* obj)
{
	m_Parent = obj;
}

void Object::Update(float deltaTime, float time)
{
}

void Object::Render()
{
}

void Object::OnCollision(Object* other)
{
}