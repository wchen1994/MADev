#ifndef __GAMEOBJECT_H_
#define __GAMEOBJECT_H_

#include <SFML/Graphics.hpp>

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
};

#endif
