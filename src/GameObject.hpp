#ifndef __GAMEOBJECT_H_
#define __GAMEOBJECT_H_

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

class GameObject{
protected:
	sf::Vector2<float> position;
	sf::RenderWindow *wnd;
	sf::Drawable *drawing;
public:
	GameObject(sf::RenderWindow *wnd);
	virtual ~GameObject();
	virtual void Draw();
	virtual void Update();
	virtual void OnKeyPressed(sf::Event::KeyEvent key);
	virtual void OnKeyReleased(sf::Event::KeyEvent key);
	static std::list<GameObject*> layerDefault;
	static std::list<GameObject*> layerDelete;
};


#endif
