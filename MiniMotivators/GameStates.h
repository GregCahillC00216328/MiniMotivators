#ifndef GLOBALS
#define GLOBALS

/// <summary>
/// this enum will hold the different modes/screens the game be in
/// </summary>
enum class  GameMode
{
	LicenseScreen,
	SplashScreen,
	MainMenuScreen,
	HelpScreen,
	OptionsScreen,
	PlayScreen,
	LoseScreen,
	WinScreen,
	CreditsScreen,
	LevelScreen,
	LevelIntroScreen,
	GamePlayScreen

};

const int MAX_ASTEROIDS = 5; // user for pool of asteroids some alive some dead (re-use dead ones)

#endif // !GLOBALS
