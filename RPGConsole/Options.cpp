#include "stdafx.h"
#include "Options.h"
#include <rlutil/rlutilJM.h>


void Options::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && !keyIsPressed)
	{
		musicIsPlaying = !musicIsPlaying;
		keyIsPressed = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		keyIsPressed = false;

	if (musicIsPlaying && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		rlUtilJM::PlayMusicBackground("data/Final_Fantasy.flac", TRUE, 100, TRUE);
	else if (!musicIsPlaying && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		rlUtilJM::PlayMusicBackground("", TRUE, 100, TRUE);
}

void Options::Draw()
{
	rlUtilJM::TextWrapper("     Play Music?     ",
		WHITE, BLACK, (rlUtilJM::getScreenWidth() / 2) - 16, (rlUtilJM::getScreenHeight() / 2));
	rlUtilJM::TextWrapper(+ musicIsPlaying ? "TRUE" : "FALSE",
		WHITE, BLACK, (rlUtilJM::getScreenWidth() / 2) + 16, (rlUtilJM::getScreenHeight() / 2));
	rlUtilJM::TextWrapper("     Main Menu       ",
		WHITE, BLACK, (rlUtilJM::getScreenWidth() / 2) + 16, (rlUtilJM::getScreenHeight() / 2 - 5));
}

void Options::Start()
{
	musicIsPlaying = true;
	keyIsPressed = false;
	//rlUtilJM::PlayMusicBackground("", FALSE, 100, TRUE);
}
