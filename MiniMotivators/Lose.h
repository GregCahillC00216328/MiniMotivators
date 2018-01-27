#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

const int NUM_EXERCISE = 6;

class Lose
{
public:
	Lose();
	~Lose();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
	int m_clipNo;
private:
	sf::Font m_font;
	sf::Text m_message;
	sf::SoundBuffer testbuffer;
	sf::SoundBuffer m_excercisesAudioBuf[NUM_EXERCISE];
	sf::Sound m_exerciseSounds[NUM_EXERCISE];
};
