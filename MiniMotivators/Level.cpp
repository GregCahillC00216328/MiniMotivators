#include "Level.h"
#include "Game.h"
#include "GameStates.h"
Level::Level()
{
}

Level::~Level()
{
}

void Level::update(sf::Time t_deltaTime, sf::Window &t_window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		Game::m_currentMode = GameMode::LoseScreen;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		Game::m_currentMode = GameMode::WinScreen;
	}


	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))//if mouse left click
	{
		sf::Vector2i mouseLocation;//store mouse location in the windoww
		mouseLocation = sf::Mouse::getPosition(t_window);//gets the mouse position from window
		
		for (int i = 0; i < 4; i++)
		{
			//m_mam[i].getGlobalBounds().intersects()
		}
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
		t_window.draw(m_shirtSquare[i]);
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

	if (!m_shirtTexture.loadFromFile("ASSETS/IMAGES/tShirt.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	if (!m_mamTexture.loadFromFile("ASSETS/IMAGES/mam.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	if (!m_dadTexture.loadFromFile("ASSETS/IMAGES/dad.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}

	srand(time(NULL));

	for (int i = 0; i < 4; i++)
	{
		m_dad[i].setSize(sf::Vector2f(120, 100));
		m_dad[i].setTexture(&m_dadTexture);
		m_dad[i].setFillColor(sf::Color::Blue);
		m_dad[i].setPosition(rand()% 600 + 50, rand()%500);

		m_mam[i].setSize(sf::Vector2f(120, 100));
		m_mam[i].setTexture(&m_mamTexture);
		m_mam[i].setFillColor(sf::Color::Red);
		m_mam[i].setPosition(m_dad[i].getPosition().x - 100, m_dad[i].getPosition().y);

		m_kid[i].setSize(sf::Vector2f(60, 80));
		m_kid[i].setTexture(&m_kidTexture);
		m_kid[i].setFillColor(sf::Color::Green);
		m_kid[i].setPosition(m_dad[i].getPosition().x + 70, m_dad[i].getPosition().y);
		
		m_shirtSquare[i].setSize(sf::Vector2f(60, 80));
		m_shirtSquare[i].setTexture(&m_shirtTexture);
		m_shirtSquare[i].setFillColor(sf::Color::Red);
		m_shirtSquare[i].setPosition(m_kid[i].getPosition().x, m_kid[i].getPosition().y);

		m_sequenceSquares[i].setSize(sf::Vector2f(60, 80));
		m_sequenceSquares[i].setFillColor(sf::Color::Red);
		m_sequenceSquares[i].setPosition(20 + 150 * i, 550);
		m_sequenceSquares[i].setTexture(&m_kidTexture);
	}
}
