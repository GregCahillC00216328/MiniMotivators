#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <cstdlib>
#include <ctime>
const int NO_OOHS = 26;
const int MAX_PEOPLE = 12;

enum class Voice
{
	Daddy,
	Mammy,
	Baby
};
class Level//Hi Greg
{
public:
	
	Level();
	~Level();
	void update(sf::Time t_deltaTime, sf::Window &t_window);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
	void processEvents(sf::Event &t_event,sf::Window &t_window);
	void mouseDetection(sf::RectangleShape t_rect, sf::Vector2f mouseLocation, sf::Window &t_window);
	void movement(sf::RectangleShape &t_rect, sf::Vector2f t_moveVec);
private:
	sf::Font m_font;
	sf::Text m_message;
	sf::Sprite m_kidSprite;
	sf::Texture m_kidTexture;
	sf::Texture m_mamTexture;
	sf::Texture m_dadTexture;
	sf::Texture m_shirtTexture;
	sf::Color colourArray[10];
	

	sf::RectangleShape m_mam[MAX_PEOPLE];
	sf::RectangleShape m_dad[MAX_PEOPLE];
	sf::RectangleShape m_kid[MAX_PEOPLE];
	sf::RectangleShape m_shirtSquare[MAX_PEOPLE];
	sf::RectangleShape m_sequenceSquares[5]; //squares used to display sequence/missing kids
	int timer = 300;
	int timer2 = 300;
	sf::Vector2f moveVec[12];
	bool clicked[12]{ false,false,false,false };
	bool inPlace[12]{ false,false,false,false };
	bool haveChild[12] = { false,false,false,false };

	
	
	sf::SoundBuffer m_oohSoundBuffers[NO_OOHS];
	sf::Sound m_oohSounds[NO_OOHS];
	void playOoh(int t_index, Voice t_voice);
	void loadVoices();
	int m_currentIndex = 0;
	Voice m_currentVoice{ Voice::Daddy };
	sf::Vector2f displacement{0,0};
	sf::RectangleShape m_backgroundSquare;
	sf::Texture m_backTexture;
};
