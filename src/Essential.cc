#include <iostream>
#include "Essential.hpp"

bool Essential::isGameOver = false;
bool Essential::isExit = false;
Essential::GameState Essential::gameState = GAME;
sf::RenderWindow Essential::wnd(sf::VideoMode(800, 600), "Game");
void Essential::defHandleMsg(const sf::Event &event){
	switch(event.type){
		case sf::Event::Closed:
			Essential::wnd.close();
			break;
		case sf::Event::Resized:
//Essential::wnd.setSize(sf::Vector2<uint>(event.size.width, event.size.height));
			break;
		default:
			break;
	}
}
