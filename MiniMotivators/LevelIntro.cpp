#include "LevelIntro.h"
#include "Game.h"


LevelIntro::LevelIntro()
{
}


LevelIntro::~LevelIntro()
{
}

void LevelIntro::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		Game::m_currentMode = GameMode::MainMenuScreen;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Game::m_currentMode = GameMode::LevelScreen;
	}
}

void LevelIntro::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Yellow);
	t_window.draw(m_message);
	t_window.display();
}

void LevelIntro::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Blue);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("level intro");
	m_message.setFont(m_font);
}