#include "stdafx.h"
#include "asd.h"

asd::asd()
{
	asdf = Sprite::Create(L"Painting/BG1.png");
	asdf->SetParent(this);
	SetPosition(1920 / 2, 1080 / 2);
}

void asd::Update(float deltatime, float time)
{
}

void asd::Render()
{
	asdf->Render();
}
