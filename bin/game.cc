/*
A touhou like game
*/

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>

class Player{
private:
	sf::RenderWindow *wnd;
	sf::CircleShape sprite;
	float x, y;
	float dx, dy;
	float originX, originY;
	float radius;
	float speed;
	bool up, down, left, right;
public:
	Player(sf::RenderWindow *wnd) :
		sprite()
	{
		this->wnd = wnd;
		radius = 50;
		x = 400;
		y = 300;
		dx = dy = 0;
		speed = 10;
		originX = originY = radius;
		sprite.setRadius(radius);
		sprite.setOrigin(originX, originY);
		sprite.setPosition(x, y);
	}

	void Draw(){
		wnd->draw(sprite);
	}

	void Update(){
		dx = dy = 0;
		if (up)
			dy -= 100;
		if (down)
			dy += 100;
		if (left)
			dx -= 100;
		if (right)
			dx += 100;
		float sqlen =dx * dx + dy * dy;
		
		if (sqlen != 0){
			sqlen = sqrt(sqlen);
			x += dx/sqlen * speed;
			y += dy/sqlen * speed;
		}
		std::cout << x << ' ' << y << std::endl;
		sprite.setPosition(x, y);
	}

	void SetUp(bool status){
		up = status;
	}

	void SetDown(bool status){
		down = status;
	}

	void SetLeft(bool status){
		left = status;
	}

	void SetRight(bool status){
		right = status;
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

	// Trigge as the key just be pressed
	void handleKeyPressed(sf::Event::KeyEvent key){
		sf::Keyboard::Key keycode = key.code;
		switch (keycode){
			case sf::Keyboard::W:
				player.SetUp(true);
				break;
			case sf::Keyboard::S:
				player.SetDown(true);
				break;
			case sf::Keyboard::A:
				player.SetLeft(true);
				break;
			case sf::Keyboard::D:
				player.SetRight(true);
				break;
			default:
				break;
		}
	}

	void handleKeyReleased(sf::Event::KeyEvent key){
		sf::Keyboard::Key keycode = key.code;
		switch (keycode){
			case sf::Keyboard::W:
				player.SetUp(false);
				break;
			case sf::Keyboard::S:
				player.SetDown(false);
				break;
			case sf::Keyboard::A:
				player.SetLeft(false);
				break;
			case sf::Keyboard::D:
				player.SetRight(false);
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
				case sf::Event::KeyReleased:
					handleKeyReleased(event.key);
					break;
				case sf::Event::Closed:
					wnd.close();
					break;
				default:
					break;
			}
		}
		player.Update();

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
