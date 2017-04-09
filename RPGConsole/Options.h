#pragma once
#include "Scene.h"

class Options : public Scene {
public:
	void Update() final;
	void Draw() final;
protected:
	void Start() final;
private:
	bool musicIsPlaying, keyIsPressed;
	char* volume;
	int playerSelection;
	//class MainMenu;
};