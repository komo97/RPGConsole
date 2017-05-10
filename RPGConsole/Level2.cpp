#include "stdafx.h"
#include "Level2.h"
#include "sprites\Tile1.h"
#include "PlayerSprite.h"


void Level2::Update()
{
	isGrounded = false;
	gravity +=.2f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (player->getX() <= rlUtilJM::getScreenWidth() / 3)
		{
			for (auto i : platforms)
			{
				if (!((i->getY() <= player->getY() && i->getY() >=
					(player->getY() + player->getSpriteSizeVer()) ||
					i->getY() + i->getSpriteSizeVer() <= player->getY() &&
					i->getY() + i->getSpriteSizeVer() >=
					(player->getY() + player->getSpriteSizeVer())) &&
					player->getX() <= i->getX() + i->getSpriteSizeHor()))
					i->addX(2);
			}
		}
		else
		{
			for (auto i : platforms)
			{
				if (!((i->getY() <= player->getY() && i->getY() >=
					(player->getY() + player->getSpriteSizeVer()) ||
					i->getY() + i->getSpriteSizeVer() <= player->getY() &&
					i->getY() + i->getSpriteSizeVer() >=
					(player->getY() + player->getSpriteSizeVer())) &&
					player->getX() <= i->getX() + i->getSpriteSizeHor()))
				{
					player->addX(-2);
					break;
				}
			}
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (player->getX() + player->getSpriteSizeHor() >= rlUtilJM::getScreenWidth() / 2)
		{
			for (auto i : platforms)
			{
				if (!((i->getY() <= player->getY() && i->getY() >=
					(player->getY() + player->getSpriteSizeVer()) ||
					i->getY() + i->getSpriteSizeVer() <= player->getY() &&
					i->getY() + i->getSpriteSizeVer() >=
					(player->getY() + player->getSpriteSizeVer())) &&
					player->getX() + player->getSpriteSizeHor() >= i->getX()))
					i->addX(-2);
			}
		}
		else
		{
			for (auto i : platforms)
			{
				if (!((i->getY() <= player->getY() && i->getY() >=
					(player->getY() + player->getSpriteSizeVer()) || 
					i->getY() + i->getSpriteSizeVer() <= player->getY() &&
					i->getY() + i->getSpriteSizeVer() >=
					(player->getY() + player->getSpriteSizeVer())) &&
					player->getX() + player->getSpriteSizeHor() >= i->getX()))
				{
					player->addX(2);
					break;
				}
			}
		}
	}
	for (auto i : platforms)
	{
		if (player->getX() + player->getSpriteSizeHor() >= i->getX() &&
			player->getX() <= i->getX() + i->getSpriteSizeHor())
		{
			if (player->getY() >= i->getY() + i->getSpriteSizeVer())
			{
				isGrounded = false;
				gravity = 1;
			}
			//top Collisions
			else if (player->getY() + player->getSpriteSizeVer() <= i->getY() + 1 &&
				player->getY() + player->getSpriteSizeVer() >= i->getY() - 1)
			{
				player->setY(i->getY() - player->getSpriteSizeVer());
				gravity = 0;
				isGrounded = true;
			}
			//bottom collisions
			else if (player->getY() - 1 >= i->getY() + i->getSpriteSizeVer())
			{
				isGrounded = false;
				gravity = 1;
			}
			else if (player->getY() >= i->getY() &&
				player->getY() < i->getY() + i->getSpriteSizeVer())
			{
				//player->setY(i->getY() - player->getSpriteSizeVer());
				if (player->getX() < i->getX() + (i->getSpriteSizeHor() / 2))
					player->setX(i->getX() - player->getSpriteSizeHor());
				else player->setX(i->getX() + player->getSpriteSizeHor());
				isGrounded = false;
				continue;
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isGrounded)
	{
		isJumping = true;
		isGrounded = false;
	}
	if (isJumping) {
		player->addY(-(jump += .3f));
		if (jump >= jumpForce)
		{
			jump = 0;
			isJumping = false;
		}
	}
	else if(!isGrounded)
		player->addY(gravity);
	if (player->getY() >= rlUtilJM::getScreenHeight()) ChangeScene(new Level2());
	if (!(++count %= 3)) rlUtilJM::ForceClearScreen();
}

void Level2::Draw()
{
	background->draw();
	for (auto i : platforms)
		i->draw();
	if(!isDead)
		player->draw();
}

void Level2::Start()
{
	rlUtilJM::ChangeWindowTitle("Level 2");
	sprites.push_back(new int*[20]);
	sprites.push_back(Tile1::FillSprite());
	sprites.push_back(new int*[127]);
	for (int i = 20; i--;)
	{
		sprites[0][i] = new int[100];
		for (int j = 100; j--;)
		{
			sprites[0][i][j] = sprites[1][i][j % 20];
		}
	}
	for (int i = 127; i--;)
	{
		sprites[2][i] = new int[240];
		for (int j = 240; j--;)
		{
			sprites[2][i][j] = BACKGROUND1;
		}
	}
	player = new Entity(RLBACKGROUND, 0, rlUtilJM::getScreenHeight() - 60);
	player->InitSprite(25, 23);
	player->setColors( ALPHACOLOR, ALPHACOLOR, LBASEGREEN, LBASEGREEN );
	player->setLetters('\0', '\0', '\0', '\0');
	player->setBackgrounds( ALPHACOLOR, ALPHACOLOR, BBASEGREEN, BBASEGREEN);
	player->setLife(100);
	player->setSprite(PlayerSprite1());
	player->setIsStatic(true);
	platforms.push_back(new Entity(RLBACKGROUND, 0, rlUtilJM::getScreenHeight() - 20));
	platforms.push_back(new Entity(RLBACKGROUND, 140, rlUtilJM::getScreenHeight() - 30));
	platforms.push_back(new Entity(RLBACKGROUND, 290, rlUtilJM::getScreenHeight() - 40));
	platforms.push_back(new Entity(RLBACKGROUND, 420, rlUtilJM::getScreenHeight() - 80));
	platforms.push_back(new Entity(RLBACKGROUND, 580, rlUtilJM::getScreenHeight() - 20));
	platforms.push_back(new Entity(RLBACKGROUND, 700, rlUtilJM::getScreenHeight() - 20));
	background = new Entity(RLBACKGROUND, 0, 0);
	background->setColors(LBASEGREEN, LBASEGREEN, LBASEMAGENTA, LBASEMAGENTA);
	background->setLetters('\0', '\0', '\0', '\0');
	background->setBackgrounds(BBASEBLUE, BBASEGREEN, BBASEMAGENTA, BBASEMAGENTA);
	background->InitSprite(240, 127);
	background->setSprite(sprites[2]);
	background->setIsStatic(true);
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
