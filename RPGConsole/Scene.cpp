#include "stdafx.h"
#include "Scene.h"

Scene* Scene::currentScene;
Scene::Scene()
{
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

void Scene::ChangeScene(Scene* scene)
{
	currentScene = scene;
	scene->Start();
}

Scene* Scene::GetCurrentScene()
{
	return currentScene;
}
