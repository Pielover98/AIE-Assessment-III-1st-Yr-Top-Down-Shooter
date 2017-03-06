

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>

#include "IOstuff.h"
#include "Music.h"
#include "GameState.h"

//including the Gamestate-Headers
#include "MenuState.h"
#include "PlayState.h"
#include "Intro.h"
#include "Highscore.h"
#include "HighscoreList.h"
#include "Settings.h"
#include "DiffSet.h"
#include "graphics.h"
#include "SoundSet.h"
#include "SplashState.h"

class Game{
public:
	 Game();
	~Game();

	enum class gameStates{ MAINMENU, INTRO, PLAY, SETTINGS, graphics, SOUNDSET, DIFFSET, HIGHSCORE, HIGHSCORELIST, SPLASHSTATE};

	void Run();
	void ChangeState(gameStates newState);

	const bool isRunning(){ return running; };
	const bool getIntroPlayed(){ return playedIntro; };
	const int getVolume(){ return volume; };

	void setRunning(bool mRunning);
	void setIntroPlayed(bool played){ playedIntro = played; };
	void setVolume(int &iVolume);

	sf::RenderWindow	window;
	HighscoreManager	highscore;

private:
	void Quit();
	void Update();
	void HandleEvents();
	void Render();

	void checkScreenSet();

	std::unique_ptr<GameState> CurrentState;
	IOscreen	ioscreen;
	IOsound		iosound;
	IngameMusic ingMusic;
	MenuMusic	menMusic;
	
	int volume;
	bool running;
	bool playedIntro;
};

#endif