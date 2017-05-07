#pragma once
#include "Scene.h"
#include "rlutil\Entity.h"
#include <vector>

class Level1 : public Scene {
public:
	void Update() final;
	void Draw() final;
protected:
	void Start() final;
private:
	Entity* player;
	Entity* fireplace;
	Entity* rock;
	Entity* log;
	Entity* girl;
	std::vector<Entity*> bg;
	std::vector<int**> sprites;
};