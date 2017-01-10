#include "Game.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

sf::RenderWindow Game::wnd(sf::VideoMode(800, 600), "Game");

Game::Game()
{
	wnd.setFramerateLimit(60);
}

void Game::Run(){ 
	GameObject::layerDefault.push_back(new Player(&wnd));
	GameObject::layerDefault.push_back(new Bullet(&wnd, 300, 400));
	std::cout << &GameObject::layerDefault << std::endl;
	while(wnd.isOpen()){ 
		Update();
	}
}

void Game::Update(){
	while(wnd.pollEvent(event)){
		switch (event.type){
			case sf::Event::KeyPressed:
				for (std::list<GameObject*>::iterator it=GameObject::layerDefault.begin();
				it != GameObject::layerDefault.end(); it++){
					(*it)->OnKeyPressed(event.key);
				}
				break;
			case sf::Event::KeyReleased:
				for (std::list<GameObject*>::iterator it=GameObject::layerDefault.begin();
				it != GameObject::layerDefault.end(); it++){
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

	for (std::list<GameObject*>::iterator it=GameObject::layerDefault.begin();
		it != GameObject::layerDefault.end(); it++){
		(*it)->Update();
	}

	for (std::list<GameObject*>::iterator it=GameObject::layerDefault.begin();
		it != GameObject::GameObject::layerDefault.end(); it++){
		(*it)->Draw();
	}

	while(!GameObject::layerDelete.empty()){
		GameObject::layerDefault.remove(GameObject::layerDelete.front());
		delete GameObject::layerDelete.front();
	GameObject::	GameObject::layerDelete.pop_front();
	}

	std::cout << '\r';
	std::cout << "layerDefault size: " << GameObject::layerDefault.size();

	wnd.display();
}
