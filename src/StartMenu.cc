#include "StartMenu.hpp"
#include "Essential.hpp"

StartMenu::StartMenu(sf::RenderWindow *wnd){
	this->wnd = wnd;
}

Essential::GameState StartMenu::Run(){
	while(wnd->isOpen()){
		while(wnd->pollEvent(event)){
			switch(event.type){
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Return){
						Essential::isGameOver = false;
						return Essential::GAME;
					}
					break;
				default:
					Essential::defHandleMsg(event);
			}
		}
		wnd->clear(sf::Color(255,255,255));
		wnd->display();
	}
	return Essential::POP;
}
