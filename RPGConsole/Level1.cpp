#include "stdafx.h"
#include "Level1.h"
#include "PlayerSprite.h"

void Level1::Update()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player->addY(-1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player->addX(-1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player->addY(1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player->addX(1);
}

void Level1::Draw()
{
	//player->draw();

	rlUtilJM::TextWrapper("A", BLACK, WHITE, 50, 1);
	rlUtilJM::TextWrapper("B", BLUE, WHITE, 50, 2);
	rlUtilJM::TextWrapper("C", GREEN, WHITE, 50, 3);
	rlUtilJM::TextWrapper("A", CYAN, WHITE, 50, 4);
	rlUtilJM::TextWrapper("A", RED, WHITE, 50, 5);
	rlUtilJM::TextWrapper("A", MAGENTA, WHITE, 50, 6);
	rlUtilJM::TextWrapper("A", BROWN, WHITE, 50, 7);
	rlUtilJM::TextWrapper("A", GREY, WHITE, 50, 8);
	rlUtilJM::TextWrapper("A", DARKGREY, WHITE, 50, 9);
	rlUtilJM::TextWrapper("A", LIGHTBLUE, WHITE, 50, 10);
	rlUtilJM::TextWrapper("A", LIGHTCYAN, WHITE, 50, 11);
	rlUtilJM::TextWrapper("A", LIGHTRED, WHITE, 50, 12);
	rlUtilJM::TextWrapper("A", LIGHTMAGENTA, WHITE, 50, 13);
	rlUtilJM::TextWrapper("A", YELLOW, WHITE, 50, 14);
	rlUtilJM::TextWrapper("A", WHITE, BLACK, 50, 15);

	rlUtilJM::TextWrapper("A", BLACK, BLACK, 51, 1);
	rlUtilJM::TextWrapper("B", BLUE, BLUE, 51, 2);
	rlUtilJM::TextWrapper("C", GREEN, GREEN, 51, 3);
	rlUtilJM::TextWrapper("A", CYAN, CYAN, 51, 4);
	rlUtilJM::TextWrapper("A", RED, RED, 51, 5);
	rlUtilJM::TextWrapper("A", MAGENTA, MAGENTA, 51, 6);
	rlUtilJM::TextWrapper("A", BROWN, BROWN, 51, 7);
	rlUtilJM::TextWrapper("A", GREY, GREY, 51, 8);
	rlUtilJM::TextWrapper("A", DARKGREY, DARKGREY, 51, 9);
	rlUtilJM::TextWrapper("A", LIGHTBLUE, LIGHTBLUE, 51, 10);
	rlUtilJM::TextWrapper("A", LIGHTCYAN, LIGHTCYAN, 51, 11);
	rlUtilJM::TextWrapper("A", LIGHTRED, LIGHTRED, 51, 12);
	rlUtilJM::TextWrapper("A", LIGHTMAGENTA, LIGHTMAGENTA, 51, 13);
	rlUtilJM::TextWrapper("A", YELLOW, YELLOW, 51, 14);
	rlUtilJM::TextWrapper("A", WHITE, WHITE, 51, 15);


}

void Level1::Start()
{
	player = new Entity(CHARACTER, 0, 0);
	player->InitSprite(25, 23);
	player->setSprite(PlayerSprite1());
	player->setColors(RED, BLUE, WHITE, BLACK);
	player->setLetters('1', '2', '3', '4');
	player->setBackgrounds(RED, BLUE, BLUE, WHITE);
	player->setLife(100);
}
