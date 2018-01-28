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
	void mouseDetection(sf::RectangleShape t_rect, sf::Vector2i t_mouse);
private:
	sf::Font m_font;
	sf::Text m_message;
	sf::Sprite m_kidSprite;
	sf::Texture m_kidTexture;
	sf::Texture m_mamTexture;
	sf::Texture m_dadTexture;
	sf::Texture m_shirtTexture;

	sf::RectangleShape m_mam[6];
	sf::RectangleShape m_dad[6];
	sf::RectangleShape m_kid[6];

	sf::RectangleShape m_sequenceSquares[4]; //squares used to display sequence/missing kids
	sf::RectangleShape m_fatherSquares[6];
	sf::RectangleShape m_motherSquares[6];
	sf::RectangleShape m_kidSquares[6];
	sf::RectangleShape m_shirtSquare[6];

	sf::Color colourArray[10];
	bool used[10];
};
