#pragma once
#include "Scene.h"
#include "rlutil\Entity.h"

class Level1 : public Scene {
public:
	void Update() final;
	void Draw() final;
protected:
	void Start() final;
private:
	Entity* player;
};