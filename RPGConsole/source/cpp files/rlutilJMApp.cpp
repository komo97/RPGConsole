#include "rlutilJMApp.h"
#include <cstdlib>

void rlUtilJMApp::Draw()
{
	
}

void rlUtilJMApp::Start()
{

	DrawStep();
	rlUtilJM::AddToDrawThread(std::bind(&rlUtilJMApp::Draw,this));
}

void rlUtilJMApp::Update()
{
	rlUtilJM::AddToDrawThread(rlUtilJM::ClearBuffer);
	rlUtilJM::KeepScreenSize();
	rlUtilJM::AddToDrawThread(std::bind(&rlUtilJMApp::Draw, this));
}

void rlUtilJMApp::OnClose()
{
	rlUtilJM::RestoreFont();
}

void rlUtilJMApp::EndOfFrame()
{
	rlUtilJM::AddToDrawThread(rlUtilJM::PrintBuffer);
}

void rlUtilJMApp::App(int windowWidthInPixels, int windowHeightInPixels)
{
	rlUtilJM::WindowSize(windowHeightInPixels, windowHeightInPixels);

	this->Start();
	
	while (1)
	{
		this->Update();
		std::atexit(rlUtilJMApp::OnClose);
		EndOfFrame();
	}


}

void rlUtilJMApp::DrawStep()
{
	rlUtilJM::startDrawThread(rlUtilJM::executeDraw);
}
