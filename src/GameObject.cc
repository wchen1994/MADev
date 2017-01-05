#include"GameObject.hpp"

GameObject::GameObject(sf::RenderWindow *wnd) :
	position(0,0)
{
	this->wnd = wnd;
	drawing = NULL;
}

GameObject::~GameObject(){
//	if (drawing){ // drawing should be class member can not delete
//		delete drawing;
//	}
};

void GameObject::Draw(){
	if (drawing){
		wnd->draw(*drawing);
	}
}

void GameObject::Update(){
}

void GameObject::OnKeyPressed(sf::Event::KeyEvent key){
}

void GameObject::OnKeyReleased(sf::Event::KeyEvent key){
}
