#pragma once
class ScoreMgr : public Singleton<ScoreMgr>
{
public:


	int m_Score;

	void SetScore(int score) {	m_Score = score;}
	int GetScore() { return m_Score; }
	void AddScore(int score) { m_Score += score; }
	void ResetScore() { m_Score = 0; }
};

