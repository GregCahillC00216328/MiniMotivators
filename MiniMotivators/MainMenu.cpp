#include"MainMenu.h"
#include "Game.h"
#include "GameStates.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(sf::Time t_deltaTime, sf::Window &t_window)
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		Game::m_currentMode = GameMode::LevelIntroScreen;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		Game::m_currentMode = GameMode::OptionsScreen;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		Game::m_currentMode = GameMode::HelpScreen;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		Game::m_currentMode = GameMode::CreditsScreen;
	}*/

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))//if mouse left click
	{
		sf::Vector2i mouseLocation;//store mouse location in the windoww
		mouseLocation = sf::Mouse::getPosition(t_window);//gets the mouse position from window
		if (mouseLocation.x > m_leftOffset && mouseLocation.x < m_leftOffset + m_buttonWidth)//if mouse is inside button x parameters
		{
			if (mouseLocation.y > m_topOffset && mouseLocation.y && mouseLocation.y <  m_topOffset + m_buttonHeight)//if top button
			{
				Game::m_currentMode = GameMode::LevelIntroScreen;//sets mode to gameplay
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing && mouseLocation.y <  m_topOffset + m_verticalSpacing + m_buttonHeight)//2nd button
			{
				Game::m_currentMode = GameMode::HelpScreen;//opens help menu
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 2 && mouseLocation.y <  m_topOffset + m_verticalSpacing * 2 + m_buttonHeight)//3rd button
			{
				Game::m_currentMode = GameMode::OptionsScreen;//sets mode to garage
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 3 && mouseLocation.y <  m_topOffset + m_verticalSpacing * 3 + m_buttonHeight)
			{
				Game::m_currentMode = GameMode::CreditsScreen;//sets game mode to mission
			}
		}
	}
}

void MainMenu::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	t_window.draw(backgroundSquare);
	for (int i = 0; i < m_optionCount; i++)
	{
		//draw buttons and text
		t_window.draw(m_buttonSprites[i]);
	}
	t_window.display();
}

void MainMenu::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Main Menu");
	m_message.setFont(m_font);


	//variables used to set buttons
	m_topOffset = 20;
	m_verticalSpacing = 150;
	m_buttonWidth = 350;
	m_leftOffset = (800 - m_buttonWidth) / 2;
	m_buttonHeight = 100;
	int textDropOffset = 10;
	if (!m_buttonTexture[0].loadFromFile("ASSETS/IMAGES/Level.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	if (!m_buttonTexture[1].loadFromFile("ASSETS/IMAGES/Help.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	if (!m_buttonTexture[2].loadFromFile("ASSETS/IMAGES/Options.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	if (!m_buttonTexture[3].loadFromFile("ASSETS/IMAGES/Credits.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	
	for (int i = 0; i < m_optionCount; i++)//loops number of times = noOFButtons
	{
		//set up sprite/buttons
		m_buttonSprites[i].setTexture(m_buttonTexture[i]);//sets texture for button to loaded image
		m_buttonSprites[i].setPosition(m_leftOffset, m_verticalSpacing * i + m_topOffset);//setsposition of button
		sf::Vector2u textureSize = m_buttonTexture[i].getSize();//gets size for scale
		m_buttonSprites[i].setScale(m_buttonWidth / textureSize.x, m_buttonHeight / textureSize.y);//sets scale
	}

	if (!m_background.loadFromFile("ASSETS/IMAGES/main.jpg"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	backgroundSquare.setPosition(0, 0);
	backgroundSquare.setSize(sf::Vector2f(800, 600));
	backgroundSquare.setTexture(&m_background);
}
