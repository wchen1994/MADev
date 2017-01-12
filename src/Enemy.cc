#include "Enemy.hpp"

Enemy::Enemy(sf::RenderWindow *wnd, float x, float y=0) :
	GameObject(wnd),
	sprite()
{
	this->wnd = wnd;
	position.x = x;
	position.y = y;
	velocity.x = 0;
	velocity.y = 2;
	radius = 10;
	sprite.setRadius(radius);
	sprite.setPosition(position);
	sprite.setOrigin(radius, radius);
	drawing = &sprite;
}

void Enemy::Update(){
	position += velocity;

	if (position.x < 0 || position.x > 800 || position.y > 600){
		GameObject::layerDelete.push_back(this);	
	}

	sprite.setPosition(position);
}
