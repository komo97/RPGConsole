#pragma once
#include "Scene.h"
#include <vector>
#include "rlutil\Entity.h"

class Level2 : public Scene
{
public:
	void Update() final;
	void Draw() final;
protected:
	void Start() final;
private:
	std::vector<int**> sprites;
	Entity* player;
	std::vector<Entity*> platforms;
	int count = 0;
	int gravity = 0;
	int jumpForce = 5;
	int jump = 0;
	bool isGrounded = false;
};

