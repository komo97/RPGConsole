#include "stdafx.h"
#include "Level1.h"

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
	player->draw();
}

void Level1::Start()
{
	player = new Entity(CHARACTER, 0, 0);
	//player->InitSprite(25, 25);
	//player->setSprite(PlayerSprite1());
	player->setColors(RED, BLUE, WHITE, BLACK);
	player->setLetters('1', '2', '3', '4');
	player->setBackgrounds(RED, BLUE, BLUE, WHITE);
	player->setLife(100);
}
