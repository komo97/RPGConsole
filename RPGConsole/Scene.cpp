#include "stdafx.h"
#include "Scene.h"
#include "rlutil\rlutilJM.h"

Scene* Scene::currentScene;
std::vector<std::vector<int**>> Scene::spritesHolder;
Scene::Scene()
{
	currentScene = NULL;
}

void Scene::Start()
{

}

void Scene::Draw()
{

}

void Scene::Update()
{

}

void Scene::EndScene()
{
	for (auto i : spritesHolder) {
		for (auto j : i) {
			delete j;
		}
	}
	spritesHolder.clear();
	rlUtilJM::ForceClearScreen();
	if (currentScene != NULL) {
		delete currentScene;
		rlUtilJM::CleanEntities();
	}
}

void Scene::ChangeScene(Scene* scene)
{
	EndScene();
	currentScene = scene;
	scene->Start();
}

Scene* Scene::GetCurrentScene()
{
	return currentScene;
}
