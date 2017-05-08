// RPGConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <rlutil/rlutilJM.h>
#include <rlutil/Entity.h>
#include <rlutil/Bar.h>
#include "RPGApp.h"
#include <Windows.h>

int main()
{
	RPGApp app;

	app.App(240, 126,"RPG Console");
	std::atexit(rlUtilJMApp::OnClose);
    return 0;
}

