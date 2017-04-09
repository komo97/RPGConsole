#pragma once
#include <rlutil/rlutilJMApp.h>

class RPGApp : public rlUtilJMApp{
private:
	void Update() final;
	void Start() final;
	void Draw() final;
};