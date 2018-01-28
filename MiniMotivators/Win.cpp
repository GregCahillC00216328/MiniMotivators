#include "Win.h"
#include "Game.h"


Win::Win()
{
}


Win::~Win()
{
}

void Win::update(sf::Time t_deltaTime)
{
	
}

void Win::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	t_window.draw(m_message);
	t_window.display();
}

void Win::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Blue);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Congratulations, you won!!");
	m_message.setFont(m_font);
}