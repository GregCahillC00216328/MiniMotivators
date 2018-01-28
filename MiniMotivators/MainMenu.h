#pragma once
#include <SFML/Graphics.hpp>

class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void update(sf::Time t_deltaTime, sf::Window &t_window);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
private:
	sf::Font m_font;
	sf::Text m_message;
	sf::RectangleShape menuButtons[4];
	/// Number of buttons on our menu
	static const int m_optionCount = 5;
	/// green button background
	sf::Texture m_buttonTexture[4];
	/// array of sprites used to display buttons
	sf::Sprite m_buttonSprites[m_optionCount];

	sf::Texture m_background;
	sf::RectangleShape backgroundSquare;

	/// top left of area usde for menu
	float m_topOffset;
	/// top left of area usde for menu
	float m_leftOffset;
	/// gap in pixels between tops of buttons
	float m_verticalSpacing;
	/// width in pixels of all buttons
	float m_buttonWidth;
	/// height of button in pixels must be less than vertical spacing
	float m_buttonHeight;
};
