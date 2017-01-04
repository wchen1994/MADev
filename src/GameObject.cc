#include"GameObject.hpp"

GameObject::GameObject(sf::RenderWindow *wnd) :
	position(0,0)
{
	this->wnd = wnd;
	drawing = NULL;
}

GameObject::~GameObject(){
	if (drawing){
		delete drawing;
	}
};

void GameObject::Draw(){
	if (drawing){
		wnd->draw(*drawing);
	}
}

void GameObject::Update(){
	Draw();
}
