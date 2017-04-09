#pragma once
#include "Scene.h"

class MainMenu : public Scene {
public:
	void Update() final;
	void Draw() final;
protected:
	void Start() final;
};