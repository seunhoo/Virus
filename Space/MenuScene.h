#pragma once
class MenuScene : public Scene
{
public:

	MenuScene();


	void Init();
	void Update(float deltatime, float time);
	void Release();
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

