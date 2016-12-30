/*
A touhou like game
*/

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>
#include<list>

class GameObject{
protected:
	sf::Vector2<float> position;
	sf::Vector2<float> velocity;
	sf::RenderWindow *wnd;
public:
	GameObject(sf::RenderWindow *wnd) :
		position(0,0),
		velocity(0,0)
	{
		this->wnd = wnd;
	}

	virtual void Draw(){
	}
	
	virtual void Update(){
		std::cout << "!" << std::endl;
		position += velocity;
		Draw();
	}

};

class Bullet{
private:
	sf::RenderWindow *wnd;
	sf::CircleShape sprite;
	float x, y;
	float dx, dy;
public:
	Bullet(sf::RenderWindow *wnd, float x, float y) :
		sprite()
	{
		this->wnd = wnd;
		this->x = x;
		this->y = y;
		this->dx = 0;
		this->dy = -5;

		sprite.setRadius(30);
		sprite.setPosition(x, y);
	}

	void Update(){
		x += dx;
		y += dy;
		sprite.setPosition(x, y);
	}

	void Draw(){
		wnd->draw(sprite);
	}
};

class Player : public GameObject{
private:
	sf::CircleShape sprite;
	float originX, originY;
	float radius;
	float speed;
	bool up, down, left, right;
public:
	Player(sf::RenderWindow *wnd) :
		GameObject(wnd),
		sprite()
	{
		this->wnd = wnd;
		radius = 5;
		position.x = 400;
		position.y = 300;
		velocity.x = 0;
		velocity.y = 0;
		speed = 3;
		originX = originY = radius;
		sprite.setRadius(radius);
		sprite.setOrigin(originX, originY);
		sprite.setPosition(position);
	}

	void Draw(){
		sprite.setPosition(position);
		wnd->draw(sprite);
	}

	void Update(){
		velocity.x = 0;
		velocity.y = 0;
		if (up)
			velocity.y -= 100;
		if (down)
			velocity.y += 100;
		if (left)
			velocity.x -= 100;
		if (right)
			velocity.x += 100;
		float sqlen = velocity.x*velocity.x + velocity.y*velocity.y;
		
		if (sqlen != 0){
			sqlen = sqrt(sqlen);
			position += velocity/sqlen * speed;
		}

		Draw();
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
	
	std::list<GameObject*> gameObjects;
	Player player;
	Bullet bullet;
public:
	Game() :
		wnd(sf::VideoMode(800,600), "GAME"),
		player(&wnd),
		bullet(&wnd, 400,600)
	{
		wnd.setFramerateLimit(60);
		gameObjects.push_back(&player);
	}

	// Trigge as the key just be pressed
	void handleKeyPressed(sf::Event::KeyEvent key){
		sf::Keyboard::Key keycode = key.code;
		switch (keycode){
			case sf::Keyboard::Up:
				player.SetUp(true);
				break;
			case sf::Keyboard::Down:
				player.SetDown(true);
				break;
			case sf::Keyboard::Left:
				player.SetLeft(true);
				break;
			case sf::Keyboard::Right:
				player.SetRight(true);
				break;
			default:
				break;
		}
	}

	void handleKeyReleased(sf::Event::KeyEvent key){
		sf::Keyboard::Key keycode = key.code;
		switch (keycode){
			case sf::Keyboard::Up:
				player.SetUp(false);
				break;
			case sf::Keyboard::Down:
				player.SetDown(false);
				break;
			case sf::Keyboard::Left:
				player.SetLeft(false);
				break;
			case sf::Keyboard::Right:
				player.SetRight(false);
				break;
			default:
				break;
		}
	}

	void Run(){ while(wnd.isOpen()){ Update();
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
		wnd.clear();

		for (std::list<GameObject*>::iterator it=gameObjects.begin();
			it != gameObjects.end(); it++){
			(*it)->Update();
		}
		bullet.Update();

		bullet.Draw();
		wnd.display();
	}
};


int main(){
	Game game;
	game.Run();

	return 0;
}
