#ifndef __GAME_H_
#define __GAME_H_

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

#include "GameObject.hpp"

class Game{
private:
	sf::Event event;
	static sf::RenderWindow wnd;

public:
	Game();
	void Run();
	void Update();
};

#endif
