#include "stdafx.h"
#include "Scene.h"
#include "rlutil\rlutilJM.h"

Scene* Scene::currentScene;
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
