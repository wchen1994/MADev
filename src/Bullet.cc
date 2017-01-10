#include "Bullet.hpp"

Bullet::Bullet(sf::RenderWindow *wnd, float x, float y) :
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
	drawing = &sprite;
}

void Bullet::Update(){
	if (position.y < 0){
		layerDelete.push_back(this);
	} else {
		position += velocity;
		Draw();
	}
	sprite.setPosition(position);
}
