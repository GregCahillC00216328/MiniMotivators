#include"MainMenu.h"
#include "Game.h"
#include "GameStates.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		Game::m_currentMode = GameMode::LevelIntroScreen;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		Game::m_currentMode = GameMode::OptionsScreen;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		Game::m_currentMode = GameMode::HelpScreen;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		Game::m_currentMode = GameMode::CreditsScreen;
	}
}

void MainMenu::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	t_window.draw(m_message);
	t_window.display();
}

void MainMenu::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Main Menu");
	m_message.setFont(m_font);
}
