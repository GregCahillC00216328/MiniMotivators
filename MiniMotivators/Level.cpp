#include "Level.h"
#include "Game.h"
#include "GameStates.h"
Level::Level()
{
	srand(time(NULL));
}

Level::~Level()
{
}

void Level::update(sf::Time t_deltaTime, sf::Window &t_window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		Game::m_currentMode = GameMode::LoseScreen;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		Game::m_currentMode = GameMode::WinScreen;
	}
	
	if (timer = 300)
	{
		for (int i = 0; i < 4; i++)
		{
			moveVec[i] = sf::Vector2f((rand() % 9 + 1) - 5, (rand() % 9 + 1) - 5);
		}
		
		timer = 0;
	}
	timer++;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))//if mouse left click
	{
		sf::Vector2i mouseLocation;//store mouse location in the windoww
		mouseLocation = sf::Mouse::getPosition(t_window);//gets the mouse position from window

		for (int i = 0; i < 4; i++)
		{
			m_currentIndex = i;
			mouseDetection(m_mam[i], static_cast<sf::Vector2f>(mouseLocation),t_window);
			mouseDetection(m_dad[i], static_cast<sf::Vector2f>(mouseLocation),t_window);
			mouseDetection(m_kid[i], static_cast<sf::Vector2f>(mouseLocation),t_window);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		
		
		movement(m_mam[i],moveVec[i]);
		movement(m_dad[i], moveVec[i]);
		if (!inPlace[i])
		{
			if (clicked[i] == false)
			{
				movement(m_kid[i], moveVec[i]);
				movement(m_shirtSquare[i], moveVec[i]);
			}
			if (clicked[i])
			{
				displacement.x = ((displacement.x ) * (rand() % 2) - 1)*0.2;
				displacement.x = ((displacement.y ) * (rand() % 2) - 1)*0.2;
				m_kid[i].setPosition(m_kid[i].getPosition() + displacement);
				m_shirtSquare[i].setPosition(m_shirtSquare[i].getPosition() + displacement);


			}
		}
		
		clicked[i] = false;
	}

	
}

void Level::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	t_window.draw(m_message);
	for (int i = 0; i < 4; i++)
	{
		t_window.draw(m_mam[i]);
		t_window.draw(m_dad[i]);
		t_window.draw(m_kid[i]);
		t_window.draw(m_shirtSquare[i]);
		t_window.draw(m_sequenceSquares[i]);
	}
	
	t_window.display();
}

