#include "Game.hpp"

sf::RenderWindow Game::wnd(sf::VideoMode(800, 600), "Game");
std::list<GameObject*> Game::layerDefault;
std::list<GameObject*> Game::layerDelete;

Game::Game()
{
	wnd.setFramerateLimit(60);
}

void Game::Run(){ 
	while(wnd.isOpen()){ 
		Update();
	}
}

void Game::Update(){
	while(wnd.pollEvent(event)){
		switch (event.type){
			case sf::Event::KeyPressed:
				for (std::list<GameObject*>::iterator it=layerDefault.begin();
				it != layerDefault.end(); it++){
					(*it)->OnKeyPressed(event.key);
				}
				break;
			case sf::Event::KeyReleased:
				for (std::list<GameObject*>::iterator it=layerDefault.begin();
				it != layerDefault.end(); it++){
					(*it)->OnKeyReleased(event.key);
				}
				break;
			case sf::Event::Closed:
				wnd.close();
				break;
			default:
				break;
		}
	}

	wnd.clear();

	for (std::list<GameObject*>::iterator it=layerDefault.begin();
		it != layerDefault.end(); it++){
		(*it)->Update();
	}

	for (std::list<GameObject*>::iterator it=layerDefault.begin();
		it != layerDefault.end(); it++){
		(*it)->Draw();
	}

	while(!layerDelete.empty()){
		layerDefault.remove(layerDelete.front());
		delete layerDelete.front();
		layerDelete.pop_front();
	}

	wnd.display();
}
