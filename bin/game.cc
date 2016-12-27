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

void handleKeyPressed(sf::Event::KeyEvent key){
	sf::Keyboard::Key keycode = key.code;
	std::cout << keycode << std::endl;
}

int main(){
	sf::RenderWindow wnd(sf::VideoMode(800,600), "GAME");
	wnd.setFramerateLimit(60);

	Player player(&wnd);

	while(wnd.isOpen()){
		sf::Event event;
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

	return 0;
}
