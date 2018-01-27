#include "Help.h"
#include "Game.h"


Help::Help()
{
}


Help::~Help()
{
}

void Help::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		Game::m_currentMode = GameMode::MainMenuScreen;
	}
}

void Help::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Yellow);
	t_window.draw(m_message);
	t_window.display();
}

void Help::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Blue);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Help");
	m_message.setFont(m_font);
}