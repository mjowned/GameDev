#pragma once
#include <vector>
#include "Box2D\Box2D.h"
#include "testLevel.h"


class Level;

class LevelFactory
{
public:
	static Level* GetNextLevel(Level*);
	static Level* GetFirstLevel();
private:
	LevelFactory();
	~LevelFactory();
	static void Init();
	static std::vector<Level*> levels;
	
};

