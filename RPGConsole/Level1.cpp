#include "stdafx.h"
#include "Level1.h"
#include "rlutil\ColorPalette.h"
#include "sprites\stuff1x1.h"
#include "sprites\stuff1x2.h"
#include "sprites\stuff1x3.h"
#include "sprites\stuff1x4.h"
#include "sprites\stuff1x5.h"
#include "sprites\stuff2x1.h"
#include "sprites\stuff2x2.h"
#include "sprites\stuff2x3.h"
#include "sprites\stuff2x4.h"
#include "sprites\stuff2x5.h"
#include "sprites\stuff3x1.h"
#include "sprites\stuff3x2.h"
#include "sprites\stuff3x3.h"
#include "sprites\stuff3x4.h"
#include "sprites\stuff3x5.h"
#include "sprites\stuff4x1.h"
#include "sprites\stuff4x2.h"
#include "sprites\stuff4x3.h"
#include "sprites\stuff4x4.h"
#include "sprites\stuff4x5.h"
#include "sprites\stuff5x1.h"
#include "sprites\stuff5x2.h"
#include "sprites\stuff5x3.h"
#include "sprites\stuff5x4.h"
#include "sprites\stuff5x5.h"
#include "sprites\stuffFogat1x1.h"
#include "sprites\stuffFogat1x2.h"
#include "sprites\stuffTron1x1.h"
#include "sprites\stuffTron1x2.h"
#include "Level2.h"


void Level1::Update()
{
	if (++count == 60)
		ChangeScene(new Level2());
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
	//	sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
	//	sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
	//	sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//{
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//		player->addY(-1);
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//	{
	//		player->addX(-1);
	//		player->setSprite(sprites[0]);
	//	}
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//		player->addY(1);
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//	{
	//		player->addX(1);
	//		player->setSprite(PlayerSprite1());
	//	}
	//	rlUtilJM::ShouldClearScreen(true);
	//}
	//else rlUtilJM::ShouldClearScreen(true);
	//for (int i = 16; i-- > 1;)
	//	test.SetColorRGB(i, rand() % 255, rand() % 255, rand() % 255);
 //	rlUtilJM::ChangeColorPalette(test);
}

void Level1::Draw()
{
	for (auto i : bg)
		i->draw();
	rock->draw();
	log->draw();
	girl->draw();
	fireplace->draw();
	//player->draw();
	//rlUtilJM::TextWrapper("A", LBASEBLACK, BBASEWHITE, 50, 1);
	//rlUtilJM::TextWrapper("B", LBASEBLUE, BBASEWHITE, 50, 2);
	//rlUtilJM::TextWrapper("C", LBASEGREEN, BBASEWHITE, 50, 3);
	//rlUtilJM::TextWrapper("A", LBASECYAN, BBASEWHITE, 50, 4);
	//rlUtilJM::TextWrapper("A", LBASERED, BBASEWHITE, 50, 5);
	//rlUtilJM::TextWrapper("A", LBASEMAGENTA, BBASEWHITE, 50, 6);
	//rlUtilJM::TextWrapper("A", LBASEBROWN, BBASEWHITE, 50, 7);
	//rlUtilJM::TextWrapper("A", LBASEGREY, BBASEWHITE, 50, 8);
	//rlUtilJM::TextWrapper("A", LBASEBLACK, BBASEWHITE, 50, 9);
	//rlUtilJM::TextWrapper("A", LBASELIGHTBLUE, BBASEWHITE, 50, 10);
	//rlUtilJM::TextWrapper("A", LBASELIGHTCYAN, BBASEWHITE, 50, 11);
	//rlUtilJM::TextWrapper("A", LBASELIGHTRED, BBASEWHITE, 50, 12);
	//rlUtilJM::TextWrapper("A", LBASELIGHTMAGENTA, BBASEWHITE, 50, 13);
	//rlUtilJM::TextWrapper("A", LBASEYELLOW, BBASEWHITE, 50, 14);
	//rlUtilJM::TextWrapper("A", LBASEWHITE, BBASEBLACK, 50, 15);

	//rlUtilJM::TextWrapper("A", LBASEBLACK, BBASEBLACK, 51, 1);
	//rlUtilJM::TextWrapper("B", LBASEBLUE, BBASEBLUE, 51, 2);
	//rlUtilJM::TextWrapper("C", LBASEGREEN, BBASEGREEN, 51, 3);
	//rlUtilJM::TextWrapper("A", LBASECYAN, BBASECYAN, 51, 4);
	//rlUtilJM::TextWrapper("A", LBASERED, BBASERED, 51, 5);
	//rlUtilJM::TextWrapper("A", LBASEMAGENTA, BBASEMAGENTA, 51, 6);
	//rlUtilJM::TextWrapper("A", LBASEBROWN, BBASEBROWN, 51, 7);
	//rlUtilJM::TextWrapper("A", LBASEGREY, BBASEGREY, 51, 8);
	//rlUtilJM::TextWrapper("A", LBASEBLACK, BBASEBLACK, 51, 9);
	//rlUtilJM::TextWrapper("A", LBASELIGHTBLUE, BBASELIGHTBLUE, 51, 10);
	//rlUtilJM::TextWrapper("A", LBASELIGHTCYAN, BBASELIGHTCYAN, 51, 11);
	//rlUtilJM::TextWrapper("A", LBASELIGHTRED, BBASELIGHTRED, 51, 12);
	//rlUtilJM::TextWrapper("A", LBASELIGHTMAGENTA, BBASELIGHTMAGENTA, 51, 13);
	//rlUtilJM::TextWrapper("A", LBASEYELLOW, BBASEYELLOW, 51, 14);
	//rlUtilJM::TextWrapper("A", LBASEWHITE, BBASEWHITE, 51, 15);
	
}

