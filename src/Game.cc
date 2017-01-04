#include "Game.hpp"

int Game::wndWidth = 800;
int Game::wndHeight = 600;
std::string Game::wndName = "Game";
sf::RenderWindow Game::wnd(
	sf::VideoMode(Game::wndWidth, Game::wndHeight), 
	Game::wndName);
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

	while(!layerDelete.empty()){
		layerDefault.remove(layerDelete.front());
		delete layerDelete.front();
		layerDelete.pop_front();
	}

	wnd.display();
}
