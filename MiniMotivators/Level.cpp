#include "Level.h"

Level::Level()
{
}

Level::~Level()
{
}

void Level::update(sf::Time t_deltaTime)
{
}

void Level::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Red);
	t_window.draw(m_message);
	t_window.display();
}

void Level::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Level");
	m_message.setFont(m_font);
}
