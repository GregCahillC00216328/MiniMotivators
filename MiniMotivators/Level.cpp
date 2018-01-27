#include "Level.h"
#include "Game.h"
#include "GameStates.h"
Level::Level()
{
}

Level::~Level()
{
}

void Level::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		Game::m_currentMode = GameMode::LoseScreen;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		Game::m_currentMode = GameMode::WinScreen;
	}
}

void Level::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	t_window.draw(m_message);
	for (int i = 0; i < 4; i++)
	{
		t_window.draw(m_mam[i]);
		t_window.draw(m_dad[i]);
		t_window.draw(m_kid[i]);
		t_window.draw(m_sequenceSquares[i]);
	}
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
	if (!m_kidTexture.loadFromFile("ASSETS/IMAGES/kid2.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}

	for (int i = 0; i < 4; i++)
	{
		m_mam[i].setSize(sf::Vector2f(40, 40));
		m_mam[i].setFillColor(sf::Color::Red);
		m_mam[i].setPosition(20 + 50 * i, 70+50*i);

		m_dad[i].setSize(sf::Vector2f(45, 45));
		m_dad[i].setFillColor(sf::Color::Blue);
		m_dad[i].setPosition(70 + 50 * i, 20+50*i);

		m_kid[i].setSize(sf::Vector2f(60, 80));
		m_kid[i].setTexture(&m_kidTexture);
		m_kid[i].setFillColor(sf::Color::Green);
		m_kid[i].setPosition(0 + 90 * i, 350);
		

		//m_sequenceSquares[i].setSize(sf::Vector2f(40, 40));
		//m_sequenceSquares[i].setFillColor(sf::Color::Red);
		//m_sequenceSquares[i].setPosition(20 + 150 * i, 550);
		////m_sequenceSquares[i].setTexture()

		//m_fatherSquares[i].setSize(sf::Vector2f(50, 50));
		////	m_fatherSquares[i].setPosition();

	}
}
