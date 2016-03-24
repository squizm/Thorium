#pragma once
#include "Scene.h"
#include "GameEngine.h"
#include "Map.h"
#include <bitset>

class SceneCampaign :
	public Scene
{
private:
	GameEngine* game;
	Map* map;
public:
	SceneCampaign(GameEngine* gameEngine);
	SceneCampaign();
	~SceneCampaign();
	void update();
	void render();
};

