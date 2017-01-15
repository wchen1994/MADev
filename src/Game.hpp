#ifndef __GAME_H_
#define __GAME_H_

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

#include "GameObject.hpp"
#include "Scene.hpp"
#include "Essential.hpp"

class Game : public Scene{
private:
	sf::Event event;
	sf::RenderWindow *wnd;

public:
	Game(sf::RenderWindow *wnd);
	Essential::GameState Run();
	void Update();
};

#endif
