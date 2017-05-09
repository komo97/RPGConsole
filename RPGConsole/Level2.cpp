#include "stdafx.h"
#include "Level2.h"
#include "sprites\Tile1.h"
#include "PlayerSprite.h"


void Level2::Update()
{
	isGrounded = false;
	++gravity;
	for (auto i : platforms)
	{
		if (player->getX() >= i->getX() && player->getX() <= i->getX() + i->getSpriteSizeHor())
		{
			//top Collisions
			if (player->getY() + player->getSpriteSizeVer() < i->getY())
			{
				gravity = 0;
				isGrounded = true;
				break;
			}
			//bottom collisions
			else if (player->getY() - 1 >= i->getY() + i->getSpriteSizeVer())
			{
				gravity = 0;
				isGrounded = false;
				break;
			}
			else if (player->getY() >= i->getY())
			{
				player->setY(i->getY() - player->getSpriteSizeVer());
				gravity = 0;
				isGrounded = true;
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isGrounded)
	{
		player->addY(-(jumpForce));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player->addX(-1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player->addX(1);
	//for (auto i : platforms)
	//	i->addX(-1);
	//collisions
	if(!isGrounded)
		player->addY(gravity);
	if (!(++count %= 15)) rlUtilJM::ForceClearScreen();
}

void Level2::Draw()
{
	for (auto i : platforms)
		i->draw();
	player->draw();
}

void Level2::Start()
{
	rlUtilJM::ChangeWindowTitle("Level 2");
	sprites.push_back(new int*[20]);
	sprites.push_back(Tile1::FillSprite());
	for (int i = 20; i--;)
	{
		sprites[0][i] = new int[100];
	}
	for (int i = 20; i--;)
	{
		for (int j = 100; j--;)
		{
			sprites[0][i][j] = sprites[1][i][j % 20];
		}
	}
	player = new Entity(RLCHARACTER, 0,rlUtilJM::getScreenHeight() - 40);
	player->InitSprite(25, 23);
	player->setColors(LBASEGREEN, LBASEGREEN, LBASEMAGENTA, LBASEMAGENTA);
	player->setLetters('\0', '\0', '\0', '\0');
	player->setBackgrounds(BBASEGREEN, BBASEGREEN, BBASEMAGENTA, BBASEMAGENTA);
	player->setLife(100);
	player->setSprite(PlayerSprite1());
	player->setIsStatic(true);
	platforms.push_back(new Entity(RLBACKGROUND, 0, rlUtilJM::getScreenHeight()-20));
	platforms.push_back(new Entity(RLBACKGROUND, 100, rlUtilJM::getScreenHeight() - 20));
	platforms.push_back(new Entity(RLBACKGROUND, 200, rlUtilJM::getScreenHeight() - 20));
	platforms.push_back(new Entity(RLBACKGROUND, 300, rlUtilJM::getScreenHeight() - 20));
	platforms.push_back(new Entity(RLBACKGROUND, 400, rlUtilJM::getScreenHeight() - 20));
	platforms.push_back(new Entity(RLBACKGROUND, 500, rlUtilJM::getScreenHeight() - 20));
	for (auto i : platforms)
	{
		i->InitSprite(100, 20);
		i->setBackgrounds(BBASEBROWN, BBASERED, BBASEBLUE, BBASEYELLOW);
		i->setColors(ALPHACOLOR, ALPHACOLOR, ALPHACOLOR, ALPHACOLOR);
		i->setLetters('\0', '\0', '\0', '\0');
		i->setIsStatic(true);
		i->setSprite(sprites[0]);
	}

	spritesHolder.push_back(sprites);
}
