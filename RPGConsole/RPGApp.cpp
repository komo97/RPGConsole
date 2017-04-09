#include "stdafx.h"
#include "RPGApp.h"
#include <rlutil/Entity.h>
#include <rlutil/rlutilJM.h>
#include "Scene.h"
#include "MainMenu.h"


void RPGApp::Update()
{
	rlUtilJMApp::Update();
	Scene::GetCurrentScene()->Update();

}

void RPGApp::Start()
{

	Scene::ChangeScene(new MainMenu());

	rlUtilJMApp::Start();
}

void RPGApp::Draw()
{
	rlUtilJMApp::Draw();
	Scene::GetCurrentScene()->Draw();


}


