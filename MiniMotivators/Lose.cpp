#include "Lose.h"
#include "Game.h"
#include <string.h>


Lose::Lose()
{
}


Lose::~Lose()
{
}

void Lose::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

	}
	sf::Sound::Status stat = m_exerciseSounds[m_clipNo].getStatus();


	if ( stat == sf::Sound::Stopped)
	{
		m_exerciseSounds[m_clipNo].play();
	
	}
}

void Lose::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Magenta);
	t_window.draw(m_message);
	t_window.display();
}

void Lose::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Blue);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("You lost \n press space to go to menu");
	m_message.setFont(m_font);
	
	for (size_t i = 0; i < NUM_EXERCISE; i++)
	{
		if (!m_excercisesAudioBuf[i].loadFromFile("assets//audio//conversation" + std::to_string(i) + ".ogg"))
		{
			std::cout << "problem loading conversation" << std::endl;
		}		
		m_exerciseSounds[i].setBuffer(m_excercisesAudioBuf[i]);
	}
	m_clipNo = std::rand() % NUM_EXERCISE;
}