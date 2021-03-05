#pragma once
class CollisionMgr : public Singleton<CollisionMgr>
{
public:
	bool MouseWithBoxSize(Object* obj);
};

