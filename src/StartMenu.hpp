#ifndef __STARTMENU_H_
#define __STARTMENU_H_

#include "Scene.hpp"
#include "Essential.hpp"

class StartMenu : public Scene{
private:
	sf::Event event;
	sf::RenderWindow *wnd;
public:
	StartMenu(sf::RenderWindow *wnd);
	Essential::GameState Run();
};

#endif
