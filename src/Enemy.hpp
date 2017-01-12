#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "GameObject.hpp"

class Enemy : public GameObject{
private:
	sf::RenderWindow *wnd;
	sf::CircleShape sprite;
	sf::Vector2<float> velocity;
	float radius;
public:
	Enemy(sf::RenderWindow *wnd, float x, float y);
	void Update();
};

#endif
