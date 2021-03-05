#pragma once
class Texture;
class Sprite : public Object
{
	LPD3DXSPRITE m_pSp;
	Texture* m_Texture;
	RECT m_Rect;

public:
	Sprite();

	bool Init(std::wstring fileName);
	static Sprite* Create(std::wstring fileName);
	void Render() override;
	int A, R, G, B;
};