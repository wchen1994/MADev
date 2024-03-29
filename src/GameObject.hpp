#ifndef __GAMEOBJECT_H_
#define __GAMEOBJECT_H_

#include <SFML/Graphics.hpp>
#include <list>
#include <set>
#include <iostream>
#include <string>

class GameObject{
protected:
	sf::Vector2<float> position;
	sf::RenderWindow *wnd;
	sf::Drawable *drawing;
	float colliderSize;
public:
	GameObject(sf::RenderWindow *wnd);
	sf::Vector2<float> getPosition(){ return position; }
	float getSize(){ return colliderSize; }
	virtual ~GameObject();
	virtual void Draw();
	virtual void Update();
	virtual void OnKeyPressed(sf::Event::KeyEvent key);
	virtual void OnKeyReleased(sf::Event::KeyEvent key);
	virtual void OnCollisionEnter(GameObject *other);
	virtual std::string GetType() { return ""; }
	static std::set<GameObject*> layerDefault;
	static std::set<GameObject*> layerDelete;
};


#endif
