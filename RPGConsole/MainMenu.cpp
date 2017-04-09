#include "stdafx.h"
#include "MainMenu.h"
#include <rlutil\rlutilJM.h>
#include <rlutil\Entity.h>
#include "PlayerSprite.h"
#include "Options.h"

//Entity* player;

int playerSelection;
bool keyIsPressed;

namespace MenuItems {
	enum MenuItems {
		FirstElement,
		StartGame,
		Options,
		QuitGame,
		LastElement,
	};
}
void MainMenu::Start()
{
	//player = new Entity(CHARACTER, 0, 0);
	//player->InitSprite(25, 25);
	//player->setSprite(PlayerSprite1());
	//player->setColors(RED, BLUE, WHITE, BLACK);
	//player->setLetters('1', '2', '3', '4');
	//player->setBackgrounds(RED, BLUE, BLUE, WHITE);
	//player->setLife(100);
	rlUtilJM::PlayMusicBackground("data/Final_Fantasy.flac", TRUE, 100, TRUE);
	playerSelection = MenuItems::StartGame;
	keyIsPressed = false;
}

void MainMenu::Update()
{
	//rlUtilJM::TextWrapper("Main Menu", RED, BLUE, 20, 20);

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//	player->addY(-1);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//	player->addX(-1);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//	player->addY(1);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//	player->addX(1);
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
		case 1:
			break;
		case 2:
			break;
		case 3:
			Scene::ChangeScene(new Options());
			break;
		}
	}


}

void MainMenu::Draw()
{
	//player->draw();
	rlUtilJM::TextWrapper("     Start Game     ",
		playerSelection == 1 ? BLACK : WHITE, playerSelection == 1 ? WHITE : BLACK,
		(rlUtilJM::getScreenWidth() / 2) - 10, rlUtilJM::getScreenHeight()/2);
	rlUtilJM::TextWrapper("      Load Game     ",
		playerSelection == 2 ? BLACK : WHITE, playerSelection == 2 ? WHITE : BLACK,
		(rlUtilJM::getScreenWidth() / 2) - 10, (rlUtilJM::getScreenHeight() / 2) +1);
	rlUtilJM::TextWrapper("       Options      ",
		playerSelection == 3 ? BLACK : WHITE, playerSelection == 3 ? WHITE : BLACK,
		(rlUtilJM::getScreenWidth() / 2) - 10, (rlUtilJM::getScreenHeight() / 2) + 2);
}
