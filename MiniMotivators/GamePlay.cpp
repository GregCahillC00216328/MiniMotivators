#include"GamePlay.h"

GamePlay::GamePlay()
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime)
{
}

void GamePlay::render(sf::RenderWindow & t_window)
{
	t_window.clear();
	for (int i = 0; i < 0; i++)
	{
		t_window.draw(m_sequenceSquares[i]);
	}
}

void GamePlay::setup(sf::Font & t_font)
{
	for(int i = 0; i < 5; i++)
	{ 
		m_sequenceSquares[i].setSize(sf::Vector2f(40, 40));
		m_sequenceSquares[i].setFillColor(sf::Color::Red);
		m_sequenceSquares[i].setPosition(20 + 50 * i, 550);
		//m_sequenceSquares[i].setTexture()

		m_fatherSquares[i].setSize(sf::Vector2f(50, 50));
		//m_fatherSquares[i].setPosition()
	}
}
