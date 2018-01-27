#include "Credits.h"
#include "Game.h"
#include "GameStates.h"
Credits::Credits()
{
}

Credits::~Credits()
{
}

void Credits::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		Game::m_currentMode = GameMode::MainMenuScreen;
	}
}

void Credits::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	t_window.draw(m_message);
	t_window.display();
}

void Credits::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Credits");
	m_message.setFont(m_font);
}
