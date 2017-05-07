#include "stdafx.h"
#include "MainMenu.h"
#include <rlutil\rlutilJM.h>
#include <rlutil\Entity.h>
#include "Options.h"
#include "Level1.h"

namespace MenuItems {
	enum MenuItems {
		FirstElement,
		StartGame,
		LoadGame,
		Options,
		QuitGame,
		LastElement,
	};
}
void MainMenu::Start()
{
	if(!rlUtilJM::BackgroundMusicIsPaused() &&
		!rlUtilJM::BackgroundMusicIsPlaying())
		rlUtilJM::PlayMusicBackground("data/Final_Fantasy.flac", TRUE, 100, FALSE);

	playerSelection = MenuItems::StartGame;
	keyIsPressed = true;
	rlUtilJM::ShouldClearScreen(true);
}

void MainMenu::Update()
{

	if (playerSelection < MenuItems::LastElement - 1 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && !keyIsPressed)
	{
		playerSelection++;
	}
	else if (playerSelection > MenuItems::FirstElement + 1 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && !keyIsPressed)
	{
		playerSelection--;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && !keyIsPressed)
	{
		switch (playerSelection)
		{
		case MenuItems::StartGame:
			Scene::ChangeScene(new Level1());
			break;
		case MenuItems::LoadGame:
			break;
		case MenuItems::Options:
			//player->freeSprite();
			Scene::ChangeScene(new Options());
			break;
		case MenuItems::QuitGame:
			//player->freeSprite();
			exit(0);
		}
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && 
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		keyIsPressed = false;
	else keyIsPressed = true;


}

void MainMenu::Draw()
{

	rlUtilJM::TextWrapper("     Start Game     ",
		playerSelection == MenuItems::StartGame ? LBASEBLACK : LBASEWHITE,
		playerSelection == MenuItems::StartGame ? BBASEWHITE : BBASEBLACK,
		(rlUtilJM::getScreenWidth() / 2) - 10, rlUtilJM::getScreenHeight()/2);
	rlUtilJM::TextWrapper("      Load Game     ",
		playerSelection == MenuItems::LoadGame ? LBASEBLACK : LBASEWHITE,
		playerSelection == MenuItems::LoadGame ? BBASEWHITE : BBASEBLACK,
		(rlUtilJM::getScreenWidth() / 2) - 10, (rlUtilJM::getScreenHeight() / 2) +1);
	rlUtilJM::TextWrapper("       Options      ",
		playerSelection == MenuItems::Options ? LBASEBLACK : LBASEWHITE,
		playerSelection == MenuItems::Options ? BBASEWHITE : BBASEBLACK,
		(rlUtilJM::getScreenWidth() / 2) - 10, (rlUtilJM::getScreenHeight() / 2) + 2);
	rlUtilJM::TextWrapper("      Quit Game     ",
		playerSelection == MenuItems::QuitGame ? LBASEBLACK : LBASEWHITE,
		playerSelection == MenuItems::QuitGame ? BBASEWHITE : BBASEBLACK,
		(rlUtilJM::getScreenWidth() / 2) - 10, (rlUtilJM::getScreenHeight() / 2) + 3);

}
