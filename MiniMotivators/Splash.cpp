#include"Splash.h"
#include"game.h"
Splash::Splash()
{
}


Splash::~Splash()
{
}


void Splash::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Game::m_currentMode = GameMode::MainMenuScreen;
	}
}

void Splash::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Red);
	t_window.draw(m_sprite);
	t_window.draw(m_message);
	t_window.display();
}

void Splash::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("'Fuck the mainstream!'\n press any key to go to menu");//yurt
	m_message.setFont(m_font);

	if (!m_texture.loadFromFile("ASSETS\\Capture.PNG"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading sprite" << std::endl;
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(175, 100);
}
