#ifndef __ESSENTIAL_H_
#define __ESSENTIAL_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Essential{
public:
	static bool isGameOver;
	static bool isExit;
	enum GameState{MENU, GAME, POP};
	static GameState gameState;
	static sf::RenderWindow wnd;
	static void defHandleMsg(const sf::Event &eventType);
};

#endif
