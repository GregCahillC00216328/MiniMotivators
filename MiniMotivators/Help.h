#pragma once

#include <SFML\Graphics.hpp>



class Help
{
public:
	Help();
	~Help();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
private:
	sf::Font m_font;
	sf::Text m_message;
};
