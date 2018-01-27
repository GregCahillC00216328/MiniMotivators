#pragma once
#include"SFML\Graphics.hpp"
#include<iostream>
class GamePlay
{
public:
	GamePlay();
	~GamePlay();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
private:
	sf::Font m_font;
	sf::Text m_message;
	int noOfFathers = 5;
	int m_timer = 0;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::RectangleShape m_sequenceSquares[5]; //squares used to display sequence/missing kids
	sf::RectangleShape m_fatherSquares[5];
	sf::RectangleShape m_motherSquares[5];
	sf::RectangleShape m_childSquares[5];
};