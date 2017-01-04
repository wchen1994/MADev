#ifndef __GAME_H_
#define __GAME_H_

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

#include "GameObject.hpp"

class Game{
private:
	sf::Event event;

public:
	static sf::RenderWindow wnd;
	static int wndHeight;
	static int wndWidth;
	static std::string wndName;
	static std::list<GameObject*> layerDefault;
	static std::list<GameObject*> layerDelete;

	Game();
	void Run();
	void Update();
};


#endif
