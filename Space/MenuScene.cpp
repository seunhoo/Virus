#include "stdafx.h"
#include "MenuScene.h"
#include"MenuSelect.h"

MenuScene::MenuScene()
{
}

void MenuScene::Init()
{
	ObjMgr->AddObject(new MenuSelect(1), "1");
	ObjMgr->AddObject(new MenuSelect(2), "1");
	ObjMgr->AddObject(new MenuSelect(3), "1");
	ObjMgr->AddObject(new MenuSelect(4), "1");
	ObjMgr->AddObject(new MenuSelect(5), "1");

}

void MenuScene::Update(float deltatime, float time)
{
}

void MenuScene::Release()
{
}

void MenuScene::Render()
{
}

void MenuScene::OnCollision(Object* obj, std::string tag)
{
}
