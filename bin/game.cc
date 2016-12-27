/*
A touhou like game
*/

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>

class Player{
private:
	sf::RenderWindow *wnd;
	sf::CircleShape Sprite;
public:
	Player(sf::RenderWindow *wnd) :
		Sprite(50)	
	{
		this->wnd = wnd;
	}
	void Update(){
		wnd->draw(Sprite);
	}
};

class Game{
private:
	sf::RenderWindow wnd;
	sf::Event event;
	Player player;
public:
	Game() :
		wnd(sf::VideoMode(800,600), "GAME"),
		player(&wnd)
	{
		wnd.setFramerateLimit(60);
	}

	void handleKeyPressed(sf::Event::KeyEvent key){
		sf::Keyboard::Key keycode = key.code;
		std::cout << keycode << std::endl;
	}

	void Run(){
		while(wnd.isOpen()){
			Update();
		}
	}

	void Update(){
		while(wnd.pollEvent(event)){
			switch (event.type){
				case sf::Event::KeyPressed:
					handleKeyPressed(event.key);
					break;
				case sf::Event::Closed:
					wnd.close();
					break;
				default:
					break;
			}
		}
		wnd.clear();
		player.Update();
		wnd.display();
	}
};


int main(){
	Game game;
	game.Run();

	return 0;
}
