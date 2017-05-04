#include "stdafx.h"
#include "MainMenu.h"
#include <rlutil\rlutilJM.h>
#include <rlutil\Entity.h>
#include "Options.h"

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
	keyIsPressed = false;
}

void MainMenu::Update()
{

	if (playerSelection < MenuItems::LastElement - 1 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && !keyIsPressed)
	{
		playerSelection++;
		keyIsPressed = true;
	}
	else if (playerSelection > MenuItems::FirstElement + 1 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && !keyIsPressed)
	{
		playerSelection--;
		keyIsPressed = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
		keyIsPressed = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		switch (playerSelection)
		{
		case MenuItems::StartGame:
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


}

void MainMenu::Draw()
{

	rlUtilJM::TextWrapper("     Start Game     ",
		playerSelection == MenuItems::StartGame ? BLACK : WHITE,
		playerSelection == MenuItems::StartGame ? WHITE : BLACK,
		(rlUtilJM::getScreenWidth() / 2) - 10, rlUtilJM::getScreenHeight()/2);
	rlUtilJM::TextWrapper("      Load Game     ",
		playerSelection == MenuItems::LoadGame ? BLACK : WHITE,
		playerSelection == MenuItems::LoadGame ? WHITE : BLACK,
		(rlUtilJM::getScreenWidth() / 2) - 10, (rlUtilJM::getScreenHeight() / 2) +1);
	rlUtilJM::TextWrapper("       Options      ",
		playerSelection == MenuItems::Options ? BLACK : WHITE,
		playerSelection == MenuItems::Options ? WHITE : BLACK,
		(rlUtilJM::getScreenWidth() / 2) - 10, (rlUtilJM::getScreenHeight() / 2) + 2);
	rlUtilJM::TextWrapper("      Quit Game     ",
		playerSelection == MenuItems::QuitGame ? BLACK : WHITE,
		playerSelection == MenuItems::QuitGame ? WHITE : BLACK,
		(rlUtilJM::getScreenWidth() / 2) - 10, (rlUtilJM::getScreenHeight() / 2) + 3);
}
