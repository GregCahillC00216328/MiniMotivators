#pragma once

#include <SFML\Graphics.hpp>



class Win
{
public:
	Win();
	~Win();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
private:
	sf::Font m_font;
	sf::Text m_message;
};
