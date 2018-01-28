#pragma once
#include <SFML/Graphics.hpp>

class Level//Hi Greg
{
public:
	Level();
	~Level();
	void update(sf::Time t_deltaTime, sf::Window &t_window);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
private:
	sf::Font m_font;
	sf::Text m_message;
	sf::Sprite m_kidSprite;
	sf::Texture m_kidTexture;
	sf::Texture m_shirtTexture;
	sf::Texture m_mamTexture;
	sf::Texture m_dadTexture;

	sf::RectangleShape m_mam[4];
	sf::RectangleShape m_dad[4];
	sf::RectangleShape m_kid[4];

	sf::RectangleShape m_sequenceSquares[5]; //squares used to display sequence/missing kids
	sf::RectangleShape m_fatherSquares[5];
	sf::RectangleShape m_motherSquares[5];
	sf::RectangleShape m_kidSquares[5];
	sf::RectangleShape m_shirtSquare[5];
};
