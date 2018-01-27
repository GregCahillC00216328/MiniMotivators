#include"Splash.h"
#include "Game.h"
#include "GameStates.h"

Splash::Splash()
{
}


Splash::~Splash()
{
}


void Splash::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Game::m_currentMode = GameMode::MainMenuScreen;
	}
}

void Splash::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Red);
	t_window.draw(m_sprite);
	t_window.draw(m_message);
	t_window.display();
}

void Splash::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("'Looking'~Corita Kent\n pete was here \n press any key to go to menu");
	m_message.setFont(m_font);

	if (!m_texture.loadFromFile("ASSETS//CAPTURE.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading sprite" << std::endl;
	}
	m_sprite.setTexture(m_texture);
}