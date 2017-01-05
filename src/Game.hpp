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
	static std::list<GameObject*> layerDefault;
	static std::list<GameObject*> layerDelete;
	static std::list<GameObject*> layerKey;

public:
	Game();
	void Run();
	void Update();
};


#endif
