#include"GameObject.hpp"

std::list<GameObject*> GameObject::layerDefault;
std::list<GameObject*> GameObject::layerDelete;

GameObject::GameObject(sf::RenderWindow *wnd) :
	position(0,0)
{
	this->wnd = wnd;
	drawing = NULL;
}

GameObject::~GameObject(){
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

void GameObject::OnCollisionEnter(GameObject *other){
}
