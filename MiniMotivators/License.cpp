#include "License.h"
#include "Game.h"
#include "GameStates.h"


License::License()
{
}


License::~License()
{
}

void License::update(sf::Time t_deltaTime)
{
	m_timer+=1;
	if (m_timer > 30)
	{
		Game::m_currentMode = GameMode::SplashScreen;
	}
}

void License::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Yellow);
	t_window.draw(m_message);
	t_window.display();
}

void License::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Blue);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Made in c++ SFML");
	m_message.setFont(m_font);
}