void Level::setup(sf::Font & t_font)
{

	loadVoices();
	colourArray[0] = sf::Color::Red;
	colourArray[1] = sf::Color::Blue;
	colourArray[2] = sf::Color::Yellow;
	colourArray[3] = sf::Color::Green;
	colourArray[4] = { 153, 51, 255 };
	colourArray[5] = { 255, 128, 0 };
	colourArray[6] = { 255, 0, 255 };
	colourArray[7] = { 160, 160, 160 };
	colourArray[8] = sf::Color::Magenta;
	colourArray[9] = sf::Color::Cyan;


	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Level");
	m_message.setFont(m_font);
	if (!m_kidTexture.loadFromFile("ASSETS/IMAGES/kid2.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}

	if (!m_shirtTexture.loadFromFile("ASSETS/IMAGES/tShirt.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	if (!m_mamTexture.loadFromFile("ASSETS/IMAGES/mam.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	if (!m_dadTexture.loadFromFile("ASSETS/IMAGES/dad.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	srand(time(NULL));
	for (int i = 0; i < 4; i++)

	{
		m_dad[i].setSize(sf::Vector2f(120, 100));
		m_dad[i].setTexture(&m_dadTexture);
		m_dad[i].setFillColor(sf::Color::Blue);
		m_dad[i].setPosition(rand()% 600 + 50, rand()%500);


		m_mam[i].setSize(sf::Vector2f(120, 100));
		m_mam[i].setTexture(&m_mamTexture);
		m_mam[i].setFillColor(sf::Color::Red);
		m_mam[i].setPosition(m_dad[i].getPosition().x - 100, m_dad[i].getPosition().y);

		m_kid[i].setSize(sf::Vector2f(60, 80));
		m_kid[i].setTexture(&m_kidTexture);
		m_kid[i].setFillColor(sf::Color::Green);
		m_kid[i].setPosition(m_dad[i].getPosition().x + 70, m_dad[i].getPosition().y);

		m_shirtSquare[i].setSize(sf::Vector2f(60, 80));
		m_shirtSquare[i].setTexture(&m_shirtTexture);		
		m_shirtSquare[i].setFillColor(colourArray[rand()%10]);
		m_shirtSquare[i].setPosition(m_kid[i].getPosition().x, m_kid[i].getPosition().y);

		m_sequenceSquares[i].setSize(sf::Vector2f(60, 80));
		m_sequenceSquares[i].setFillColor(m_shirtSquare[i].getFillColor());
		m_sequenceSquares[i].setPosition(20 + 150 * i, 550);
		m_sequenceSquares[i].setTexture(&m_kidTexture);
	}

}

void Level::mouseDetection(sf::RectangleShape t_rect,sf::Vector2f mouseLocation,sf::Window &t_window)
{
	if (mouseLocation.x > t_rect.getPosition().x &&
		mouseLocation.x < t_rect.getPosition().x + t_rect.getGlobalBounds().width &&
		mouseLocation.y > t_rect.getPosition().y &&
		mouseLocation.y < t_rect.getPosition().y + t_rect.getGlobalBounds().height)
	{
		//Play appropriate sound here
		std::cout << "Test" << std::endl << std::endl;
		if (t_rect.getTexture() == &m_dadTexture)
		{
			m_currentVoice = Voice::Daddy;
		}
		if (t_rect.getTexture() == &m_mamTexture)
		{
			m_currentVoice = Voice::Mammy;
		}
		if (t_rect.getTexture() == &m_kidTexture)
		{
			m_currentVoice = Voice::Baby;
			displacement.x = (((0) + (sf::Mouse::getPosition(t_window).x))-t_rect.getPosition().x);
			displacement.y = (((0) + (sf::Mouse::getPosition(t_window).y)) - t_rect.getPosition().y);
			//t_rect.setPosition(sf::Mouse::getPosition(t_window).x, sf::Mouse::getPosition(t_window).y);
			clicked[m_currentIndex] = true;
			if (m_kid[m_currentIndex].getGlobalBounds().intersects(m_sequenceSquares[m_currentIndex].getGlobalBounds()))
			{
				inPlace[m_currentIndex] = true;
			}
		}
		
		
		playOoh(m_currentIndex, m_currentVoice);
		//m_currentIndex = std::rand() % NO_OOHS;
		

	}
}

void Level::movement(sf::RectangleShape &t_rect, sf::Vector2f t_moveVec)
{
	
	if (t_rect.getPosition().x <= 0 || t_rect.getPosition().x >= 400)
	{
		t_moveVec.x = t_moveVec.x*-1;
	}
	if (t_rect.getPosition().y <= 0 || t_rect.getPosition().y >= 760)
	{
		t_moveVec.y = t_moveVec.y*-1;
	}
	t_rect.setPosition(t_rect.getPosition() + t_moveVec);
	if (t_rect.getPosition().y > 300)
	{
		t_rect.setPosition(t_rect.getPosition().x, t_rect.getPosition().y - 5);
	}
}

void Level::playOoh(int t_index, Voice t_voice)
{
	switch (t_voice)
	{
	case Voice::Daddy:
		m_oohSounds[m_currentIndex].setPitch(1.0f);
		break;
	case Voice::Mammy:
		m_oohSounds[m_currentIndex].setPitch(1.3f);
		break;
	case Voice::Baby:
		m_oohSounds[m_currentIndex].setPitch(1.8f);
		break;
	default:
		break;
	}
	m_oohSounds[m_currentIndex].play();
}

void Level::loadVoices()
{
	for (size_t i = 0; i < NO_OOHS; i++)
	{
		if (!m_oohSoundBuffers[i].loadFromFile("ASSETS\\Audio\\ooh" + std::to_string(i) + ".ogg"))
		{
			std::cout << "Problem with ooh sounds" << std::endl;

		}
		else
		{
			m_oohSounds[i].setBuffer(m_oohSoundBuffers[i]);
		}
	}
}