void Level1::Start()
{
	//player = new Entity(RLCHARACTER, 0, 0);
	//player->InitSprite(25, 23);
	//player->setColors(LBASEGREEN, LBASEGREEN, LBASEMAGENTA, LBASEMAGENTA);
	//player->setLetters('\0', '\0', '\0', '\0');
	//player->setBackgrounds(BBASEGREEN, BBASEGREEN, BBASEMAGENTA, BBASEMAGENTA);
	//player->setLife(100);
	//player->setSprite(PlayerSprite1());
	//player->setIsStatic(false);
	isKeyPressed = true;
	fireplace = new Entity(RLBACKGROUND, 70, 30);
	fireplace->InitSprite(61, 69);
	fireplace->setColors(ALPHACOLOR, ALPHACOLOR, ALPHACOLOR, ALPHACOLOR);
	fireplace->setLetters('\0', '\0', '\0', '\0');
	fireplace->setBackgrounds(BBASEYELLOW, BBASERED, BBASEBLACK, ALPHACOLOR);
	fireplace->setSprite(stuffFogat1x1::FillSprite());
	fireplace->setIsStatic(true);
	rock = new Entity(RLBACKGROUND, rlUtilJM::getScreenWidth()-50, 35);
	rock->InitSprite(51, 48);
	rock->setColors(ALPHACOLOR, ALPHACOLOR, ALPHACOLOR, ALPHACOLOR);
	rock->setLetters('\0', '\0', '\0', '\0');
	rock->setBackgrounds(BBASEDARKGREY, BBASEGREY, BBASEBLACK, BBASEMAGENTA);
	rock->setSprite(stuffFogat1x2::FillSprite());
	rock->setIsStatic(true);
	log = new Entity(RLBACKGROUND, 0, rlUtilJM::getScreenHeight() - 35);
	log->InitSprite(107, 35);
	log->setColors(ALPHACOLOR, ALPHACOLOR, ALPHACOLOR, ALPHACOLOR);
	log->setLetters('\0', '\0', '\0', '\0');
	log->setBackgrounds(BBASEBLACK, BBASERED, BBASEBLACK, BBASEMAGENTA);
	log->setSprite(stuffTron1x1::FillSprite());
	log->setIsStatic(true);
	girl = new Entity(RLBACKGROUND, rlUtilJM::getScreenWidth() - 96, rlUtilJM::getScreenHeight() - 93);
	girl->InitSprite(89, 93);
	girl->setColors(ALPHACOLOR, ALPHACOLOR, ALPHACOLOR, ALPHACOLOR);
	girl->setLetters('\0', '\0', '\0', '\0');
	girl->setBackgrounds(BBASEBROWN, BBASEBLACK, BBASEYELLOW, BBASEMAGENTA);
	girl->setSprite(stuffTron1x2::FillSprite());
	girl->setIsStatic(true);

	sprites.push_back(stuff1x1::FillSprite());
	sprites.push_back(stuff1x2::FillSprite());
	sprites.push_back(stuff1x3::FillSprite());
	sprites.push_back(stuff1x4::FillSprite());
	sprites.push_back(stuff1x5::FillSprite());
	sprites.push_back(stuff2x1::FillSprite());
	sprites.push_back(stuff2x2::FillSprite());
	sprites.push_back(stuff2x3::FillSprite());
	sprites.push_back(stuff2x4::FillSprite());
	sprites.push_back(stuff2x5::FillSprite());
	sprites.push_back(stuff3x1::FillSprite());
	sprites.push_back(stuff3x2::FillSprite());
	sprites.push_back(stuff3x3::FillSprite());
	sprites.push_back(stuff3x4::FillSprite());
	sprites.push_back(stuff3x5::FillSprite());
	sprites.push_back(stuff4x1::FillSprite());
	sprites.push_back(stuff4x2::FillSprite());
	sprites.push_back(stuff4x3::FillSprite());
	sprites.push_back(stuff4x4::FillSprite());
	sprites.push_back(stuff4x5::FillSprite());
	sprites.push_back(stuff5x1::FillSprite());
	sprites.push_back(stuff5x2::FillSprite());
	sprites.push_back(stuff5x3::FillSprite());
	sprites.push_back(stuff5x4::FillSprite());
	sprites.push_back(stuff5x5::FillSprite());
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			bg.push_back(new Entity(RLBACKGROUND, 48*j, 25*i));
		}
	}

	int j = 0;
	for (auto i : bg)
	{
		i->setColors(LBASERED, LBASEGREY, LBASEMAGENTA, LBASEBLACK);
		i->setLetters('\0', '\0', '\0', '\0');
		i->setBackgrounds(BBASERED, BBASEGREY, BBASEMAGENTA, BBASEBLACK);
		i->InitSprite(48, 25);
		i->setSprite(sprites[j++]);
		i->setIsStatic(true);
	}
	bg[12]->setBackgrounds(BBASERED, BBASEGREY, BBASEWHITE, BBASEBLACK);
	bg[15]->setBackgrounds(BBASERED, BBASEGREY, BBASEWHITE, BBASEBLACK);
	bg[16]->setBackgrounds(BBASERED, BBASEGREY, BBASEWHITE, BBASEBLACK);
	bg[17]->setBackgrounds(BBASERED, BBASEGREY, BBASEWHITE, BBASEBLACK);
	bg[18]->setBackgrounds(BBASERED, BBASEGREY, BBASEWHITE, BBASEBLACK);
	bg[19]->setBackgrounds(BBASERED, BBASEGREY, BBASEWHITE, BBASEBLACK);
	bg[20]->setBackgrounds(BBASERED, BBASEGREY, BBASEWHITE, BBASEBLACK);
	bg[21]->setBackgrounds(BBASERED, BBASEGREY, BBASEWHITE, BBASEBLACK);
	bg[22]->setBackgrounds(BBASERED, BBASEGREY, BBASEWHITE, BBASEBLACK);
	bg[23]->setBackgrounds(BBASERED, BBASEGREY, BBASEWHITE, BBASEBLACK);
	spritesHolder.push_back(sprites);
	rlUtilJM::ShouldClearScreen(true);

}
