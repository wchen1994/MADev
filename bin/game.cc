/*
A touhou like game
*/

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>
#include<list>
#include<cstdlib>

#include "GameObject.hpp"

//class GameObject{
//protected:
//	sf::Vector2<float> position;
//	sf::Vector2<float> velocity;
//	sf::RenderWindow *wnd;
//public:
//	GameObject(sf::RenderWindow *wnd) :
//		position(0,0),
//		velocity(0,0)
//	{
//		this->wnd = wnd;
//	}
//
//	~GameObject(){};
//
//	virtual void Draw(){
//	}
//	
//	virtual void Update(){
//		position += velocity;
//		Draw();
//	}
//
//};

std::list<GameObject*> gameObjects;
std::list<GameObject*> deleteLayer;

class Enemy : public GameObject{
private:
	sf::RenderWindow *wnd;
	sf::CircleShape sprite;
	float radius;
public:
	Enemy(sf::RenderWindow *wnd, float x) :
		GameObject(wnd),
		sprite()
	{
		this->wnd = wnd;
		position.x = x;
		position.y = 0;
		velocity.x = 0;
		velocity.y = 2;
		radius = 10;
		sprite.setRadius(radius);
		sprite.setPosition(position);
		sprite.setOrigin(radius, radius);
	}

	void Update(){
		position += velocity;
		Draw();
	}

	void Draw(){
		sprite.setPosition(position);
		wnd->draw(sprite);
	}
};

class Bullet : public GameObject{
private:
	sf::RenderWindow *wnd;
	sf::CircleShape sprite;
	float radius;
public:
	Bullet(sf::RenderWindow *wnd, float x, float y) :
		GameObject(wnd),
		sprite()
	{
		this->wnd = wnd;
		position.x = x;
		position.y = y;
		velocity.x = 0;
		velocity.y = -5;
		radius = 3;
		sprite.setRadius(radius);
		sprite.setPosition(x, y);
		sprite.setOrigin(radius, radius);
	}

	void Update(){
		if (position.y < 0){
			deleteLayer.push_back(this);
		} else {
			position += velocity;
			Draw();
		}
	}

	void Draw(){
		sprite.setPosition(position);
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
	bool fire;
	int cooldown;
public:
	Player(sf::RenderWindow *wnd) :
		GameObject(wnd),
		sprite()
	{
		this->wnd = wnd;
		up = down = left = right = false;
		fire = false;
		radius = 5;
		position.x = 400;
		position.y = 300;
		velocity.x = 0;
		velocity.y = 0;
		speed = 3;
		cooldown = 0;
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

		if (cooldown > 0){
			cooldown--;
		}else if (fire){
			gameObjects.push_back(new Bullet(wnd, position.x, position.y));
			cooldown = 10;
		}
		float sqlen = velocity.x*velocity.x + velocity.y*velocity.y;
		
		if (sqlen != 0){
			sqlen = sqrt(sqlen);
			position += velocity/sqlen * speed;
			if (position.x < 0)
				position.x = 0;
			if (position.x > 800)
				position.x = 800;
			if (position.y < 0)
				position.y = 0;
			if (position.y > 600)
				position.y = 600;
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

	void SetFire(bool status){
		fire = status;
	}
};

class Game{
private:
	sf::RenderWindow wnd;
	sf::Event event;
	
	Player player;
	float enemyCountdown;
public:
	Game() :
		wnd(sf::VideoMode(800,600), "GAME"),
		player(&wnd)
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
			case sf::Keyboard::Z:
				player.SetFire(true);
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
			case sf::Keyboard::Z:
				player.SetFire(false);
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
		if (enemyCountdown < 0){
			gameObjects.push_back(new Enemy(&wnd, rand()%800));
			enemyCountdown = 50;
		}
		enemyCountdown--;

		for (std::list<GameObject*>::iterator it=gameObjects.begin();
			it != gameObjects.end(); it++){
			(*it)->Update();
		}

		while(!deleteLayer.empty()){
			gameObjects.remove(deleteLayer.front());
			delete deleteLayer.front();
			deleteLayer.pop_front();
		}

		wnd.display();
	}
};


int main(){
	Game game;
	game.Run();

	return 0;
}
