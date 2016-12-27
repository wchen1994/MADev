/*
A touhou like game
*/

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>

class Player{
private:
	sf::RenderWindow *wnd;
	sf::CircleShape sprite;
	float x, y;
	float originX, originY;
	float radius;
public:
	Player(sf::RenderWindow *wnd) :
		sprite()
	{
		this->wnd = wnd;
		radius = 50;
		x = 400;
		y = 300;
		originX = originY = radius;
		sprite.setRadius(radius);
		sprite.setOrigin(originX, originY);
		sprite.setPosition(x, y);
	}

	void Draw(){
		wnd->draw(sprite);
	}

	void Move(float dx, float dy){
		x += dx;
		y += dy;
		sprite.setPosition(x, y);
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
		switch (keycode){
			case sf::Keyboard::W:
				player.Move(0,-30);
				break;
			case sf::Keyboard::S:
				player.Move(0,30);
				break;
			case sf::Keyboard::A:
				player.Move(-30,0);
				break;
			case sf::Keyboard::D:
				player.Move(30,0);
				break;
			default:
				break;
		}
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
		player.Draw();
		wnd.display();
	}
};


int main(){
	Game game;
	game.Run();

	return 0;
}
