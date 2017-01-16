#include "StartMenu.hpp"
#include "Essential.hpp"

StartMenu::StartMenu(sf::RenderWindow *wnd){
	this->wnd = wnd;
}

Essential::GameState StartMenu::Run(){
	while(wnd->isOpen()){
		while(wnd->pollEvent(event)){
			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::Return){
					Essential::isGameOver = false;
					return Essential::GAME;
				}
			}
			if (event.type == sf::Event::Closed){
				wnd->close();
			}
		}
		wnd->clear(sf::Color(255,255,255));
		wnd->display();
	}
	return Essential::POP;
}
