#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Splash
{
public:
	Splash();
	~Splash();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
private:
	sf::Font m_font;
	sf::Text m_message;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};
