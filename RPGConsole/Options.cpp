#include "stdafx.h"
#include "Options.h"
#include <rlutil/rlutilJM.h>
#include "MainMenu.h"

namespace OptionItems {
	enum OptionItems {
		FirstElement,
		PlayMusic,
		ChangeMusicVolume,
		MainMenuOption,
		LastElement,
	};
}

void Options::Update()
{

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && !keyIsPressed &&
		playerSelection > OptionItems::FirstElement + 1)
	{
		playerSelection--;
		keyIsPressed = true;
	}

	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && !keyIsPressed &&
		playerSelection < OptionItems::LastElement - 1)
	{
		playerSelection++;
		keyIsPressed = true;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && !keyIsPressed &&
		playerSelection == OptionItems::PlayMusic)
	{
		musicIsPlaying = !musicIsPlaying;
		keyIsPressed = true;
		if (musicIsPlaying)
			rlUtilJM::UnPauseBackgroundMusic();
		else if (!musicIsPlaying)
			rlUtilJM::PauseBackgroundMusic();
	}

	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && 
			(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && 
			(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
		keyIsPressed = false;

	if (playerSelection == OptionItems::ChangeMusicVolume)
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::A)) &&
			rlUtilJM::GetBackgroundVolume() > 0)
			rlUtilJM::ChangeBackgroundVolume(rlUtilJM::GetBackgroundVolume() - 1);

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::D)) &&
			rlUtilJM::GetBackgroundVolume() < 100)
			rlUtilJM::ChangeBackgroundVolume(rlUtilJM::GetBackgroundVolume() + 1);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) &&
		playerSelection == OptionItems::MainMenuOption)
		ChangeScene(new MainMenu());
	std::snprintf(volume,4, "%f", rlUtilJM::GetBackgroundVolume());
}

void Options::Draw()
{
	rlUtilJM::TextWrapper("     Play Music?     ",
		playerSelection == OptionItems::PlayMusic ? LBASEBLACK : LBASEWHITE,
		playerSelection == OptionItems::PlayMusic ? BBASEWHITE : BBASEBLACK,
		(rlUtilJM::getScreenWidth() / 2) - 16, (rlUtilJM::getScreenHeight() / 2));
	rlUtilJM::TextWrapper(musicIsPlaying ? "TRUE" : "FALSE",
		playerSelection == OptionItems::PlayMusic ? LBASEBLACK : LBASEWHITE,
		playerSelection == OptionItems::PlayMusic ? BBASEWHITE : BBASEBLACK,
		(rlUtilJM::getScreenWidth() / 2) + 16, (rlUtilJM::getScreenHeight() / 2));
	rlUtilJM::TextWrapper("     Music Volume    ",
		playerSelection == OptionItems::ChangeMusicVolume ? LBASEBLACK : LBASEWHITE,
		playerSelection == OptionItems::ChangeMusicVolume ? BBASEWHITE : BBASEBLACK,
		(rlUtilJM::getScreenWidth() / 2) - 16, (rlUtilJM::getScreenHeight() / 2) + 1);
	rlUtilJM::TextWrapper(volume,
		playerSelection == OptionItems::ChangeMusicVolume ? LBASEBLACK : LBASEWHITE,
		playerSelection == OptionItems::ChangeMusicVolume ? BBASEWHITE : BBASEBLACK,
		(rlUtilJM::getScreenWidth() / 2) + 16, (rlUtilJM::getScreenHeight() / 2) + 1);
	rlUtilJM::TextWrapper("     Main Menu       ",
		playerSelection == OptionItems::MainMenuOption ? LBASEBLACK : LBASEWHITE,
		playerSelection == OptionItems::MainMenuOption ? BBASEWHITE : BBASEBLACK,
		(rlUtilJM::getScreenWidth() / 2) - 16, (rlUtilJM::getScreenHeight() / 2 + 2));
}

void Options::Start()
{
	musicIsPlaying = rlUtilJM::BackgroundMusicIsPlaying();
	keyIsPressed = false;
	volume = new char[4];
	playerSelection = OptionItems::FirstElement;
	//rlUtilJM::PlayMusicBackground("", FALSE, 100, TRUE);
}
