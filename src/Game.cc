#include <cstdlib>

#include "Game.hpp"
#include "Board.hpp" 
#include "Player.hpp" 
#include "Enemy.hpp"

sf::RenderWindow Game::wnd(sf::VideoMode(800, 600), "Game");

Game::Game()
{
	wnd.setFramerateLimit(60);
}

void Game::Run(){ 
	GameObject::layerDefault.push_back(new Player(&wnd));

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

	GameObject::layerDefault.push_back(new Enemy(&wnd, rand()%800, 0,
											rand()%100-50, rand()%50));

	wnd.clear();

	for (std::list<GameObject*>::iterator it=GameObject::layerDefault.begin();
		it != GameObject::layerDefault.end(); it++){
		(*it)->Update();
	}

	//GameObject::layerDefault.push_back(new Enemy(&wnd, 50, 50));
	for (std::list<GameObject*>::iterator it=GameObject::layerDefault.begin();
		it != --GameObject::layerDefault.end(); it++){
		for (std::list<GameObject*>::iterator it2=it;
			it2 != GameObject::layerDefault.end(); it2++){
			if(it != it2){
				sf::Vector2<float> diffPos = (*it)->getPosition() - (*it2)->getPosition();
				float len = (*it)->getSize() + (*it2)->getSize();
				if (diffPos.x*diffPos.x + diffPos.y*diffPos.y <= len*len)
					(*it)->OnCollisionEnter(*it2);
			}
		}
	}


	for (std::list<GameObject*>::iterator it=GameObject::layerDefault.begin();
		it != GameObject::GameObject::layerDefault.end(); it++){
		(*it)->Draw();
	}

	while(!GameObject::layerDelete.empty()){
		GameObject::layerDefault.remove(GameObject::layerDelete.front());
		delete GameObject::layerDelete.front();
		GameObject::layerDelete.pop_front();
	}

//	std::cout << '\r';
//	std::cout << "layerDefault size: " << GameObject::layerDefault.size();

	wnd.display();
}
