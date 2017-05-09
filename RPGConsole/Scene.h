#pragma once
#include <vector>
class Scene {
public:
	Scene();
	virtual void Draw();
	virtual void Update();
	static void EndScene();
	static void ChangeScene(Scene* scene);
	static Scene* GetCurrentScene();
private:
	static Scene* currentScene;
protected:
	virtual void Start();
	static std::vector<std::vector<int**>> spritesHolder;

};