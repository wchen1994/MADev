#ifndef __BULLET_H_
#define __HULLET_H_

#include "GameObject.hpp"

class Bullet : public GameObject{
private:
	sf::RenderWindow *wnd;
	sf::CircleShape sprite;
	sf::Vector2<float> velocity;
	float radius;
public:
	Bullet(sf::RenderWindow *wnd, float x, float y);
	void Update();
};

#endif
