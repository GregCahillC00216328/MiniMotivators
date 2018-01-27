#include "Game.h"//murt was heredfuisgnsdkfgsdfsdfsd vhgh
#include <SFML\Graphics.hpp>
#include <iostream>


// neede to initialise the gamemode
// as this is static we need to initialise it outside of the methods
// and need to refrence it using the class rather than via an istance
GameMode Game::m_currentMode{ GameMode::LicenseScreen };




Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Mini-Motivators" },
	m_exitGame{ false } //when true game will exit
{
	setupAssets(); // load font 

}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
				// need to change this as escape should pause
				// or bring me back one level in the game not exit
				// straight away
			}
		}
	}
}

/// <summary>
/// Update the game world
/// switch to which ever class is dealing wiht curretn game state
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	switch (m_currentMode)
	{
	case GameMode::LicenseScreen:
		m_licenseScreen.update(t_deltaTime);
		break;
	case GameMode::SplashScreen:
		m_splashScreen.update(t_deltaTime);
		break;
	case GameMode::MainMenuScreen:
		m_mainMenuScreen.update(t_deltaTime, m_window);
		break;
	case GameMode::HelpScreen:
		m_helpScreen.update(t_deltaTime);
		break;
	case GameMode::LevelIntroScreen:
		m_levelIntroScreen.update(t_deltaTime);
		break;
	case GameMode::OptionsScreen:
		m_optionsScreen.update(t_deltaTime);
		break;
	case GameMode::CreditsScreen:
		m_creditsScreen.update(t_deltaTime);
		break;
	case GameMode::LevelScreen:
		m_levelScreen.update(t_deltaTime);
		break;
	default:
		break;
	}
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the game
/// switch to which ever class is dealing wiht curretn game state
/// </summary>
void Game::render()
{
	switch (m_currentMode)
	{
	case GameMode::LicenseScreen:
		m_licenseScreen.render(m_window);
		break;
	case GameMode::SplashScreen:
		m_splashScreen.render(m_window);
		break;
	case GameMode::MainMenuScreen:
		m_mainMenuScreen.render(m_window);
		break;
	case GameMode::OptionsScreen:
		m_optionsScreen.render(m_window);
		break;
	case GameMode::LevelIntroScreen:
		m_levelIntroScreen.render(m_window);
		break;
	case GameMode::HelpScreen:
		m_helpScreen.render(m_window);
		break;
	case GameMode::CreditsScreen:
		m_creditsScreen.render(m_window);
		break;
	case GameMode::LevelScreen:
		m_levelScreen.render(m_window);
		break;
	default:
		break;
	}

}

/// <summary>
/// load the font for use in other classes
/// get other classes to setup their assets
/// </summary>
void Game::setupAssets()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_licenseScreen.setup(m_ArialBlackfont);
	m_splashScreen.setup(m_ArialBlackfont);
	m_mainMenuScreen.setup(m_ArialBlackfont);
	m_creditsScreen.setup(m_ArialBlackfont);
	m_helpScreen.setup(m_ArialBlackfont);
	m_levelIntroScreen.setup(m_ArialBlackfont);
	m_optionsScreen.setup(m_ArialBlackfont);
	m_levelScreen.setup(m_ArialBlackfont);
}