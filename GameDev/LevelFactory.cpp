#include "LevelFactory.h"

std::vector<Level*> LevelFactory::levels;
LevelFactory::LevelFactory() { }
	
LevelFactory::~LevelFactory() { }

void LevelFactory::Init(PlayState* play)
{
	levels = {
		new TestLevel(2000, 120,play), 
		//TODO add , new Level1() , new level2()
	};
}

Level* LevelFactory::GetFirstLevel(PlayState* play)
{
	if (!(levels.size() > 0))
	{
		Init(play);
	}
	return levels[0]->CreateLevel();
}

Level* LevelFactory::GetNextLevel(Level* level, PlayState* play)
{
	if (!(levels.size() > 0))
	{
		Init(play);
	}
	bool foundLevel = false;
	for (size_t i = 0; i < levels.size(); i++)
	{
		if (foundLevel){
			
			return levels[i];
		}
		if (levels[i] == level)
			foundLevel = true;
	}

	if (foundLevel)
	{
		// you just finished last level
		// give te first level
		//TODO back to main screen
		return levels[0]->CreateLevel();
	}
	//level was not in levels list get te first level
	return levels[0]->CreateLevel();
}
