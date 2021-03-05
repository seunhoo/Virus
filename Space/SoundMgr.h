#pragma once
class SoundMgr :public Singleton<SoundMgr>
{
public:


	void Play(const WCHAR* pFileName, bool loop);
	void Stop();
};

