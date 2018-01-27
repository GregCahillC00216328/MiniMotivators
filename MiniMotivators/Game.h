#ifndef GAME
#define GAME
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameStates.h"
#include "License.h"
#include "Splash.h"
#include "MainMenu.h"
#include "LevelIntro.h"
#include "Help.h"
#include "Credits.h"
#include "Options.h"
#include "Level.h"
#include "Lose.h"
#include "Win.h"




/// <summary>
/// this class will control the overall game
/// not the gameplay that eill be a smaller part of the game
/// </summary>
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	// used to determin which screen we're on
	static GameMode m_currentMode;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();


	void setupAssets();
	License m_licenseScreen;
	Splash m_splashScreen;
	MainMenu m_mainMenuScreen; // menu screen
	LevelIntro m_levelIntroScreen; //Gives desrition of each level
	Help m_helpScreen;
	Credits m_creditsScreen;
	Options m_optionsScreen;
	Level m_levelScreen;
	Win m_winScreen;
	Lose m_loseScreen;
	//GamePlay m_gamePlayScreen; // gameplay object

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used all othet lcasses only loaded once and other classes
							   // use a refrence to this
	bool m_exitGame;			// control exiting game

};

#endif // !GAME