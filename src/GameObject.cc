#include"GameObject.hpp"

GameObject::GameObject(sf::RenderWindow *wnd) :
	position(0,0),
	velocity(0,0)
{
	this->wnd = wnd;
}

GameObject::~GameObject(){};

void GameObject::Draw(){
}

void GameObject::Update(){
	position += velocity;
	Draw();
}
